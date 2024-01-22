CC = gcc
CFLAGS = -O -Wall -std=gnu99 -D_REENTRANT

PROGS = sumu16 sumu16_par

all : sumu16 sumu16_par

sumu16 : sumu16.o common.o
	$(CC) -o $@ sumu16.o common.o

sumu16_par : sumu16_par.o common.o
	$(CC) -o $@ sumu16_par.o common.o -lpthread

clean :
	rm -f *.o $(PROGS) *~
