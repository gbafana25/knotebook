#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data_structs.h"

#define MAX_ENTRIES 18
#define DB_FILE "code.db"

void write_db(database db, entry *en) {
	db.fd = fopen(DB_FILE, "ab+");
	fwrite(en, sizeof(entry), 1, db.fd);
	fclose(db.fd);

} 

void read_db(database db) {
	entry in;
	db.fd = fopen(DB_FILE, "rb");
	while(fread(&in, sizeof(entry), 1, db.fd)) {
		printf("%s\n", in.name);	
		printf("%s\n", in.language);
		printf("%s\n", in.code);
	}
	fclose(db.fd);

}

void init_db(database db) {
	db.entry_num = MAX_ENTRIES;
		
}

