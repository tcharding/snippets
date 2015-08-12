#include "tch.h"
#include "data_t.h"

/* test data_t */
int main(void)
{
	data_t *p;
	data_t dt = {"test data_t dt"};
	char buf[MAXLINE];

	fprintf(stderr, "Test creat/free/clone data_t: output 4 data_t objects\n");
	dt_dump(&dt, stdout);
	fprintf(stdout, "\n");

	p = dt_creat("test creat()");
	dt_dump(p, stdout);
	fprintf(stdout, "\n");
	dt_free(p);
	
	p = dt_clone(&dt);
	dt_dump(p, stdout);
	fprintf(stdout, "\n");
	dt_free(p);

	snprintf(buf, MAXLINE, "buffer creat");
	p = dt_creat(buf);
	dt_dump(p, stdout);
	fprintf(stdout, "\n");
	dt_free(p);
	
	return 0;
}
