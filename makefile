CC = g++
CFLAGS = -g -Wall

default: test

test:	        Vector.o main.o
	$(CC) $(CFlags) -o test Vector.o main.o

Vector.o:       Vector.cpp Vector.h
	$(CC) $(CFLAGS) -c Vector.cpp


main.o:	main.cpp Vector.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	$(RM) test *.o *~
