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



int main() {

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
	
	start_socket(serv, serv_addr);

	memset(&client_array, 0, sizeof(client_array));
	client_array[0].fd = serv;
	client_array[0].events = POLLIN;

	while(1) {
		database store;
		init_db(store);
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
					if(strncmp(buffer, add_prog, strlen(add_prog)) == 0) {
						entry *e = parse_request(buffer);
						write_db(store, e);
						read_db(store);
						//free(&store.buf);
					
					}
					memset(&buffer, 0, sizeof(buffer));
					close(client_array[i].fd);
				}
			}

		}

	}
	

}
