#include ...

/*
 * Pseudo Code Exponential Backoff Algorithm
 */

#define MAXSLEEP 128		/* maximum total time algorithm will sleep */

int retry()
{
	int numsec;

	for (numsec = 1; numsec <= MAXSLEEP; numsec <<= 1) {
		/*
		 * Code to execute
		 *  return 0 if successful 
		 */

		/*
		 * Delay (backoff)
		 */
		if (numsec <= MAXSLEEP / 2) /* / 2 so MAXSLEEP is total sleep time */
			sleep(numsec);
	}
	return -1;
}
