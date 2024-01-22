CFLAGS = -g -Wall -std=gnu99 -D_REENTRANT

all : tree tree_mutex

tree : tree.o
	$(CC) -o $@ tree.o -lpthread

tree_mutex : tree_mutex.o
	$(CC) -o $@ tree_mutex.o -lpthread

clean :
	rm -f  tree tree_mutex *.o
