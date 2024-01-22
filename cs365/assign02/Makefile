# CS 365 - Assignment 2 makefile

CC = gcc
CFLAGS = -g -Wall -std=gnu99 -D_REENTRANT

SRCS = grid.c life.c
OBJS = $(SRCS:%.c=%.o)
MAINSRCS = life_seq.c #life_par.c
PROGS = $(MAINSRCS:%.c=%)

all : $(PROGS)

life_seq : life_seq.o $(OBJS)
	$(CC) -o $@ life_seq.o $(OBJS)

#life_par : life_par.o $(OBJS)
#	$(CC) -o $@ life_par.o $(OBJS)

clean :
	rm -f *.o $(PROGS)