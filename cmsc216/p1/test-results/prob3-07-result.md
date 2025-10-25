(TEST 7) stock_main Facebook Stock 100 to 140 : ok
==================================================

COMMENTS
--------
Runs on a stock_main on a larger Facebook stock file. Prints
indices 100 to 140 which includes to best buy/sell time. Note the best
buy/sell are completely different from the min/max prices here: a bad
day for Marky Z.

PROGRAM: ./stock_main data/stock-FB-08-02-2021.txt 22 100 140
-------------------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./stock_main data/stock-FB-08-02-2021.txt 22 100 140
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                            ===ACTUAL===
==STOCK DATA==                                        . ==STOCK DATA==
data_file: data/stock-FB-08-02-2021.txt               . data_file: data/stock-FB-08-02-2021.txt
count: 543                                            . count: 543
prices: [358.94, 358.50, 358.50, ...]                 . prices: [358.94, 358.50, 358.50, ...]
lo_index:  470                                        . lo_index: 470
hi_index:  15                                         . hi_index: 15
best_buy:  109                                        . best_buy: 109
best_sell: 129                                        . best_sell: 129
profit:    2.38                                       . profit: 2.38
==PLOT DATA==                                         . ==PLOT DATA==
start/stop:  100 140                                  . start/stop: 100 140
max_height:  22                                       . max_height: 22
price range: 8.00                                     . price range: 8.00
plot step:   0.36                                     . plot step: 0.36
           +---------B===================S----------+ .            +---------B===================S----------+
    358.63 |                                        | .     358.63 |                                        |
    358.26 |                                        | .     358.26 |                                        |
    357.90 |                                        | .     357.90 |                                        |
    357.53 |                                        | .     357.53 |                                        |
    357.17 |                                        | .     357.17 |                                        |
    356.81 |                                        | .     356.81 |                                        |
    356.44 |                                        | .     356.44 |                                        |
    356.08 |                                        | .     356.08 |                                        |
    355.72 |                                        | .     355.72 |                                        |
    355.35 |*                                       | .     355.35 |*                                       |
    354.99 |****                         *          | .     354.99 |****                         *          |
    354.62 |*****                     ******** * ** | .     354.62 |*****                     ******** * ** |
    354.26 |*****          *****      **************| .     354.26 |*****          *****      **************|
    353.90 |*******    *** ********  ***************| .     353.90 |*******    *** ********  ***************|
    353.53 |********   *****************************| .     353.53 |********   *****************************|
    353.17 |********  ******************************| .     353.17 |********  ******************************|
    352.80 |********* ******************************| .     352.80 |********* ******************************|
    352.44 |****************************************| .     352.44 |****************************************|
    352.08 |****************************************| .     352.08 |****************************************|
    351.71 |****************************************| .     351.71 |****************************************|
    351.35 |****************************************| .     351.35 |****************************************|
    350.99 |****************************************| .     350.99 |****************************************|
           +^----^----^----^----^----^----^----^----+ .            +^----^----^----^----^----^----^----^----+
            100  105  110  115  120  125  130  135    .             100  105  110  115  120  125  130  135  

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./stock_main data/stock-FB-08-02-2021.txt 22 100 140
which may be pasted onto a command line to run it.

```
==443839== Memcheck, a memory error detector
==443839== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443839== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443839== Command: ./stock_main data/stock-FB-08-02-2021.txt 22 100 140
==443839== 
==443839== 
==443839== HEAP SUMMARY:
==443839==     in use at exit: 0 bytes in 0 blocks
==443839==   total heap usage: 7 allocs, 7 frees, 13,549 bytes allocated
==443839== 
==443839== All heap blocks were freed -- no leaks are possible
==443839== 
==443839== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
