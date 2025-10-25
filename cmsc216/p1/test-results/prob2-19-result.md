(TEST 19) stock_plot7 : ok
==========================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_plot7
---------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_plot7
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                             ===ACTUAL===
{                                                                      . {
    // Loads a stock from a file and checks if they are printed        .     // Loads a stock from a file and checks if they are printed
    // correctly. The file contains Tesla prices and two slices of the .     // correctly. The file contains Tesla prices and two slices of the
    // them are printed, around the time to buy and around the time to .     // them are printed, around the time to buy and around the time to
    // sell.                                                           .     // sell.
    stock_t *stock = stock_new();                                      .     stock_t *stock = stock_new();
    int ret = stock_load(stock,"data/stock-TSLA-08-12-2021.txt");      .     int ret = stock_load(stock,"data/stock-TSLA-08-12-2021.txt");
    printf("ret: %d\n",ret);                                           .     printf("ret: %d\n",ret);
    stock_set_hilo(stock);                                             .     stock_set_hilo(stock);
    stock_set_best(stock);                                             .     stock_set_best(stock);
    stock_print(stock);                                                .     stock_print(stock);
    stock_plot(stock, 15, 125, 171);                                   .     stock_plot(stock, 15, 125, 171);
    printf("\n");                                                      .     printf("\n");
    stock_plot(stock, 20, 482, 537);                                   .     stock_plot(stock, 20, 482, 537);
    stock_free(stock);                                                 .     stock_free(stock);
}                                                                      . }
ret: 0                                                                 . ret: 0
==STOCK DATA==                                                         . ==STOCK DATA==
data_file: data/stock-TSLA-08-12-2021.txt                              . data_file: data/stock-TSLA-08-12-2021.txt
count: 654                                                             . count: 654
prices: [706.00, 706.00, 705.38, ...]                                  . prices: [706.00, 706.00, 705.38, ...]
lo_index:  143                                                         . lo_index: 143
hi_index:  522                                                         . hi_index: 522
best_buy:  143                                                         . best_buy: 143
best_sell: 522                                                         . best_sell: 522
profit:    24.80                                                       . profit: 24.80
==PLOT DATA==                                                          . ==PLOT DATA==
start/stop:  125 171                                                   . start/stop: 125 171
max_height:  15                                                        . max_height: 15
price range: 24.80                                                     . price range: 24.80
plot step:   1.65                                                      . plot step: 1.65
           +------------------B===========================+            .            +------------------B===========================+
    724.18 |                                              |            .     724.18 |                                              |
    722.52 |                                              |            .     722.52 |                                              |
    720.87 |                                              |            .     720.87 |                                              |
    719.22 |                                              |            .     719.22 |                                              |
    717.57 |                                              |            .     717.57 |                                              |
    715.91 |                                              |            .     715.91 |                                              |
    714.26 |                                              |            .     714.26 |                                              |
    712.61 |                                              |            .     712.61 |                                              |
    710.95 |                                              |            .     710.95 |                                              |
    709.30 |                                             *|            .     709.30 |                                             *|
    707.65 |                                         *****|            .     707.65 |                                         *****|
    705.99 |*                                     ********|            .     705.99 |*                                     ********|
    704.34 |** *****                        **************|            .     704.34 |** *****                        **************|
    702.69 |********** *              ********************|            .     702.69 |********** *              ********************|
    701.03 |******************L***************************|            .     701.03 |******************L***************************|
           +^----^----^----^----^----^----^----^----^----^+            .            +^----^----^----^----^----^----^----^----^----^+
            125  130  135  140  145  150  155  160  165  170           .             125  130  135  140  145  150  155  160  165  170  
                                                                       . 
==PLOT DATA==                                                          . ==PLOT DATA==
start/stop:  482 537                                                   . start/stop: 482 537
max_height:  20                                                        . max_height: 20
price range: 24.80                                                     . price range: 24.80
plot step:   1.24                                                      . plot step: 1.24
           +========================================S--------------+   .            +========================================S--------------+
    724.59 |                                     *  H******        |   .     724.59 |                                     *  H******        |
    723.35 |                   *  ****  ************H**************|   .     723.35 |                   *  ****  ************H**************|
    722.11 |       **** ** *************************H**************|   .     722.11 |       **** ** *************************H**************|
    720.87 |     ***********************************H**************|   .     720.87 |     ***********************************H**************|
    719.63 |****************************************H**************|   .     719.63 |****************************************H**************|
    718.39 |****************************************H**************|   .     718.39 |****************************************H**************|
    717.15 |****************************************H**************|   .     717.15 |****************************************H**************|
    715.91 |****************************************H**************|   .     715.91 |****************************************H**************|
    714.67 |****************************************H**************|   .     714.67 |****************************************H**************|
    713.43 |****************************************H**************|   .     713.43 |****************************************H**************|
    712.19 |****************************************H**************|   .     712.19 |****************************************H**************|
    710.95 |****************************************H**************|   .     710.95 |****************************************H**************|
    709.71 |****************************************H**************|   .     709.71 |****************************************H**************|
    708.47 |****************************************H**************|   .     708.47 |****************************************H**************|
    707.23 |****************************************H**************|   .     707.23 |****************************************H**************|
    705.99 |****************************************H**************|   .     705.99 |****************************************H**************|
    704.75 |****************************************H**************|   .     704.75 |****************************************H**************|
    703.51 |****************************************H**************|   .     703.51 |****************************************H**************|
    702.27 |****************************************H**************|   .     702.27 |****************************************H**************|
    701.03 |****************************************H**************|   .     701.03 |****************************************H**************|
           +---^----^----^----^----^----^----^----^----^----^----^-+   .            +---^----^----^----^----^----^----^----^----^----^----^-+
               485  490  495  500  505  510  515  520  525  530  535   .             485  490  495  500  505  510  515  520  525  530  535  
                                                                       ( 

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_plot7
which may be pasted onto a command line to run it.

```
==443727== Memcheck, a memory error detector
==443727== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443727== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443727== Command: ./test_stock_funcs stock_plot7
==443727== 
==443727== 
==443727== HEAP SUMMARY:
==443727==     in use at exit: 0 bytes in 0 blocks
==443727==   total heap usage: 7 allocs, 7 frees, 14,439 bytes allocated
==443727== 
==443727== All heap blocks were freed -- no leaks are possible
==443727== 
==443727== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
