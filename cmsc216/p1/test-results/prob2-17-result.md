(TEST 17) stock_plot5 : ok
==========================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_plot5
---------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_plot5
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                          ===ACTUAL===
{                                                                   . {
    // Loads a stock from a file and checks if they are printed     .     // Loads a stock from a file and checks if they are printed
    // correctly. Buy/Sell indices are separated so on the top axis .     // correctly. Buy/Sell indices are separated so on the top axis
    // should see a B====S corresponding to the range the stock is  .     // should see a B====S corresponding to the range the stock is
    // purchased. Buy/Sell correspond to Lo/Hi prices. Prints whole .     // purchased. Buy/Sell correspond to Lo/Hi prices. Prints whole
    // plot and then a slice of the plot.                           .     // plot and then a slice of the plot.
    stock_t *stock = stock_new();                                   .     stock_t *stock = stock_new();
    int ret = stock_load(stock,"data/stock-valley.txt");            .     int ret = stock_load(stock,"data/stock-valley.txt");
    printf("ret: %d\n",ret);                                        .     printf("ret: %d\n",ret);
    stock_set_hilo(stock);                                          .     stock_set_hilo(stock);
    stock_set_best(stock);                                          .     stock_set_best(stock);
    stock_print(stock);                                             .     stock_print(stock);
    stock_plot(stock, 10, 0, stock->count);                         .     stock_plot(stock, 10, 0, stock->count);
    printf("\n");                                                   .     printf("\n");
    stock_plot(stock, 7, 3, stock->count-3);                        .     stock_plot(stock, 7, 3, stock->count-3);
    stock_free(stock);                                              .     stock_free(stock);
}                                                                   . }
ret: 0                                                              . ret: 0
==STOCK DATA==                                                      . ==STOCK DATA==
data_file: data/stock-valley.txt                                    . data_file: data/stock-valley.txt
count: 12                                                           . count: 12
prices: [100.00, 90.00, 80.00, ...]                                 . prices: [100.00, 90.00, 80.00, ...]
lo_index:  5                                                        . lo_index: 5
hi_index:  11                                                       . hi_index: 11
best_buy:  5                                                        . best_buy: 5
best_sell: 11                                                       . best_sell: 11
profit:    55.00                                                    . profit: 55.00
==PLOT DATA==                                                       . ==PLOT DATA==
start/stop:  0 12                                                   . start/stop: 0 12
max_height:  10                                                     . max_height: 10
price range: 55.00                                                  . price range: 55.00
plot step:   5.50                                                   . plot step: 5.50
           +-----B=====S+                                           .            +-----B=====S+
     99.50 |*          H|                                           .      99.50 |*          H|
     94.00 |*         *H|                                           .      94.00 |*         *H|
     88.50 |**        *H|                                           .      88.50 |**        *H|
     83.00 |**       **H|                                           .      83.00 |**       **H|
     77.50 |***      **H|                                           .      77.50 |***      **H|
     72.00 |***     ***H|                                           .      72.00 |***     ***H|
     66.50 |****    ***H|                                           .      66.50 |****    ***H|
     61.00 |****   ****H|                                           .      61.00 |****   ****H|
     55.50 |*****  ****H|                                           .      55.50 |*****  ****H|
     50.00 |*****L*****H|                                           .      50.00 |*****L*****H|
           +^----^----^-+                                           .            +^----^----^-+
            0    5    10                                            .             0    5    10   
                                                                    . 
==PLOT DATA==                                                       . ==PLOT DATA==
start/stop:  3 9                                                    . start/stop: 3 9
max_height:  7                                                      . max_height: 7
price range: 55.00                                                  . price range: 55.00
plot step:   7.86                                                   . plot step: 7.86
           +--B===+                                                 .            +--B===+
     97.14 |      |                                                 .      97.14 |      |
     89.29 |      |                                                 .      89.29 |      |
     81.43 |      |                                                 .      81.43 |      |
     73.57 |     *|                                                 .      73.57 |     *|
     65.71 |*    *|                                                 .      65.71 |*    *|
     57.86 |**  **|                                                 .      57.86 |**  **|
     50.00 |**L***|                                                 .      50.00 |**L***|
           +--^---+                                                 .            +--^---+
              5                                                     .             5    

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_plot5
which may be pasted onto a command line to run it.

```
==443725== Memcheck, a memory error detector
==443725== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443725== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443725== Command: ./test_stock_funcs stock_plot5
==443725== 
==443725== 
==443725== HEAP SUMMARY:
==443725==     in use at exit: 0 bytes in 0 blocks
==443725==   total heap usage: 7 allocs, 7 frees, 9,294 bytes allocated
==443725== 
==443725== All heap blocks were freed -- no leaks are possible
==443725== 
==443725== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
