#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/ioctl.h>

#define PORT 1234

int setup_socket(struct sockaddr_in addr) {
	int opt = 1;
	int serv = socket(AF_INET, SOCK_STREAM, 0);
	if(serv == -1) {
		perror("Couldn't open socket\n");
		return -1;
	}

	setsockopt(serv, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));
	ioctl(serv, FIONBIO, &opt);

	return serv;

}

struct sockaddr_in setup_sockstruct() {
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	return addr;
}

int start_socket(int server, struct sockaddr_in addr) {

	if(bind(server, (struct sockaddr *) &addr, sizeof(addr)) == -1) {

		perror("Couldn't bind socket\n");
		return -1;
	}
	
	if(listen(server, 4)) {
		perror("Couldn't listen on server socket\n");
		return -1;
	}

	return 0;


}

