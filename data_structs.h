#define UUID_SIZE 25 	// length might change if custom generator is made
#define NAME_SIZE 32
#define LANG_SIZE 32
#define CODE_SIZE 512

typedef struct { 
	//char uuid[UUID_SIZE];
	char name[NAME_SIZE];	
	char language[LANG_SIZE];	
	char code[CODE_SIZE];
	

} entry;


typedef struct {
	FILE *fd;
	int entry_num;
	void *buf;


} database;

