#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void get_value(char *s, int pos) {
	pos += 5;
	//int start = pos;
	int len = pos;
	while(s[len] != '&') {
		//curr++;
		//printf("%c\n", s[len]);
		len++;
	}
	char *val = malloc(sizeof(char) * len);
	strncpy(val, s+pos, len);
	printf("%s\n", val);

}

void parse_request(char *req) {
	for(int i = 0; i < strlen(req); i++) {
		if(strncmp(&req[i], "name=", 5) == 0) {
			printf("found name\n");
			//printf("%c\n", req[i+5]);
			get_value(req, i);
		} else if(strncmp(&req[i], "lang=", 5) == 0) {
			printf("found language\n");
		}
	}

}
