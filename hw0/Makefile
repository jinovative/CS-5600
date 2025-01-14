CC = gcc
CFLAGS = -Wall -Wextra -g

all: learnc arger

learnc: learnc.c mpg2km.c
	$(CC) $(CFLAGS) -o learnc learnc.c mpg2km.c

arger: arger.c
	$(CC) $(CFLAGS) -o arger arger.c

clean:
	rm -f learnc arger
