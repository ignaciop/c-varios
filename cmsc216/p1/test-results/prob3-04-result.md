(TEST 4) stock_main data/stock-ascending.txt 5 to End : ok
==========================================================

COMMENTS
--------
Runs the ~stock_main~ program on data/stock-ascending.txt but specify
only the 3 command line args which are
1. stock file
2. max height
3. initial index
This leaves off the stop index which should default to the end of the
prices array. In this case the output should be the same as the
preceding test

PROGRAM: ./stock_main data/stock-ascending.txt 15 5
---------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./stock_main data/stock-ascending.txt 15 5
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                          ===ACTUAL===
==STOCK DATA==                      . ==STOCK DATA==
data_file: data/stock-ascending.txt . data_file: data/stock-ascending.txt
count: 10                           . count: 10
prices: [10.00, 20.00, 30.00, ...]  . prices: [10.00, 20.00, 30.00, ...]
lo_index:  0                        . lo_index: 0
hi_index:  9                        . hi_index: 9
best_buy:  0                        . best_buy: 0
best_sell: 9                        . best_sell: 9
profit:    90.00                    . profit: 90.00
==PLOT DATA==                       . ==PLOT DATA==
start/stop:  5 10                   . start/stop: 5 10
max_height:  15                     . max_height: 15
price range: 90.00                  . price range: 90.00
plot step:   6.00                   . plot step: 6.00
           +====S+                  .            +====S+
     94.00 |    H|                  .      94.00 |    H|
     88.00 |   *H|                  .      88.00 |   *H|
     82.00 |   *H|                  .      82.00 |   *H|
     76.00 |  **H|                  .      76.00 |  **H|
     70.00 | ***H|                  .      70.00 | ***H|
     64.00 | ***H|                  .      64.00 | ***H|
     58.00 |****H|                  .      58.00 |****H|
     52.00 |****H|                  .      52.00 |****H|
     46.00 |****H|                  .      46.00 |****H|
     40.00 |****H|                  .      40.00 |****H|
     34.00 |****H|                  .      34.00 |****H|
     28.00 |****H|                  .      28.00 |****H|
     22.00 |****H|                  .      22.00 |****H|
     16.00 |****H|                  .      16.00 |****H|
     10.00 |****H|                  .      10.00 |****H|
           +^----+                  .            +^----+
            5                       .             5    

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./stock_main data/stock-ascending.txt 15 5
which may be pasted onto a command line to run it.

```
==443836== Memcheck, a memory error detector
==443836== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443836== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443836== Command: ./stock_main data/stock-ascending.txt 15 5
==443836== 
==443836== 
==443836== HEAP SUMMARY:
==443836==     in use at exit: 0 bytes in 0 blocks
==443836==   total heap usage: 7 allocs, 7 frees, 9,281 bytes allocated
==443836== 
==443836== All heap blocks were freed -- no leaks are possible
==443836== 
==443836== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
