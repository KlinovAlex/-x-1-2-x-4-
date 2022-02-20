CC=gcc
CFLAGS=-Wall -Wextra -Werror -c
OFLAGS=-Wall -Wextra -Werror -o

all:
	$(MAKE) main

clean:
	rm -rf *.o *.a *.so

main:
	$(CC) $(CFLAGS) graph.c input.c draw.c
	$(CC) $(OFLAGS) ../build/graph graph.c input.c draw.c
	$(MAKE) clean

rebuild:
	$(MAKE) clean
	$(MAKE) all
	$(MAKE) clean
