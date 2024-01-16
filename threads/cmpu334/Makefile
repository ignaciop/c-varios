# Default set to debugging flags. 
CFLAGS=-Wall -Wextra -Wno-unused-value -pedantic -Og -march=native

CC=gcc

all: train reaction

train: train-runner.c train.c train.h
	$(CC) $(CFLAGS) -o train train-runner.c train.c -lpthread 

reaction: reaction-runner.c reaction.c reaction.h
	$(CC) $(CFLAGS) -o reaction reaction-runner.c reaction.c -lpthread 

run_train: train
	./train
	./train
	./train
	
run_reaction: reaction
	./reaction 0
	./reaction 0
	./reaction 20
	./reaction 20
	./reaction 40
	./reaction 40
	./reaction 60
	./reaction 60
	./reaction 80
	./reaction 80
	./reaction 100
	./reaction 100

clean:
	rm -rf train reaction