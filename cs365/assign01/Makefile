CFLAGS = -g -Wall -std=gnu99

TESTSRCS = testgrid.c tctest.c
SRCS = grid.c
OBJS = $(SRCS:%.c=%.o)
PROGS = testgrid

test% : test%.o $(OBJS)
	$(CC) -o $@ test$*.o $(OBJS) tctest.o

all : $(PROGS)

testgrid : testgrid.o grid.o tctest.o

clean :
	rm -f *.o $(PROGS)