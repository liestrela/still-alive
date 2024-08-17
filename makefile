CC=gcc
CCFLAGS=-Wall

all: main

main: main.c song.h
	$(CC) $(CCFLAGS) -o $@ $<

clean:
	rm -f main
