CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = main.o casino.o poker.o blackjack.o roulette.o
DEPS = casino.h poker.h blackjack.h roulette.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

casino: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o casino
