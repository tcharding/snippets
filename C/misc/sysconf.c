#include <stdio.h>
#include <unistd.h>
#include <limits.h>

#ifndef LINE_MAX
#define LINE_MAX 1024
#endif

/* play with system configuration values */
int main(void)
{
	long line_max;

	line_max = sysconf(_SC_LINE_MAX);
	printf("line_max: %ld\tLINE_MAX: %d\n", line_max, LINE_MAX);
	return 0;
}
