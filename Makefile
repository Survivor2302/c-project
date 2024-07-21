# Compiler et options
CC = gcc
CFLAGS = -Wall -Wextra -g

# Fichiers sources
SRC = casino.c roulette.c craps.c machine_a_sous.c blackjack.c

OBJ = $(SRC:.c=.o)

DEPS = casino.h roulette.h craps.h machine_a_sous.h blackjack.h

# Nom de l'exécutable
EXEC = casino

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) $(EXEC)