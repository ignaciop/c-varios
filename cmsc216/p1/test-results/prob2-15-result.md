(TEST 15) stock_plot3 : ok
==========================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_plot3
---------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_plot3
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
    // Print full plot then print a slice from index 2 to 6. Checks if .     // Print full plot then print a slice from index 2 to 6. Checks if
    // the bottom axis and axis numbers are printed correctly.         .     // the bottom axis and axis numbers are printed correctly. 
    double prices[7] = {5.0, 15.0, 0.0, 10.0, 25.0, 20.0, 17.0};       .     double prices[7] = {5.0, 15.0, 0.0, 10.0, 25.0, 20.0, 17.0};
    stock_t stock = {                                                  .     stock_t stock = {
      .data_file = "c-data-file.txt",                                  .       .data_file = "c-data-file.txt",
      .count = 7,                                                      .       .count = 7,
      .prices = prices,                                                .       .prices = prices,
      .lo_index  = 2,                                                  .       .lo_index  = 2,
      .hi_index  = 4,                                                  .       .hi_index  = 4,
      .best_buy  = -1,                                                 .       .best_buy  = -1,
      .best_sell = -1,                                                 .       .best_sell = -1,
    };                                                                 .     };
    stock_plot(&stock, 10, 0, stock.count);                            .     stock_plot(&stock, 10, 0, stock.count);
    printf("\n");                                                      .     printf("\n");
    stock_plot(&stock, 10, 2, 6);                                      .     stock_plot(&stock, 10, 2, 6);
}                                                                      . }
==PLOT DATA==                                                          . ==PLOT DATA==
start/stop:  0 7                                                       . start/stop: 0 7
max_height:  10                                                        . max_height: 10
price range: 25.00                                                     . price range: 25.00
plot step:   2.50                                                      . plot step: 2.50
           +-------+                                                   .            +-------+
     22.50 |    H  |                                                   .      22.50 |    H  |
     20.00 |    H* |                                                   .      20.00 |    H* |
     17.50 |    H* |                                                   .      17.50 |    H* |
     15.00 | *  H**|                                                   .      15.00 | *  H**|
     12.50 | *  H**|                                                   .      12.50 | *  H**|
     10.00 | * *H**|                                                   .      10.00 | * *H**|
      7.50 | * *H**|                                                   .       7.50 | * *H**|
      5.00 |** *H**|                                                   .       5.00 |** *H**|
      2.50 |** *H**|                                                   .       2.50 |** *H**|
      0.00 |**L*H**|                                                   .       0.00 |**L*H**|
           +^----^-+                                                   .            +^----^-+
            0    5                                                     .             0    5    
                                                                       . 
==PLOT DATA==                                                          . ==PLOT DATA==
start/stop:  2 6                                                       . start/stop: 2 6
max_height:  10                                                        . max_height: 10
price range: 25.00                                                     . price range: 25.00
plot step:   2.50                                                      . plot step: 2.50
           +----+                                                      .            +----+
     22.50 |  H |                                                      .      22.50 |  H |
     20.00 |  H*|                                                      .      20.00 |  H*|
     17.50 |  H*|                                                      .      17.50 |  H*|
     15.00 |  H*|                                                      .      15.00 |  H*|
     12.50 |  H*|                                                      .      12.50 |  H*|
     10.00 | *H*|                                                      .      10.00 | *H*|
      7.50 | *H*|                                                      .       7.50 | *H*|
      5.00 | *H*|                                                      .       5.00 | *H*|
      2.50 | *H*|                                                      .       2.50 | *H*|
      0.00 |L*H*|                                                      .       0.00 |L*H*|
           +---^+                                                      .            +---^+
               5                                                       .             5    

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_plot3
which may be pasted onto a command line to run it.

```
==443723== Memcheck, a memory error detector
==443723== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443723== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443723== Command: ./test_stock_funcs stock_plot3
==443723== 
==443723== 
==443723== HEAP SUMMARY:
==443723==     in use at exit: 0 bytes in 0 blocks
==443723==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==443723== 
==443723== All heap blocks were freed -- no leaks are possible
==443723== 
==443723== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
