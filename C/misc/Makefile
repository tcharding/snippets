CC = gcc
CFLAG = -Wall -pedantic -std=c99 
LFLAG = -L../lib -ltch
INC = -I../include 
EXES = limits exit_handler

all: $(EXES)

limits: limits.o
	$(CC) -o $@ limits.o $(LFLAG)

exit_handler: exit_handler.o
	$(CC) -o $@ exit_handler.o $(LFLAG)

%.o: %.c
	$(CC) $(CFLAG) -c $< $(INC)

clean:
	@for f in *.o $(EXES); do \
	if [ -f $$f ]; then \
	rm "$$f"; \
	echo "rm $$f" ; \
	fi; done

