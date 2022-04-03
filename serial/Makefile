FLAGS=-lssl -lcrypto
CFLAGS=-O3 -Wall -pedantic -g
INCS=-I$(CURDIR)
LIBS=-L$(CURDIR)

CC=gcc

RM=rm -f

EXEC=password_bf

SRC=password_bf.c bench.c
OBJ=${SRC:.c=.o}

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(FLAGS) $(LIBS) $(INCS) $(CFLAGS)

%.o: %.c
	$(CC) $^ -c $(CFLAGS) $(LIBS) $(INCS) $(FLAGS)

run:
	./$(EXEC)

clean:
	$(RM) $(OBJ) $(EXEC)
