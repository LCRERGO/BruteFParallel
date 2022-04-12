FLAGS=-lssl -lcrypto -lm

CFLAGS= -Wall -pedantic -O2

CC=gcc

RM=rm -f

EXEC=password_bf

all: $(EXEC)

password_bf: password_bf.c bench.o
	$(CC) $^ -o $@ $(FLAGS) $(CFLAGS)


bench.o: bench.c
	$(CC) -c $^ $(CFLAGS)

run:
	./$(EXEC)

clean:
	$(RM) password_bf.o $(EXEC)
