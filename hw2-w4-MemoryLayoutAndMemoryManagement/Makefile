CC = gcc
CFLAGS = -Wall -Wextra -g

all: allocmem loadmem

allocmem: allocmem.c
	$(CC) $(CFLAGS) -o allocmem allocmem.c

loadmem: loadmem.c
	$(CC) $(CFLAGS) -o loadmem loadmem.c

clean:
	rm -f allocmem loadmem  
