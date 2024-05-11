#include "class.h"

#define PORT 5555
#define BUFLEN 512


int  main (void)
{
	cout << "Server started\n";
	list<Person> base;
	fstream f;
	load(f, base);
    int i, err, opt=1;
    int sock, new_sock;
    fd_set active_set, read_set;
    struct sockaddr_in  addr;
    struct sockaddr_in  client;
    char buf[BUFLEN];
    socklen_t size;

    sock = socket (PF_INET, SOCK_STREAM, 0);
    if ( sock<0 ) {
        perror ("Server: cannot create socket");
        exit (EXIT_FAILURE);
    }
    setsockopt(sock,SOL_SOCKET,SO_REUSEADDR, (char*)&opt, sizeof(opt));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    err = bind(sock, (struct sockaddr*)&addr, sizeof(addr));
    if ( err<0 ) {
        perror ("Server: cannot bind socket");
        exit (EXIT_FAILURE);
    }

    err = listen(sock,3);
    if ( err<0 ) {
        perror ("Server: listen queue failure");
        exit(EXIT_FAILURE);
    }
	
    FD_ZERO(&active_set);
    FD_SET(sock, &active_set);

    while (1) {
        read_set = active_set;
        if (select(FD_SETSIZE, &read_set, NULL, NULL, NULL) < 0) {
            perror("Server: select failure");
            exit (EXIT_FAILURE);
        }

        for (i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET(i, &read_set)) {
                if (i == sock) {
                    size = sizeof(client);
                    new_sock = accept(sock, (struct sockaddr*)&client, &size);
                    if (new_sock < 0) {
                        perror("accept");
                        exit (EXIT_FAILURE);
                    }
                    fprintf (stdout, "Server: connect from host %s, port %hu.\n",
                            inet_ntoa(client.sin_addr),
                            ntohs(client.sin_port));
                    FD_SET(new_sock, &active_set);
                } else {
                    err = readFromClient(i, buf);
                    if (err < 0) {
                        close (i);
                        FD_CLR(i, &active_set);
                    } else {
                        if (strstr(buf, "stop")) {
                            close(i);
                            FD_CLR (i, &active_set);
                        } else {
							execute(i, buf, base, f);
                        }
                    }
                }
            }
        }
    }
}

int readFromClient(int fd, char *buf)
{
    int nbytes;
    nbytes = read(fd, buf, BUFLEN);
    if (nbytes < 0) {
        perror ("Server: read failure");
        return -1;
    } else if (nbytes == 0) {
        return -1;
    } else {
		cout << "Received from client " << fd << ": " << buf << "\n";
        return 0;
    }
}

void writeToClient(int fd, const char *buf)
{
    int nbytes;
    nbytes = write(fd, buf, strlen(buf));
    if (nbytes < 0) {
        perror ("Server: failed to write");
    }
}