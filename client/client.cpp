#include <stdio.h>
#include <iostream>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SERVER_PORT 5555
#define SERVER_NAME "127.0.0.1"
#define BUFLEN 512

int writeToServer (int fd, pid_t pid);
int readFromServer (int fd, pid_t pid);
const char* random_command();

std::string commands[10] = {"?", "Generate 20", "Find rating > 0.5 && < 0.7", "Print", "Find lastname Ева Браун", "Find date 01.09.1939", "Oh hi Mark", "Find rating", "Size", "KYS"};

int main(void)
{
	pid_t pid;
	pid = fork();
	pid = fork();
	pid = fork();
	srand(pid);
	int err;
	int sock;
	struct sockaddr_in server_addr;
	struct hostent *hostinfo;

	hostinfo = gethostbyname(SERVER_NAME);
	if ( hostinfo == NULL ) {
		fprintf (stderr, "Unknown host %s.\n", SERVER_NAME);
		exit (EXIT_FAILURE);
	}

	server_addr.sin_family = PF_INET;
	server_addr.sin_port = htons(SERVER_PORT);
	server_addr.sin_addr = *(struct in_addr*) hostinfo->h_addr;

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		perror ("Client: socket was not created");
		exit (EXIT_FAILURE);
	}

	err = connect (sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
	if (err < 0) {
		perror ("Client:  connect failure");
		exit (EXIT_FAILURE);
	}
	fprintf (stdout, "Connection is ready\n");

	while(1) {
		writeToServer(sock, pid);
		readFromServer(sock, pid);
		sleep(rand() % 10 + 2);
	}
	fprintf (stdout, "The end\n");

	close (sock);
	exit (EXIT_SUCCESS);
	
}

int writeToServer(int fd, pid_t pid)
{
    const char* buf = commands[rand() % 10].c_str();
    write(fd, buf, strlen(buf) + 1);
    return 0;
}

int readFromServer (int fd, pid_t pid)
{
    char buf[BUFLEN];
    int nbytes;
	std::cout << "Answer for client " << pid << ":\n";
    nbytes = read(fd, buf, BUFLEN);
	buf[nbytes] = '\0';
	
	while(strchr(buf, '%') == NULL){
		std::cout << buf;
		nbytes = read(fd, buf, BUFLEN);
		buf[nbytes] = '\0';
	}
	buf[nbytes - 1] = '\0';
    std::cout << buf;
    return 0;
}

const char* random_command(){
	return "f";
}

/*
int main(void)
{
    int err;
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *hostinfo;

    hostinfo = gethostbyname(SERVER_NAME);
    if ( hostinfo == NULL ) {
        fprintf (stderr, "Unknown host %s.\n", SERVER_NAME);
        exit (EXIT_FAILURE);
    }

    server_addr.sin_family = PF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr = *(struct in_addr*) hostinfo->h_addr;

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror ("Client: socket was not created");
        exit (EXIT_FAILURE);
    }

    err = connect (sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (err < 0) {
        perror ("Client:  connect failure");
        exit (EXIT_FAILURE);
    }
    fprintf (stdout, "Connection is ready\n");

    while(1) {
        writeToServer(sock);
        readFromServer(sock);
    }
    fprintf (stdout, "The end\n");

    close (sock);
    exit (EXIT_SUCCESS);
}

int writeToServer(int fd)
{
    int nbytes;
    char buf[BUFLEN];

    std::cout << "Send to server > ";
    if (fgets(buf, BUFLEN, stdin) == nullptr) {
        perror("fgets");
        return -1;
    }

    nbytes = write (fd, buf, strlen(buf) + 1);
    if (nbytes < 0){
        perror("write");
        return -1;
    }
    if (strstr(buf, "stop")) return -1;
    return 0;
}


int readFromServer (int fd)
{
    char buf[BUFLEN];
    int nbytes;

    nbytes = read(fd, buf, BUFLEN);
	buf[nbytes] = '\0';
	
	while(strchr(buf, '%') == NULL){
		std::cout << buf;
		nbytes = read(fd, buf, BUFLEN);
		buf[nbytes] = '\0';
	}
	buf[nbytes - 1] = '\0';
    std::cout << buf;
    return 0;
}
*/