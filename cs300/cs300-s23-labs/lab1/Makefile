CFLAGS = -Wall -Wextra -Werror -pedantic -O3 -fsanitize=address -march=native

.PHONY:
	all clean

all:
	reverse_test

reverse_test: reverse.o test_reverse.o
	gcc $(CFLAGS) $^ -o $@

%.o: %.c
	gcc $(CFLAGS) -c $^ -o $@

clean:
	rm -f reverse_test test_reverse.o reverse.o