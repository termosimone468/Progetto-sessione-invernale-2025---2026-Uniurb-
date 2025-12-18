all: main

main: main.c
	gcc -Wall -ansi -g -o main main.c
pulisci:
	rm -f main
