#this makefile compiles all the files in activity

CC=gcc
all: log summarize

log: problem1.c
	$(CC) problem1.c -o log

summarize: problem2.c
	$(CC) problem2.c -o summarize

clean:
	rm -f log summarize
