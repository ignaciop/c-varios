(TEST 18) stock_plot6 : ok
==========================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_plot6
---------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_plot6
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
    // correctly. Buy/Sell indices are separated so on the top axis    .     // correctly. Buy/Sell indices are separated so on the top axis
    // should see a B====S corresponding to the range the stock is     .     // should see a B====S corresponding to the range the stock is
    // purchased. Buy/Sell does NOT correspond to Lo/Hi prices. Prints .     // purchased. Buy/Sell does NOT correspond to Lo/Hi prices. Prints
    // whole plot and then a slice of the plot.                        .     // whole plot and then a slice of the plot.
    stock_t *stock = stock_new();                                      .     stock_t *stock = stock_new();
    int ret = stock_load(stock,"data/stock-min-after-max.txt");        .     int ret = stock_load(stock,"data/stock-min-after-max.txt");
    printf("ret: %d\n",ret);                                           .     printf("ret: %d\n",ret);
    stock_set_hilo(stock);                                             .     stock_set_hilo(stock);
    stock_set_best(stock);                                             .     stock_set_best(stock);
    stock_print(stock);                                                .     stock_print(stock);
    stock_plot(stock, 10, 0, stock->count);                            .     stock_plot(stock, 10, 0, stock->count);
    printf("\n");                                                      .     printf("\n");
    stock_plot(stock, 12, 3, stock->count-2);                          .     stock_plot(stock, 12, 3, stock->count-2);
    stock_free(stock);                                                 .     stock_free(stock);
}                                                                      . }
ret: 0                                                                 . ret: 0
==STOCK DATA==                                                         . ==STOCK DATA==
data_file: data/stock-min-after-max.txt                                . data_file: data/stock-min-after-max.txt
count: 15                                                              . count: 15
prices: [223.00, 292.00, 27.00, ...]                                   . prices: [223.00, 292.00, 27.00, ...]
lo_index:  10                                                          . lo_index: 10
hi_index:  4                                                           . hi_index: 4
best_buy:  2                                                           . best_buy: 2
best_sell: 4                                                           . best_sell: 4
profit:    296.00                                                      . profit: 296.00
==PLOT DATA==                                                          . ==PLOT DATA==
start/stop:  0 15                                                      . start/stop: 0 15
max_height:  10                                                        . max_height: 10
price range: 309.00                                                    . price range: 309.00
plot step:   30.90                                                     . plot step: 30.90
           +--B=S----------+                                           .            +--B=S----------+
    292.10 |    H   *      |                                           .     292.10 |    H   *      |
    261.20 | *  H   *      |                                           .     261.20 | *  H   *      |
    230.30 | *  H   *      |                                           .     230.30 | *  H   *      |
    199.40 |**  H * *      |                                           .     199.40 |**  H * *      |
    168.50 |**  H** *  *  *|                                           .     168.50 |**  H** *  *  *|
    137.60 |**  H****  ****|                                           .     137.60 |**  H****  ****|
    106.70 |**  H****  ****|                                           .     106.70 |**  H****  ****|
     75.80 |** *H***** ****|                                           .      75.80 |** *H***** ****|
     44.90 |** *H***** ****|                                           .      44.90 |** *H***** ****|
     14.00 |****H*****L****|                                           .      14.00 |****H*****L****|
           +^----^----^----+                                           .            +^----^----^----+
            0    5    10                                               .             0    5    10   
                                                                       . 
==PLOT DATA==                                                          . ==PLOT DATA==
start/stop:  3 13                                                      . start/stop: 3 13
max_height:  12                                                        . max_height: 12
price range: 309.00                                                    . price range: 309.00
plot step:   25.75                                                     . plot step: 25.75
           +=S--------+                                                .            +=S--------+
    297.25 | H   *    |                                                .     297.25 | H   *    |
    271.50 | H   *    |                                                .     271.50 | H   *    |
    245.75 | H   *    |                                                .     245.75 | H   *    |
    220.00 | H   *    |                                                .     220.00 | H   *    |
    194.25 | H * *    |                                                .     194.25 | H * *    |
    168.50 | H** *  * |                                                .     168.50 | H** *  * |
    142.75 | H** *  **|                                                .     142.75 | H** *  **|
    117.00 | H****  **|                                                .     117.00 | H****  **|
     91.25 |*H****  **|                                                .      91.25 |*H****  **|
     65.50 |*H***** **|                                                .      65.50 |*H***** **|
     39.75 |*H***** **|                                                .      39.75 |*H***** **|
     14.00 |*H*****L**|                                                .      14.00 |*H*****L**|
           +--^----^--+                                                .            +--^----^--+
              5    10                                                  .             5    10   

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_plot6
which may be pasted onto a command line to run it.

```
==443726== Memcheck, a memory error detector
==443726== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443726== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443726== Command: ./test_stock_funcs stock_plot6
==443726== 
==443726== 
==443726== HEAP SUMMARY:
==443726==     in use at exit: 0 bytes in 0 blocks
==443726==   total heap usage: 7 allocs, 7 frees, 9,325 bytes allocated
==443726== 
==443726== All heap blocks were freed -- no leaks are possible
==443726== 
==443726== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
