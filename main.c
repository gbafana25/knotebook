#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stddef.h>
#include <string.h>
#include <netdb.h>
#include <stdlib.h>
#include <sys/poll.h>
#include <sys/ioctl.h>

#include "db.h"
#include "parser.h"
#include "server_setup.h"

#define PORT 1234
#define MAX_CLIENTS 10

void load_home_page(int cli) {
	char *msg = "Temp. home page\n";
	send(cli, msg, strlen(msg), 0);
	close(cli);

}


int main() {

	char home_req[] = "GET /home";
	char add_prog[] = "POST /create";

	int sock_opt = 1;
	nfds_t client_num = MAX_CLIENTS + 1; 	// first index is server 
	struct sockaddr_in serv_addr;
	memset(&serv_addr, 0, sizeof(serv_addr));
	
	serv_addr = setup_sockstruct();
	int serv = setup_socket(serv_addr);
	int num = 1;
	
	char buffer[1024];
	memset(&buffer, 0, sizeof(buffer));
	struct pollfd client_array[client_num];

	
	if(bind(serv, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {

		perror("Couldn't bind socket\n");
		return -1;
	}
	
	if(listen(serv, 4)) {
		perror("Couldn't listen on server socket\n");
		return -1;
	}

	memset(&client_array, 0, sizeof(client_array));
	client_array[0].fd = serv;
	client_array[0].events = POLLIN;

	while(1) {
		poll(client_array, client_num, -1);
		for(int i = 0; i < client_num; i++) {
			if(client_array[i].revents&POLLIN) {
				if(client_array[i].fd == serv) {
					printf("got connection\n");
					struct sockaddr_in client_addr;
					int client = accept(serv, NULL, NULL);
					client_array[num].fd = client;
					client_array[num].events = POLLIN;	
					num++;
				} else {
					recv(client_array[i].fd, buffer, sizeof(buffer), 0);
					//printf("%s", buffer);	
					if(strncmp(buffer, home_req, strlen(home_req)) == 0) {
						load_home_page(client_array[i].fd);

					} else if(strncmp(buffer, add_prog, strlen(add_prog)) == 0) {
						entry e;
						parse_request(buffer, e);
					
					}
					memset(&buffer, 0, sizeof(buffer));
					close(client_array[i].fd);
				}
			}

		}

	}

}
