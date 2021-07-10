#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data_structs.h"

#define MAX_ENTRIES 18
#define DB_FILE "code.db"

void write_db(database db, entry *en) {
	fwrite((void *) &en, sizeof(en), 1, db.fd);

} 

void init_db(database db) {
	//db.fd = fopen(DB_FILE, "ab+");	
	db.entry_num = MAX_ENTRIES;
	db.buf = malloc(sizeof(entry) * db.entry_num);
		


}

