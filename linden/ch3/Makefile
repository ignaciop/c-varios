CFLAGS = -Wall -Wextra -pedantic -O3 -fsanitize=address -march=native

.PHONY:
	all clean

all: basic_parser

basic_parser: main.o parser.o
	gcc $(CFLAGS) $^ -o $@

%.o: %.c
	gcc $(CFLAGS) -c $^ -o $@

clean:
	rm -f basic_parser main.o parser.o