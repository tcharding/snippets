#include "tch.h"
#include "data_t.h"
#include "stack.h"
#define NUM 10

/* test stack */
int main(void)
{
	char buf[MAXLINE];
	data_t *p;
	int i;
	
	for (i = 0; i < NUM; i++) {
		snprintf(buf, MAXLINE, "loop dt :%d", i);
		fprintf(stderr, "buf: %s\n", buf);
		if ((p = dt_creat(buf)) == NULL)
			err_quit("dt_creat failed");
		st_push(p);
		dt_free(p);
	}

	while ((p = st_pop()) != NULL) {
		dt_dump(p, stdout);
		dt_free(p);
	}
	
	dt_dump(p, stdout);
	fprintf(stdout, "\n");
	dt_free(p);
	
}
