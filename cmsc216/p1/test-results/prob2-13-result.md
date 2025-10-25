(TEST 13) stock_plot1 : ok
==========================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_plot1
---------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_plot1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                               ===ACTUAL===
{                                                                        . {
    // Plots a stock with a small prices array that is NOT loaded from   .     // Plots a stock with a small prices array that is NOT loaded from
    // a file with a couple different heights. Prices and max_height are .     // a file with a couple different heights. Prices and max_height are
    // selected for an integer (non-fraction) plot step.                 .     // selected for an integer (non-fraction) plot step.
    double prices[6] = {5.0, 15.0, 0.0, 10.0, 25.0, 20.0};               .     double prices[6] = {5.0, 15.0, 0.0, 10.0, 25.0, 20.0};
    stock_t stock = {                                                    .     stock_t stock = {
      .data_file = "a-data-file.txt",                                    .       .data_file = "a-data-file.txt",
      .count = 6,                                                        .       .count = 6,
      .prices = prices,                                                  .       .prices = prices,
      .lo_index  = 2,                                                    .       .lo_index  = 2,
      .hi_index  = 4,                                                    .       .hi_index  = 4,
      .best_buy  = -1,                                                   .       .best_buy  = -1,
      .best_sell = -1,                                                   .       .best_sell = -1,
    };                                                                   .     };
    stock_plot(&stock, 5, 0, stock.count);                               .     stock_plot(&stock, 5, 0, stock.count);
    printf("\n");                                                        .     printf("\n");
    stock_plot(&stock, 25, 0, stock.count);                              .     stock_plot(&stock, 25, 0, stock.count);
}                                                                        . }
==PLOT DATA==                                                            . ==PLOT DATA==
start/stop:  0 6                                                         . start/stop: 0 6
max_height:  5                                                           . max_height: 5
price range: 25.00                                                       . price range: 25.00
plot step:   5.00                                                        . plot step: 5.00
           +------+                                                      .            +------+
     20.00 |    H*|                                                      .      20.00 |    H*|
     15.00 | *  H*|                                                      .      15.00 | *  H*|
     10.00 | * *H*|                                                      .      10.00 | * *H*|
      5.00 |** *H*|                                                      .       5.00 |** *H*|
      0.00 |**L*H*|                                                      .       0.00 |**L*H*|
           +^----^+                                                      .            +^----^+
            0    5                                                       .             0    5    
                                                                         . 
==PLOT DATA==                                                            . ==PLOT DATA==
start/stop:  0 6                                                         . start/stop: 0 6
max_height:  25                                                          . max_height: 25
price range: 25.00                                                       . price range: 25.00
plot step:   1.00                                                        . plot step: 1.00
           +------+                                                      .            +------+
     24.00 |    H |                                                      .      24.00 |    H |
     23.00 |    H |                                                      .      23.00 |    H |
     22.00 |    H |                                                      .      22.00 |    H |
     21.00 |    H |                                                      .      21.00 |    H |
     20.00 |    H*|                                                      .      20.00 |    H*|
     19.00 |    H*|                                                      .      19.00 |    H*|
     18.00 |    H*|                                                      .      18.00 |    H*|
     17.00 |    H*|                                                      .      17.00 |    H*|
     16.00 |    H*|                                                      .      16.00 |    H*|
     15.00 | *  H*|                                                      .      15.00 | *  H*|
     14.00 | *  H*|                                                      .      14.00 | *  H*|
     13.00 | *  H*|                                                      .      13.00 | *  H*|
     12.00 | *  H*|                                                      .      12.00 | *  H*|
     11.00 | *  H*|                                                      .      11.00 | *  H*|
     10.00 | * *H*|                                                      .      10.00 | * *H*|
      9.00 | * *H*|                                                      .       9.00 | * *H*|
      8.00 | * *H*|                                                      .       8.00 | * *H*|
      7.00 | * *H*|                                                      .       7.00 | * *H*|
      6.00 | * *H*|                                                      .       6.00 | * *H*|
      5.00 |** *H*|                                                      .       5.00 |** *H*|
      4.00 |** *H*|                                                      .       4.00 |** *H*|
      3.00 |** *H*|                                                      .       3.00 |** *H*|
      2.00 |** *H*|                                                      .       2.00 |** *H*|
      1.00 |** *H*|                                                      .       1.00 |** *H*|
      0.00 |**L*H*|                                                      .       0.00 |**L*H*|
           +^----^+                                                      .            +^----^+
            0    5                                                       .             0    5    

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_plot1
which may be pasted onto a command line to run it.

```
==443722== Memcheck, a memory error detector
==443722== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443722== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443722== Command: ./test_stock_funcs stock_plot1
==443722== 
==443722== 
==443722== HEAP SUMMARY:
==443722==     in use at exit: 0 bytes in 0 blocks
==443722==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==443722== 
==443722== All heap blocks were freed -- no leaks are possible
==443722== 
==443722== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
