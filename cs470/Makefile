default: sum par_sum

sum: sum.c
	gcc -g -Wall -Wextra -pedantic -O2 -march=native sum.c -o sum 

par_sum: par_sum.c task_queue.c
	gcc -g -Wall -Wextra -pedantic -O2 -march=native par_sum.c task_queue.c -o par_sum -lpthread

clean:
	rm -f sum par_sum