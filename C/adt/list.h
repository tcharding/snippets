/* attribution: UNIX Systems Programming - Robbins and Robbins */
#include <time.h>

typedef struct data_struct {
	time_t time;
	char *s;
} data_t;

int accessdata(void);
int adddata(data_t data);
int freekey(int key);
int getdata(int key, data_t *datap);
