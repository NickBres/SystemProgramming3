CC = gcc
CFLAGS = -Wall -Wextra -fPIC

all: txtfind isort

isort: isort.o
	$(CC) $(CFLAGS) -o isort isort.o

txtfind: txtfind.o
	$(CC) $(CFLAGS) -o txtfind txtfind.o

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f *.o isort txtfind