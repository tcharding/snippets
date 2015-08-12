CC = gcc
CFLAG = -Wall -pedantic -std=c99 
LFLAG = -L../lib -ltch
INC = -I../include	
EXES = tst-data_t tst-stack

.PHONY: all clean

all: $(EXES)

tst-stack: tst-stack.o stack.o data_t.o
	$(CC) -o $@ tst-stack.o stack.o data_t.o $(LFLAG)	

tst-data_t: tst-data_t.o data_t.o
	$(CC) -o $@ tst-data_t.o data_t.o $(LFLAG)

%.o: %.c
	$(CC) $(CFLAG) -c $< $(INC)

clean:
	@for f in *.o $(EXES); do \
	if [ -f $$f ]; then \
	rm "$$f"; \
	echo "rm $$f" ; \
	fi; done

