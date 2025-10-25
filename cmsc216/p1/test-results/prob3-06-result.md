(TEST 6) stock_main Facebook Stock 5 to 43 : ok
===============================================

COMMENTS
--------
Runs on a stock_main on a larger Facebook stock file. Prints indices
10 to 23 only which includes the high price.

PROGRAM: ./stock_main data/stock-FB-08-02-2021.txt 15 5 43
----------------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./stock_main data/stock-FB-08-02-2021.txt 15 5 43
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                           ===ACTUAL===
==STOCK DATA==                                       . ==STOCK DATA==
data_file: data/stock-FB-08-02-2021.txt              . data_file: data/stock-FB-08-02-2021.txt
count: 543                                           . count: 543
prices: [358.94, 358.50, 358.50, ...]                . prices: [358.94, 358.50, 358.50, ...]
lo_index:  470                                       . lo_index: 470
hi_index:  15                                        . hi_index: 15
best_buy:  109                                       . best_buy: 109
best_sell: 129                                       . best_sell: 129
profit:    2.38                                      . profit: 2.38
==PLOT DATA==                                        . ==PLOT DATA==
start/stop:  5 43                                    . start/stop: 5 43
max_height:  15                                      . max_height: 15
price range: 8.00                                    . price range: 8.00
plot step:   0.53                                    . plot step: 0.53
           +--------------------------------------+  .            +--------------------------------------+
    358.46 |**********H***          *             |  .     358.46 |**********H***          *             |
    357.92 |**********H***************************|  .     357.92 |**********H***************************|
    357.39 |**********H***************************|  .     357.39 |**********H***************************|
    356.86 |**********H***************************|  .     356.86 |**********H***************************|
    356.32 |**********H***************************|  .     356.32 |**********H***************************|
    355.79 |**********H***************************|  .     355.79 |**********H***************************|
    355.25 |**********H***************************|  .     355.25 |**********H***************************|
    354.72 |**********H***************************|  .     354.72 |**********H***************************|
    354.19 |**********H***************************|  .     354.19 |**********H***************************|
    353.65 |**********H***************************|  .     353.65 |**********H***************************|
    353.12 |**********H***************************|  .     353.12 |**********H***************************|
    352.59 |**********H***************************|  .     352.59 |**********H***************************|
    352.05 |**********H***************************|  .     352.05 |**********H***************************|
    351.52 |**********H***************************|  .     351.52 |**********H***************************|
    350.99 |**********H***************************|  .     350.99 |**********H***************************|
           +^----^----^----^----^----^----^----^--+  .            +^----^----^----^----^----^----^----^--+
            5    10   15   20   25   30   35   40    .             5    10   15   20   25   30   35   40   

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./stock_main data/stock-FB-08-02-2021.txt 15 5 43
which may be pasted onto a command line to run it.

```
==443837== Memcheck, a memory error detector
==443837== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443837== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443837== Command: ./stock_main data/stock-FB-08-02-2021.txt 15 5 43
==443837== 
==443837== 
==443837== HEAP SUMMARY:
==443837==     in use at exit: 0 bytes in 0 blocks
==443837==   total heap usage: 7 allocs, 7 frees, 13,549 bytes allocated
==443837== 
==443837== All heap blocks were freed -- no leaks are possible
==443837== 
==443837== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
