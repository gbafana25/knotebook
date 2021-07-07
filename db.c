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

void init_db(database db) {
	db.size = MAX_ENTRIES;
	db.buf = malloc(sizeof(entry) * db.size);
		


}


