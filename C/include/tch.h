/*
 * Our own header, to be included before all standard system headers.
 */
#ifndef	_TCH_H			/* Tobin C Harding */
#define	_TCH_H

#define _POSIX_C_SOURCE 200809L
/*
 * This header was created based on ideas, functions, and principles
 * garnered while studying the following texts;
 *
 * * Advanced Programming in the UNIX Environment 
 * *  - Stevens and Rago, 3rd Edition
 *
 * * UNIX SYSTEMS Programming
 * *  - Robbins and Robbins
 */
#include <stdio.h>		/* for convenience */
#include <stdlib.h>		/* for convenience */
#include <string.h>		/* for convenience */
#include <unistd.h>		/* for convenience */
#include <signal.h>		/* for SIG_ERR */
#include <sys/types.h>		/* some systems still require this */
#include <sys/stat.h>

#define	MAXLINE	4096			/* max line length */

/*
 * Default file access permissions for new files.
 */
#define	FILE_MODE	(S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

/*
 * Default permissions for new directories.
 */
#define	DIR_MODE	(FILE_MODE | S_IXUSR | S_IXGRP | S_IXOTH)

typedef	void	Sigfunc(int);	/* for signal handlers */

#define	min(a,b)	((a) < (b) ? (a) : (b))
#define	max(a,b)	((a) > (b) ? (a) : (b))

/*
 * Memory Streams
 */
struct mems {			
	FILE *stream;
	char *buf;
	size_t size;
};
int m_open_memstream(struct mems *m);
int m_insert(struct mems *m, char *fmt, ...);

/* Define bzero() as macro. Stevens, Fenner, Rudoff [2004] */
#define bzero(ptr, n) memset(ptr, 0, (size_t)(n))

/*
 * Prototypes for library routines. Stevens and Rago [2013]
 */
char	*path_alloc(size_t *);				
long	 open_max(void);				

void	err_msg(const char *, ...); /* error routines */
void	err_dump(const char *, ...) __attribute__((noreturn));
void	err_quit(const char *, ...) __attribute__((noreturn));
void	err_cont(int, const char *, ...);
void	err_exit(int, const char *, ...) __attribute__((noreturn));
void	err_ret(const char *, ...);
void	err_sys(const char *, ...) __attribute__((noreturn));

/*
 * Restart library routines. Robins and Robins [2003]
 */
#ifndef ETIME
#define ETIME ETIMEDOUT
#endif

int r_close(int fd);
int r_dup2(int fd, int fd2);
/* int r_open2(const char *path, int oflag); */
/* int r_open3(const char *path, int oflag, mode_t mode); */
int r_open(char *path, int oflag, ...);
ssize_t r_read(int fd, void *buf, size_t count);
pid_t r_wait(int *stat_loc);
pid_t r_waitpid(pid_t pid, int *stat_loc, int options);
ssize_t r_write(int fd, void *buf, size_t count);

#endif	/* _TCH_H */
