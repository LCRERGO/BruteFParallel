FLAGS=-lssl -lcrypto
CFLAGS=-O3 -Wall -pedantic -g

CC=gcc

RM=rm -f

EXEC=password_bf

SRC=password_bf.c
OBJ=${SRC:.c=.o}

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(FLAGS) $(CFLAGS)

.o: .c
	$(CC) $^ -o $@ $(CFLAGS) $(LIBS) $(FLAGS)

run:
	./$(EXEC)

clean:
	$(RM) password_bf.o $(EXEC)
