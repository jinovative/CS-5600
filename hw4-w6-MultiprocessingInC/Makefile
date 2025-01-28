all: genstrings loadstrings encrypt main

genstrings: genstrings.c
	 gcc -o genstrings genstrings.c

loadstrings: loadstrings.c queue.c
	 gcc -o loadstrings loadstrings.c queue.c

encrypt: encrypt.c polybius.c
	 gcc -o encrypt encrypt.c polybius.c

main: main.c queue.c
	 gcc -o main main.c queue.c

clean:
	 rm -f genstrings loadstrings encrypt main *.txt

