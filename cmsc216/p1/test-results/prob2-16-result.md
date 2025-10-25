(TEST 16) stock_plot4 : ok
==========================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_plot4
---------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_plot4
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                            ===ACTUAL===
{                                                                     . {
    // Best Buy/Sell indices are set expect to see B and S characters .     // Best Buy/Sell indices are set expect to see B and S characters
    // on the top axis corresponding to the these positions. Buy/Sell .     // on the top axis corresponding to the these positions. Buy/Sell
    // positions do not correspond to Hi/Lo prices in this test.      .     // positions do not correspond to Hi/Lo prices in this test.
    double prices[5] = {5.0, 25.0, 10.0, 0.0, 15.0};                  .     double prices[5] = {5.0, 25.0, 10.0, 0.0, 15.0};
    stock_t stock = {                                                 .     stock_t stock = {
      .data_file = "b-data-file.txt",                                 .       .data_file = "b-data-file.txt",
      .count = 5,                                                     .       .count = 5,
      .prices = prices,                                               .       .prices = prices,
      .lo_index  = 3,                                                 .       .lo_index  = 3,
      .hi_index  = 1,                                                 .       .hi_index  = 1,
      .best_buy  = 0,                                                 .       .best_buy  = 0,
      .best_sell = 1,                                                 .       .best_sell = 1,
    };                                                                .     };
    stock_plot(&stock, 10, 0, stock.count);                           .     stock_plot(&stock, 10, 0, stock.count);
    printf("\n");                                                     .     printf("\n");
    stock_plot(&stock, 5, 0, stock.count);                            .     stock_plot(&stock, 5, 0, stock.count);
}                                                                     . }
==PLOT DATA==                                                         . ==PLOT DATA==
start/stop:  0 5                                                      . start/stop: 0 5
max_height:  10                                                       . max_height: 10
price range: 25.00                                                    . price range: 25.00
plot step:   2.50                                                     . plot step: 2.50
           +BS---+                                                    .            +BS---+
     22.50 | H   |                                                    .      22.50 | H   |
     20.00 | H   |                                                    .      20.00 | H   |
     17.50 | H   |                                                    .      17.50 | H   |
     15.00 | H  *|                                                    .      15.00 | H  *|
     12.50 | H  *|                                                    .      12.50 | H  *|
     10.00 | H* *|                                                    .      10.00 | H* *|
      7.50 | H* *|                                                    .       7.50 | H* *|
      5.00 |*H* *|                                                    .       5.00 |*H* *|
      2.50 |*H* *|                                                    .       2.50 |*H* *|
      0.00 |*H*L*|                                                    .       0.00 |*H*L*|
           +^----+                                                    .            +^----+
            0                                                         .             0    
                                                                      . 
==PLOT DATA==                                                         . ==PLOT DATA==
start/stop:  0 5                                                      . start/stop: 0 5
max_height:  5                                                        . max_height: 5
price range: 25.00                                                    . price range: 25.00
plot step:   5.00                                                     . plot step: 5.00
           +BS---+                                                    .            +BS---+
     20.00 | H   |                                                    .      20.00 | H   |
     15.00 | H  *|                                                    .      15.00 | H  *|
     10.00 | H* *|                                                    .      10.00 | H* *|
      5.00 |*H* *|                                                    .       5.00 |*H* *|
      0.00 |*H*L*|                                                    .       0.00 |*H*L*|
           +^----+                                                    .            +^----+
            0                                                         .             0    

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_plot4
which may be pasted onto a command line to run it.

```
==443724== Memcheck, a memory error detector
==443724== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443724== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443724== Command: ./test_stock_funcs stock_plot4
==443724== 
==443724== 
==443724== HEAP SUMMARY:
==443724==     in use at exit: 0 bytes in 0 blocks
==443724==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==443724== 
==443724== All heap blocks were freed -- no leaks are possible
==443724== 
==443724== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
