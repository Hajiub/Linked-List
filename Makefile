CC = gcc
CFLAGS = -Wall -Wextra

all: linkedlist

linkedlist: main.o
	$(CC) $(CFLAGS) -o $@ $^

main.o: main.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm -f *.o linkedlist
