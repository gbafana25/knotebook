#define UUID_SIZE 25 	// length might change if custom generator is made

typedef struct { 
	unsigned long id;	// increments by one
	//char uuid[UUID_SIZE];
	char *name;	
	char *language;	
	

} entry;


typedef struct {
	FILE *fd;
	int size;
	void *buf;


} database;
