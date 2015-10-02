/*
 * Check file type and existence
 */


{
	struct stat sbuf;
	char *file;
/*
 * ...
 */
	if ((fd = open(file, O_RDONLY)) < 0)
		err_sys("print: can't open %s", file);
	if (fstat(fd, &sbuf) < 0)
		err_sys("print: can't stat %s", file);
	if (!S_ISREG(sbuf.st_mode))
		err_quit("print: %s must be a regular file", file);

/*
 * ...
 */
	close(fd);
}
