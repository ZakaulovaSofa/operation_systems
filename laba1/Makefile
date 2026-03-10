CC=gcc
CFLAGS=-Wall

SRC=src/main.c src/factorial.c
OBJ=main.o factorial.o

all: factorial

factorial: $(OBJ)
	$(CC) $(OBJ) -o factorial

main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c

factorial.o: src/factorial.c
	$(CC) $(CFLAGS) -c src/factorial.c

clean:
	rm -f *.o factorial
