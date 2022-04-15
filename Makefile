LIBS=-lssl -lcrypto -lm
CFLAGS= -Wall -pedantic -O0 -g
SRC=bench.c buffer.c password_bf.c
OBJ=${SRC:.c=.o}

CC=gcc
RM=rm -f
EXEC=password_bf

all: $(EXEC)

password_bf: ${OBJ}
	$(CC) $^ -o $@ $(LIBS) $(CFLAGS)

password_bf.o: password_bf.c
	$(CC) -c $^ $(CFLAGS)

bench.o: bench.c
	$(CC) -c $^ $(CFLAGS)

buffer.o: buffer.c
	$(CC) -c $^ $(CFLAGS)

run:
	./$(EXEC)

clean:
	$(RM) $(OBJ) $(EXEC)
