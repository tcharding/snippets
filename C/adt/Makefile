CC = gcc
CFLAG = -Wall -pedantic -std=c99  -D_GNU_SOURCE -g
LFLAG = -L../lib -ltch
INC = -I../include	
EXES = tst-data tst-vector tst-stack

.PHONY: all clean

all: $(EXES)

tst-stack: tst-stack.o stack.o data_t.o
	$(CC) -o $@ tst-stack.o stack.o data_t.o $(LFLAG)	

tst-data: tst-data.o data.o string.o
	$(CC) -o $@ tst-data.o data.o string.o $(LFLAG)

tst-vector: tst-vector.o vector.o data.o string.o
	$(CC) -o $@ tst-vector.o vector.o data.o string.o $(LFLAG)


%.o: %.c
	$(CC) $(CFLAG) -c $< $(INC)

clean:
	@for f in *.o $(EXES); do \
	if [ -f $$f ]; then \
	rm "$$f"; \
	echo "rm $$f" ; \
	fi; done

