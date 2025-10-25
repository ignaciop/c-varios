(TEST 8) stock_main Facebook Stock 152 to 203 : ok
==================================================

COMMENTS
--------
Runs on a stock_main on a larger Facebook stock file. The range is
slightly odd: 152 to 203 to check that the bottom index printing looks
correct.

PROGRAM: ./stock_main data/stock-FB-08-02-2021.txt 20 152 203
-------------------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./stock_main data/stock-FB-08-02-2021.txt 20 152 203
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                        ===ACTUAL===
==STOCK DATA==                                                    . ==STOCK DATA==
data_file: data/stock-FB-08-02-2021.txt                           . data_file: data/stock-FB-08-02-2021.txt
count: 543                                                        . count: 543
prices: [358.94, 358.50, 358.50, ...]                             . prices: [358.94, 358.50, 358.50, ...]
lo_index:  470                                                    . lo_index: 470
hi_index:  15                                                     . hi_index: 15
best_buy:  109                                                    . best_buy: 109
best_sell: 129                                                    . best_sell: 129
profit:    2.38                                                   . profit: 2.38
==PLOT DATA==                                                     . ==PLOT DATA==
start/stop:  152 203                                              . start/stop: 152 203
max_height:  20                                                   . max_height: 20
price range: 8.00                                                 . price range: 8.00
plot step:   0.40                                                 . plot step: 0.40
           +---------------------------------------------------+  .            +---------------------------------------------------+
    358.59 |                                                   |  .     358.59 |                                                   |
    358.19 |                                                   |  .     358.19 |                                                   |
    357.79 |                                                   |  .     357.79 |                                                   |
    357.39 |                                                   |  .     357.39 |                                                   |
    356.99 |                                                   |  .     356.99 |                                                   |
    356.59 |                                                   |  .     356.59 |                                                   |
    356.19 |                                                   |  .     356.19 |                                                   |
    355.79 |                                                   |  .     355.79 |                                                   |
    355.39 |                                                   |  .     355.39 |                                                   |
    354.99 |                                                   |  .     354.99 |                                                   |
    354.59 |                                                   |  .     354.59 |                                                   |
    354.19 |                              *  * **             *|  .     354.19 |                              *  * **             *|
    353.79 |                       ***********************   **|  .     353.79 |                       ***********************   **|
    353.39 |*      **          * ******************************|  .     353.39 |*      **          * ******************************|
    352.99 |**** ***** ** *************************************|  .     352.99 |**** ***** ** *************************************|
    352.59 |***************************************************|  .     352.59 |***************************************************|
    352.19 |***************************************************|  .     352.19 |***************************************************|
    351.79 |***************************************************|  .     351.79 |***************************************************|
    351.39 |***************************************************|  .     351.39 |***************************************************|
    350.99 |***************************************************|  .     350.99 |***************************************************|
           +---^----^----^----^----^----^----^----^----^----^--+  .            +---^----^----^----^----^----^----^----^----^----^--+
               155  160  165  170  175  180  185  190  195  200   .             155  160  165  170  175  180  185  190  195  200  

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./stock_main data/stock-FB-08-02-2021.txt 20 152 203
which may be pasted onto a command line to run it.

```
==443841== Memcheck, a memory error detector
==443841== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443841== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443841== Command: ./stock_main data/stock-FB-08-02-2021.txt 20 152 203
==443841== 
==443841== 
==443841== HEAP SUMMARY:
==443841==     in use at exit: 0 bytes in 0 blocks
==443841==   total heap usage: 7 allocs, 7 frees, 13,549 bytes allocated
==443841== 
==443841== All heap blocks were freed -- no leaks are possible
==443841== 
==443841== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
