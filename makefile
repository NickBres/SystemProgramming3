all: txtfind
	clear

isort: isort.o
	gcc -o isort isort.o

txtfind: txtfind.o
	gcc -o txtfind txtfind.o

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -f *.o isort txtfind