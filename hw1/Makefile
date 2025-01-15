CC = gcc
CFLAGS = -Wall -Wextra -g

all: genrand cipher

genrand: genrand.c
	$(CC) $(CFLAGS) -o genrand genrand.c

cipher: cipher.c polybius.c
	$(CC) $(CFLAGS) -o cipher cipher.c polybius.c

clean:
	rm -f genrand cipher

