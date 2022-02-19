CC=gcc
CFLAGS=-Wall -Wextra -Werror -c
OFLAGS=-Wall -Wextra -Werror -o

all:
	$(MAKE) first_period

clean:
	rm -rf *.o *.a *.so

first_period:
	$(CC) $(CFLAGS) test_parsing.c input.c
	$(CC) $(OFLAGS) First test_parsing.o input.o
	$(MAKE) clean

rebuild:
	$(MAKE) clean
	$(MAKE) all
	$(MAKE) clean
