#define UUID_SIZE 25 	// length might change if custom generator is made

typedef struct { 
	//char uuid[UUID_SIZE];
	char *name;	
	char *language;	
	char *code;
	

} entry;


typedef struct {
	FILE *fd;
	int size;
	void *buf;


} database;
