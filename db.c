#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data_structs.h"

#define MAX_ENTRIES 8
#define DB_FILE "code.db"

void write_db(database db, entry en) {
	db.fd = fopen(DB_FILE, "ab+");	
	fwrite((void *) &en, sizeof(entry), 1, db.fd);

} 

void init_db() {
	database db;
	db.size = MAX_ENTRIES;
	db.buf = malloc(sizeof(entry) * db.size);
		


}


char *get_name(char *buf) {
	int size = 0;
	while(buf[size] != '#') {
		size++;

	}
	char *var = malloc(sizeof(char) * size);
	strncpy(var, buf, size);
	return var;	

} 

void parse_input(char *buf, entry e) {
	memset(&e.name, 0, sizeof(e.name));
	memset(&e.language, 0, sizeof(e.language));
	int el_num = 0;
	for(int i = 0; i < strlen(buf); i++) {
		if(&buf[i] == '#') {
			char *s = get_name(buf); 
			if(el_num == 0) {
				e.name = s;
				el_num++;
			} else if(el_num == 1) {
				e.language = s;
				el_num++;
			}	
		}

	}


} 
