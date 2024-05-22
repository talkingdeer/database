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
#include <thread>
#include <semaphore>
#include <signal.h>
#include <pthread.h>

using namespace std;

#define SERVER_PORT 5555
#define SERVER_NAME "127.0.0.1"
#define BUFLEN 512
#define CLIENT_COUNT 4

string commands[5] = {"Find rating > 0.5 && < rating 0.7", "Print", "Find date 01.09.1939", "Generate 20", "Add Степанов Геннадий Русланович 08.01.2001 Украина 0 0.337255"};


void writeToServer(int fd){
    const char* buf = commands[rand() % 5].c_str();
    write(fd, buf, strlen(buf) + 1);
}

void readFromServer(int fd){
    char buf[BUFLEN];
    int nbytes;
    nbytes = read(fd, buf, BUFLEN);
	buf[nbytes] = '\0';
	while(strchr(buf, '%') == NULL){
		cout << buf;
		nbytes = read(fd, buf, BUFLEN);
		buf[nbytes] = '\0';
	}
	buf[nbytes - 1] = '\0';
    std::cout << buf;
}

void* client_process(void* arg){
	int err;
	int sock;
	struct sockaddr_in server_addr;
	struct hostent *hostinfo;

	hostinfo = gethostbyname(SERVER_NAME);
	if (hostinfo == NULL) {
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
	while(1){
		writeToServer(sock);
		readFromServer(sock);
		sleep(1);
	}
	close(sock);
}


int main(void)
{
	int i;
	pthread_t clients[CLIENT_COUNT];
	for(i = 0; i < CLIENT_COUNT; i++){
		pthread_create(&clients[i], NULL, client_process, (void*)&i);
	}
	for(i = 0; i < CLIENT_COUNT; i++)
		pthread_join(clients[i], NULL);
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