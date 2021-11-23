CC=gcc
FLAGS= -Wall

all: connections

connections: main.o my_mat.a
	$(CC) -o connections main.o my_mat.a 

my_mat.a: my_mat.o
	ar rcs my_mat.a my_mat.o

main.o: main.c  my_mat.h
	$(CC) $(FLAGS) -c main.c  

my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -c my_mat.c 

.PHONY: clean all

clean: 
	rm -f *.o connections