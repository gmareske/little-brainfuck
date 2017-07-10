CC= gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic

grisp: main.c
	$(CC) $(CFLAGS) main.c -o gbf

.PHONY: clean

clean:
	-rm *.o *~ core paper
