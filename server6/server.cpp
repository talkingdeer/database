#include "class.h"

#define PORT 1488
#define BUFLEN 4096

list<Person> base;
fstream f;

char from_hex(char ch) {
    return isdigit(ch) ? ch - '0' : tolower(ch) - 'a' + 10;
}

string url_decode(string text) {
    char h;
    ostringstream escaped;
    escaped.fill('0');

    for (auto i = text.begin(), n = text.end(); i != n; ++i) {
        string::value_type c = (*i);

        if (c == '%') {
            if (i[1] && i[2]) {
                h = from_hex(i[1]) << 4 | from_hex(i[2]);
                escaped << h;
                i += 2;
            }
        } else if (c == '+') {
            escaped << ' ';
        } else {
            escaped << c;
        }
    }
    return escaped.str();
}

string fix(string request){
	for(auto it = request.begin(); it != request.end(); ++it){
		if(*it == '+') *it = ' ';
	}
	return request;
}

int  main(void)
{
	load(f, base);
    int i, err, opt = 1;
    int sock, new_sock;
    fd_set active_set, read_set;  
    struct sockaddr_in addr;
    struct sockaddr_in client;
    char buf[BUFLEN];
    socklen_t  size;

    printf("HTTP server started\n");

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock<0) {
        perror("Server: cannot create socket");
        exit(EXIT_FAILURE);
    }
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char*)&opt, sizeof(opt));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    err = bind(sock, (struct sockaddr*)&addr, sizeof(addr));
    if (err<0) {
        perror("Server: cannot bind socket");
        exit(EXIT_FAILURE);
    }

    err = listen(sock, 3);
    if (err<0) {
        perror("Server: listen queue failure");
        exit(EXIT_FAILURE);
    }

    FD_ZERO(&active_set);
	FD_ZERO(&read_set);
    FD_SET(sock, &active_set);

    while (1) {
        read_set = active_set;
        if ( select(FD_SETSIZE, &read_set, NULL, NULL, NULL) < 0) {
            perror("Server: select  failure");
            exit(EXIT_FAILURE);
        }
        for (i = 0; i<FD_SETSIZE; i++) {
            if (FD_ISSET(i, &read_set)) {
                if (i == sock) {
                    size = sizeof(client);
                    new_sock = accept(sock, (struct sockaddr*)&client, &size);
                    if (new_sock<0) {
                        perror("accept");
                        exit(EXIT_FAILURE);
                    }
                    fprintf(stdout, "Server: connect from host %s, port %hu.\n",
                        inet_ntoa(client.sin_addr),
                        ntohs(client.sin_port));
                    FD_SET(new_sock, &active_set);
                    fprintf(stdout, "New socket = %d\n", new_sock);
                }
                else {
                    err = readFromClientHTTP(i, buf);
                    if (err<0) {
                        close(i);
                        fprintf(stdout, "Socket %d closed\n", i);
                    } else  {
                        writeToClientHTTP(i, buf);
                    }
                    FD_CLR(i, &active_set);
                }
            }
        }
    }
}

int  readFromClientHTTP(int fd, char *buf)
{
    int  nbytes;
    nbytes = recv(fd, buf, BUFLEN, 0);
    fprintf(stdout, "Reading %d bytes from socket %d\n", nbytes, fd);
    if (nbytes < 0) {
        return -1;
    } else {
        printf("Server gets %d bytes:\n", nbytes);
        buf[min(nbytes, BUFLEN - 1)] = 0;
        cout << "\n" << buf <<"\n";
        return nbytes;
    }
}

void ProcessHTML(stringstream &html, string request)
{
	html << "<!DOCTYPE html>\r\n";
    html << "<html><head><meta charset = \"utf-8\">\r\n";
    html << "<title>Migration service database</title></head>\r\n";
    html << "<body>\r\n";
    html << "<h2>Migration service database</h2>\r\n";
	html << "<form action=\"http://localhost:1488\" method=\"post\">\n";
	html << "<input name=\"sub\" type=\"submit\" value=\"Send\" style=\"font-size: 20px;\">\n";
	html << "<input name=\"request\" placeholder=\"Enter your command\" style=\"width: 700px; height: 25px; font-size: 20px;\">\n";
	html << "<br>\n";
	html << "<p style=\"font-size: 20px;\">" << request << "</p>\n";
	html << "</form>\n";
    html << "</body></html>\r\n";
}


void  writeToClientHTTP(int fd, char *buf)
{
	bool request_type = 0;
    int  nbytes;
    stringstream head; 
    stringstream html;
    string request = "";

    if (strstr(buf, "GET")) {
        request = "request=";
        printf("GET request: %s\n", request.c_str());
    }
    if (strstr(buf, "POST")) {
        char *p1 = strstr(buf, "\r\n\r\n");
        request = (p1 + 4);
        printf("POST request: %s\n", request.c_str());
		request_type = 1;
    }

    if (request != "/" && request.find("request") == string::npos)  {
        head << "HTTP/1.1 404 Not found\r\n";
        head << "Connection: close\r\n";
        head << "Content-length: 0\r\n";
        head << "\r\n";
        nbytes = send(fd, head.str().c_str(), head.str().length() + 1, 0);
        return;
    }
	if(request_type){
		size_t pos = request.find("request=");
		string out_request = request.substr(pos + 8);
		out_request = url_decode(out_request);
		cout << out_request << endl;
		ProcessHTML(html, execute(fd, out_request.data(), base, f));
	} else {
		ProcessHTML(html, "");
	}
	int html_length = html.str().length();
    head << "HTTP/1.1 200 OK\r\n";
    head << "Connection: keep-alive\r\n";
    head << "Content-type: text/html\r\n";
    head << "Content-length: " << html_length << "\r\n";
    head << "\r\n";

    nbytes = send(fd, head.str().c_str(), head.str().length() + 1, 0);
    printf("http nb = %d\n", nbytes);
    nbytes = send(fd, html.str().c_str(), html.str().length() + 1, 0);
    printf("html nb = %d\n", nbytes);

    if (nbytes<0) {
        perror("Server: write failure");
    }
}