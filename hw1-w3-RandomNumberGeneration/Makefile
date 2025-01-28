#
# Makefile
#
# JinYoung Park / CS5600 / Northeastern University
# Spring 2025 / Jan 15, 2025
#


all: genrand cipher

genrand: genrand.c
	gcc -Wall -Wextra -g -o genrand genrand.c

cipher: cipher.c polybius.c
	gcc -Wall -Wextra -g -o cipher cipher.c polybius.c

clean:
	rm -f genrand cipher

