(TEST 5) stock_main data/stock-min-after-max.txt : ok
=====================================================

COMMENTS
--------
Runs the ~stock_main~ program on a the file
data/stock-min-after-max.txt to see if the correct command line output
is produced.

PROGRAM: ./stock_main data/stock-min-after-max.txt 14
-----------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./stock_main data/stock-min-after-max.txt 14
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                              ===ACTUAL===
==STOCK DATA==                          . ==STOCK DATA==
data_file: data/stock-min-after-max.txt . data_file: data/stock-min-after-max.txt
count: 15                               . count: 15
prices: [223.00, 292.00, 27.00, ...]    . prices: [223.00, 292.00, 27.00, ...]
lo_index:  10                           . lo_index: 10
hi_index:  4                            . hi_index: 4
best_buy:  2                            . best_buy: 2
best_sell: 4                            . best_sell: 4
profit:    296.00                       . profit: 296.00
==PLOT DATA==                           . ==PLOT DATA==
start/stop:  0 15                       . start/stop: 0 15
max_height:  14                         . max_height: 14
price range: 309.00                     . price range: 309.00
plot step:   22.07                      . plot step: 22.07
           +--B=S----------+            .            +--B=S----------+
    300.93 |    H   *      |            .     300.93 |    H   *      |
    278.86 | *  H   *      |            .     278.86 | *  H   *      |
    256.79 | *  H   *      |            .     256.79 | *  H   *      |
    234.71 | *  H   *      |            .     234.71 | *  H   *      |
    212.64 |**  H   *      |            .     212.64 |**  H   *      |
    190.57 |**  H * *      |            .     190.57 |**  H * *      |
    168.50 |**  H** *  *  *|            .     168.50 |**  H** *  *  *|
    146.43 |**  H** *  ****|            .     146.43 |**  H** *  ****|
    124.36 |**  H****  ****|            .     124.36 |**  H****  ****|
    102.29 |**  H****  ****|            .     102.29 |**  H****  ****|
     80.21 |** *H***** ****|            .      80.21 |** *H***** ****|
     58.14 |** *H***** ****|            .      58.14 |** *H***** ****|
     36.07 |** *H***** ****|            .      36.07 |** *H***** ****|
     14.00 |****H*****L****|            .      14.00 |****H*****L****|
           +^----^----^----+            .            +^----^----^----+
            0    5    10                .             0    5    10   

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./stock_main data/stock-min-after-max.txt 14
which may be pasted onto a command line to run it.

```
==443835== Memcheck, a memory error detector
==443835== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443835== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443835== Command: ./stock_main data/stock-min-after-max.txt 14
==443835== 
==443835== 
==443835== HEAP SUMMARY:
==443835==     in use at exit: 0 bytes in 0 blocks
==443835==   total heap usage: 7 allocs, 7 frees, 9,325 bytes allocated
==443835== 
==443835== All heap blocks were freed -- no leaks are possible
==443835== 
==443835== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
