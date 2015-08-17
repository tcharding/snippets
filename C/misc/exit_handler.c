#include "tch.h"

static void our_exit1(void);
static void our_exit2(void);

int main(void)
{
	if (atexit(our_exit2) != 0)
		err_sys("cannot register my_exit2");

	if (atexit(our_exit1) != 0)
		err_sys("cannot register my_exit1");
	if (atexit(our_exit1) != 0)
		err_sys("cannot register my_exit1");
	
	printf("main is done\n");
	return(0);
}
static void our_exit1(void)
{
	printf("first exit handler\n");
}

static void our_exit2(void)
{
	printf("second exit handler\n");	
}
