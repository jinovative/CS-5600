CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lpthread

all: multithread shared_multithread pqueuepmain 

multithread: multithread.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

shared_multirhread: shared_multithread.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

pqueuepmain: pqueuepmain.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f multithread shared_multithread pqueuepmain 

