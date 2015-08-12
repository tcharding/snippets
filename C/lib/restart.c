/* attribution: UNIX Systems Programming - Robbins and Robbins */
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <string.h>
#include <stdarg.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "tch.h"		/* restart prototypes */
#define BLKSIZE PIPE_BUF
#define MILLION 1000000L
#define D_MILLION 1000000.0

/* Private functions */

/*
static int gettimeout(struct timeval end, struct timeval *timeoutp)
{
	gettimeofday(timeoutp, NULL);
	timeoutp->tv_sec = end.tv_sec - timeoutp->tv_sec;
	timeoutp->tv_usec = end.tv_usec - timeoutp->tv_usec;
	if (timeoutp->tv_usec >= MILLION) {
		timeoutp->tv_sec++;
		timeoutp->tv_usec -= MILLION;
	}
	if (timeoutp->tv_usec < 0) {
		timeoutp->tv_sec--;
		timeoutp->tv_usec += MILLION;
	}
	if ((timeoutp->tv_sec < 0) ||
	    ((timeoutp->tv_sec == 0) && (timeoutp->tv_usec == 0))) {
		errno = ETIME;
		return -1;
	}
	return 0;
}
*/

/* Restart versions of traditional functions */

int r_close(int fd)
{
	int retval;
	
	while (retval = close(fd), retval == -1 && errno == EINTR)
		;
	return retval;
}
int r_dup2(int fd, int fd2)
{
	int retval;
	
	while (retval = dup2(fd, fd2), retval == -1 && errno == EINTR)
		;
	return retval;
}

int r_open(char *path, int oflag, ...)
{
	va_list ap;
	int retval;
	
	va_start(ap, oflag);
	while ((retval = open(path, oflag, ap)) == -1 && errno == EINTR)
		;
	va_end(ap);
	return retval;
}
/*
int r_open2(const char *path, int oflag)
{
	int retval;
	
	while (retval = open2(path, oflag), retval == -1 && errno == EINTR)
		;
	return retval;
}
int r_open3(const char *path, int oflag, mode_t mode)
{
	int retval;
	
	while (retval = open3(path, oflag, mode), retval == -1 && errno == EINTR)
		;
	return retval;
}
*/
ssize_t r_read(int fd, void *buf, size_t count)
{
       	int retval;
	
	while (retval = read(fd, buf, count), retval == -1 && errno == EINTR)
		;
	return retval;
}	
pid_t r_wait(int *stat_loc)
{
	int retval;

	while (((retval = wait(stat_loc)) == -1) && (errno == EINTR))
		;
	return retval;
}

pid_t r_waitpid(pid_t pid, int *stat_loc, int options)
{
	int retval;

	while (((retval = waitpid(pid, stat_loc, options)) == -1) && (errno == EINTR))
		;
	return retval;
}
ssize_t r_write(int fd, void *buf, size_t count)
{
	int retval;

	while (((retval = write(fd, buf, count)) == -1) && (errno == EINTR))
		;
	return retval;
}
