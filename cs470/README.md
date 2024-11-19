##Project 1 - Pthread Application

#Introduction

The primary purpose of this assignment is to gain experience with multicore parallelism using the standard POSIX Pthreads library, including exposure to multithreading concepts such as mutexes and conditions. The secondary purpose of this assignment is to gain experience implementing a supervisor/worker task queue model of parallel computation.
Description

You will develop a parallel version of the following serial program: sum.c

The program reads a list of "tasks" from a file. Each task consists of a character code indicating an action and a number. The character code can be either a "p" (for "process") or "w" (for "wait"). The input file simulates various workloads entering a multiprocessing system. In a real system, the "p" actions (the tasks) would likely be calls to computational routines. For our purposes, "processing" a task with number n just means waiting n seconds using the sleep function and then updating a few global aggregate variables (sum, odd count, min, and max). The "w" action provides a way to simulate a pause in incoming tasks.

For example, the following script simulates one initial one-second task entering the system, followed by a two-second delay. After the delay, a two-second task enters the system followed by a three-second task.

p 1
w 2
p 2
p 3

Using a purely serial processing system (as implemented in the provided sum.c), the above scenario will take eight seconds to finish:

t=0    t=1    t=2    t=3    t=4    t=5    t=6    t=7    t=8
|      |      |      |      |      |      |      |      |
---------------------------------------------------------
| p 1  | w 2         | p 2          | p 3               |       serial version
---------------------------------------------------------

The final output should match the following (sum, # odd, min, max):

6 2 1 3

In this project you will extend this program to take advantage of a multicore CPU using a task queue model. In such a model, the main program spawns a set number of worker threads. You should read the number of worker threads from the command line as a new second parameter, and you should verify that that number is greater than zero. The main program and worker threads communicate using a task queue to keep track of tasks that still need to be processed.

Observe that if we allowed the first task to be processed during the wait, we could reduce the time by a single second:

t=0    t=1    t=2    t=3    t=4    t=5    t=6    t=7
|      |      |      |      |      |      |      |
--------------------------------------------------
| w 2         | idle                             |      supervisor
--------------------------------------------------
| p 1  | idle | p 2         | p 3                |      single worker
--------------------------------------------------

This can be achieved by splitting the actual processing work out into a worker thread that can work parallel to the original supervisor thread. This allows the supervisor thread to focus on receiving jobs while the worker thread focuses on doing the actual work. In the above scenario, the first task arrives at t=0 while the second two tasks arrive simultaneously at t=2.

Because our tasks are independent, the situation can be further improved by the addition of more worker threads, assuming we have enough physical CPU cores to take advantage of them. In the example above, the last two tasks could be executed simultaneously to save two additional seconds:

t=0    t=1    t=2    t=3    t=4    t=5
|      |      |      |      |      |
------------------------------------
| w 2         | idle               |    supervisor
------------------------------------
| p 1  | idle | p 2         | idle |    worker 1
------------------------------------
| idle        | p 3                |    worker 2
------------------------------------

Your program should work as follows. At the beginning of execution, the supervisor thread spawns a set number of worker threads (given by a command line parameter--if the user enters a non-positive number, simply print an error and exit). The worker threads are idle at first. Once the workers have been fully initialized, the supervisor then begins to handle tasks from the input file by adding them to a task queue, waking up an idle worker thread (if there are any) for each task. When a thread is awakened, they begin to pull tasks from the queue and process them. If the queue ever runs out of tasks, the worker should block again until awakened by the supervisor. If the supervisor encounters a "w" (wait) command, it waits the given number of seconds before continuing in the input file. Otherwise, the supervisor should continue to add "p" tasks with no pause or delay. After all tasks have been added to the queue, the supervisor waits for the queue to be exhausted and for non-idle workers to finish. The supervisor then cleans everything up (nicely! do not forcibly abort worker threads) and exits.

To implement the above system, you should use Pthread threads, mutexes, and conditions as covered in class and in the textbook. You may not use Pthread barriers as they are not C99-compliant, and you may not use message queues because one of the points of the assignment is to implement a synchronized work queue (which is trivial with message queues).

Your program should take the number of worker threads as a second command-line parameter; the performance on parallelizable work loads should scale linearly with the number of threads. Insert debugging output as necessary, but make sure you disable it before you submit. Do NOT modify the output format--your program's output must match the serial version EXACTLY. You must also keep an explicit task queue data structure that is dynamically allocated so that it can grow as necessary to adapt to large numbers of incoming tasks (up to a million is reasonable).

#Hints:

    Add a new worker thread function for most of your worker-side synchronization.
    Implement the task queue as a singly-linked list.
    Use a mutex to protect the global aggregate variables.
    Don't lock around the entire update() call; this will serialize all tasks!
    Use a mutex to protect the task queue.
    Use a condition to block and wake worker threads. Think carefully about which mutex should be used to protect it.
    Declare variables that you don't want the compiler to optimize using the volatile keyword.
    It's ok for the supervisor thread to busy-wait; however, the workers should not!
    Compile with -O0 to debug, then switch to -O2 after you're sure the basics are working.
    Create several test input files and a script to automatically run (and time) all of them.
    Try removing the call to "sleep" in the update function to compress the work times and check for race conditions.
    Don't over-engineer! My reference solution adds fewer than 200 total lines.
