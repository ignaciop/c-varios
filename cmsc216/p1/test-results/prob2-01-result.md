(TEST 1) stock_set_hilo1 : ok
=============================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_set_hilo1
-------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_set_hilo1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                        ===ACTUAL===
{                                                                 . {
    // Checks if stock_set_hilo() correctly sets the lo_index and .     // Checks if stock_set_hilo() correctly sets the lo_index and
    // hi_index fields in a small prices array                    .     // hi_index fields in a small prices array
    double prices[5] = {                                          .     double prices[5] = {
      168.00, 16.03, 14.11, 50.00, 96.89,                         .       168.00, 16.03, 14.11, 50.00, 96.89,
    };                                                            .     };
    stock_t stock = {                                             .     stock_t stock = {
      .data_file = "5prices.txt",                                 .       .data_file = "5prices.txt",
      .count = 5,                                                 .       .count = 5,
      .prices = prices,                                           .       .prices = prices,
      .lo_index =  -1,                                            .       .lo_index  = -1,
      .hi_index =  -1,                                            .       .hi_index  = -1,
      .best_buy  = -1,                                            .       .best_buy  = -1,
      .best_sell = -1,                                            .       .best_sell = -1,
    };                                                            .     };
    stock_set_hilo(&stock);                                       .     stock_set_hilo(&stock);
                                                                  . 
    stock_print(&stock);                                          .     stock_print(&stock);
}                                                                 . }
==STOCK DATA==                                                    . ==STOCK DATA==
data_file: 5prices.txt                                            . data_file: 5prices.txt
count: 5                                                          . count: 5
prices: [168.00, 16.03, 14.11, ...]                               . prices: [168.00, 16.03, 14.11, ...]
lo_index:  2                                                      . lo_index: 2
hi_index:  0                                                      . hi_index: 0
best_buy:  -1                                                     . best_buy: -1
best_sell: -1                                                     . best_sell: -1
profit:    0.00                                                   . profit: 0.00

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_set_hilo1
which may be pasted onto a command line to run it.

```
==443712== Memcheck, a memory error detector
==443712== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443712== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443712== Command: ./test_stock_funcs stock_set_hilo1
==443712== 
==443712== 
==443712== HEAP SUMMARY:
==443712==     in use at exit: 0 bytes in 0 blocks
==443712==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==443712== 
==443712== All heap blocks were freed -- no leaks are possible
==443712== 
==443712== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
