CC = gcc
CFLAGS = -Wall -Wextra -g

programa: main.o data.o
	$(CC) $(CFLAGS) main.o data.o -o programa

main.o: main.c data.h
	$(CC) $(CFLAGS) -c main.c

data.o: data.c data.h
	$(CC) $(CFLAGS) -c data.c

clean:
	rm -f *.o programa