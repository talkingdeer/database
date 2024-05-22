#include "class.h"

binary_semaphore client_signal(1);
list<Person> base;
fstream f;

pthread_t thread_tcp[100];
int threadno_tcp = 0;
int mistfd;

void sig_handler(int signo){
	if (signo == SIGINT) {
		cout << "\nExiting\n";
		close(mistfd);
		exit(1);
	}
}

int main(){
	load(f, base);
	
	sockaddr_in mistaddr;
	sockaddr_in clientaddr;
	socklen_t addrlen = sizeof(clientaddr);

	if ((mistfd = socket (AF_INET, SOCK_STREAM, 0)) == -1) {
		 std::cout << "Socket creation failed\n";
		 return 0;
	}

	std::cout << "Socket is created" << '\n';

	memset ((sockaddr*)&mistaddr, 0, sizeof (mistaddr));
	mistaddr.sin_family = AF_INET;
	mistaddr.sin_addr.s_addr = htonl (INADDR_ANY);
	mistaddr.sin_port = htons (PORT);

	if(bind(mistfd, (sockaddr*)&mistaddr, sizeof (mistaddr)) != 0) {
		std::cout << "Binding failed, exiting\n";
		return 0;
	}

	std::cout << "Successfully binded\n";

	if ((listen (mistfd, 5)) != 0){
		cout << "Server isn't listning\n";
		return 0;
	}

	signal(SIGINT, sig_handler);
	signal(SIGTSTP, sig_handler);

	cout << "Server is listening\n";
	int connfd;
	while (1){
		if ((connfd = accept(mistfd,(sockaddr*)&clientaddr, &addrlen)) < 0)
			cout << "Client connection declined\n";
		else
			cout << "Client " << connfd << " accepted\n";
		req *r = new req;
		bzero (r, sizeof (req));
		r->des = connfd;
		pthread_create (&thread_tcp [threadno_tcp++], NULL, tcp_connection, (void*)r);
		if (threadno_tcp == 100)
			threadno_tcp = 0;
	}
}

void* tcp_connection (void* arg){
	char buf[BUFLEN];
//	pthread_t thread;
	req* sock = (req*)arg;
	while (1){
		readFromClient(sock->des, buf);
		execute(sock->des, buf);
//		pthread_create(&thread, NULL, execute, arg);
//		pthread_detach(thread);
//		free(sock);
	}
}

int readFromClient(int fd, char *buf){
	int nbytes;
	nbytes = read(fd, buf, BUFLEN);
	if (nbytes < 0) {
		  perror ("Reading failure\n");
		  return -1;
	} else if (nbytes == 0) {
		  return -1;
	} else {
		cout << "Received from client " << fd << ": " << buf << "\n";
		buf[nbytes] = '\0';
		return 0;
	}
}

void writeToClient(int fd, const char *buf){
	int nbytes;
	nbytes = write(fd, buf, strlen(buf));
	if (nbytes < 0) {
		  perror("Writing failure\n");
	}
}