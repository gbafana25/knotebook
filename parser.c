#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "data_structs.h"

char *get_value(char *s, int pos, bool is_code) {
	pos += 5;
	int len = 0;
	for(int i = pos; i < strlen(s) - 1; i++) {
		if(strncmp(&s[i], "&", 1) == 0) {
			if(is_code == false) {
				break;
			}
		} else {
			len++;
		}
	}
	char *val = malloc(sizeof(char) * len);
	strncpy(val, s+pos, len);
	return val;

}

entry *parse_request(char *req) {
	entry *info;
	for(int i = 0; i < strlen(req); i++) {
		if(strncmp(&req[i], "name=", 5) == 0) {
			strcpy(info->name, get_value(req, i, false));
			printf("%s\n", info->name);
		} else if(strncmp(&req[i], "lang=", 5) == 0) {
			strcpy(info->language, get_value(req, i, false));
			printf("%s\n", info->language);
		} else if(strncmp(&req[i], "code=", 5) == 0) {
			strcpy(info->code, get_value(req, i, true));	
			printf("%s\n", info->code);
		}
	}
	return info;

}
