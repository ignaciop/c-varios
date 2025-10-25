(TEST 14) stock_plot2 : ok
==========================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_plot2
---------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_plot2
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
    // Similar to previous test but this time with non-integer plot .     // Similar to previous test but this time with non-integer plot
    // step for vertical bars.                                      .     // step for vertical bars.
    double prices[5] = {5.0, 25.0, 10.0, 0.0, 15.0};                .     double prices[5] = {5.0, 25.0, 10.0, 0.0, 15.0};
    stock_t stock = {                                               .     stock_t stock = {
      .data_file = "b-data-file.txt",                               .       .data_file = "b-data-file.txt",
      .count = 5,                                                   .       .count = 5,
      .prices = prices,                                             .       .prices = prices,
      .lo_index  = 3,                                               .       .lo_index  = 3,
      .hi_index  = 1,                                               .       .hi_index  = 1,
      .best_buy  = -1,                                              .       .best_buy  = -1,
      .best_sell = -1,                                              .       .best_sell = -1,
    };                                                              .     };
    stock_plot(&stock, 6, 0, stock.count);                          .     stock_plot(&stock, 6, 0, stock.count);
    printf("\n");                                                   .     printf("\n");
    stock_plot(&stock, 12, 0, stock.count);                         .     stock_plot(&stock, 12, 0, stock.count);
}                                                                   . }
==PLOT DATA==                                                       . ==PLOT DATA==
start/stop:  0 5                                                    . start/stop: 0 5
max_height:  6                                                      . max_height: 6
price range: 25.00                                                  . price range: 25.00
plot step:   4.17                                                   . plot step: 4.17
           +-----+                                                  .            +-----+
     20.83 | H   |                                                  .      20.83 | H   |
     16.67 | H   |                                                  .      16.67 | H   |
     12.50 | H  *|                                                  .      12.50 | H  *|
      8.33 | H* *|                                                  .       8.33 | H* *|
      4.17 |*H* *|                                                  .       4.17 |*H* *|
      0.00 |*H*L*|                                                  .       0.00 |*H*L*|
           +^----+                                                  .            +^----+
            0                                                       .             0    
                                                                    . 
==PLOT DATA==                                                       . ==PLOT DATA==
start/stop:  0 5                                                    . start/stop: 0 5
max_height:  12                                                     . max_height: 12
price range: 25.00                                                  . price range: 25.00
plot step:   2.08                                                   . plot step: 2.08
           +-----+                                                  .            +-----+
     22.92 | H   |                                                  .      22.92 | H   |
     20.83 | H   |                                                  .      20.83 | H   |
     18.75 | H   |                                                  .      18.75 | H   |
     16.67 | H   |                                                  .      16.67 | H   |
     14.58 | H  *|                                                  .      14.58 | H  *|
     12.50 | H  *|                                                  .      12.50 | H  *|
     10.42 | H  *|                                                  .      10.42 | H  *|
      8.33 | H* *|                                                  .       8.33 | H* *|
      6.25 | H* *|                                                  .       6.25 | H* *|
      4.17 |*H* *|                                                  .       4.17 |*H* *|
      2.08 |*H* *|                                                  .       2.08 |*H* *|
      0.00 |*H*L*|                                                  .       0.00 |*H*L*|
           +^----+                                                  .            +^----+
            0                                                       .             0    

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_plot2
which may be pasted onto a command line to run it.

```
==443721== Memcheck, a memory error detector
==443721== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443721== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443721== Command: ./test_stock_funcs stock_plot2
==443721== 
==443721== 
==443721== HEAP SUMMARY:
==443721==     in use at exit: 0 bytes in 0 blocks
==443721==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==443721== 
==443721== All heap blocks were freed -- no leaks are possible
==443721== 
==443721== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
