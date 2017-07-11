CC= gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic

lbf: main.c
	$(CC) $(CFLAGS) main.c -o lbf

.PHONY: clean

clean:
	-rm *.o *~ core paper
