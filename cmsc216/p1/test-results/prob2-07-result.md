(TEST 7) stock_set_best4 : ok
=============================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_set_best4
-------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_set_best4
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
    // Checks that when there is no profitable time to buy/sell     .     // Checks that when there is no profitable time to buy/sell
    // (profit of 0.0), then the best_buy / best_sell are set to -1 .     // (profit of 0.0), then the best_buy / best_sell are set to -1
    // and the function returns -1                                  .     // and the function returns -1
    double prices[8] = {                                            .     double prices[8] = {
      50.0, 45.0, 30.0, 22.0, 18.0,                                 .       50.0, 45.0, 30.0, 22.0, 18.0,
      15.0, 10.5, 8.5,                                              .       15.0, 10.5, 8.5,
    };                                                              .     };
    stock_t stock = {                                               .     stock_t stock = {
      .data_file = "prices.txt",                                    .       .data_file = "prices.txt",
      .count = 8,                                                   .       .count = 8,
      .prices = prices,                                             .       .prices = prices,
      .lo_index =  -1,                                              .       .lo_index  = -1,
      .hi_index =  -1,                                              .       .hi_index  = -1,
      .best_buy  = 0,                                               .       .best_buy  = 0,
      .best_sell = 0,                                               .       .best_sell = 0,
    };                                                              .     };
    int ret = stock_set_best(&stock);                               .     int ret = stock_set_best(&stock);
    stock_set_hilo(&stock);                                         .     stock_set_hilo(&stock);
    printf("ret: %d\n", ret);                                       .     printf("ret: %d\n", ret);
    stock_print(&stock);                                            .     stock_print(&stock);
}                                                                   . }
ret: -1                                                             . ret: -1
==STOCK DATA==                                                      . ==STOCK DATA==
data_file: prices.txt                                               . data_file: prices.txt
count: 8                                                            . count: 8
prices: [50.00, 45.00, 30.00, ...]                                  . prices: [50.00, 45.00, 30.00, ...]
lo_index:  7                                                        . lo_index: 7
hi_index:  0                                                        . hi_index: 0
best_buy:  -1                                                       . best_buy: -1
best_sell: -1                                                       . best_sell: -1
profit:    0.00                                                     . profit: 0.00

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_set_best4
which may be pasted onto a command line to run it.

```
==443714== Memcheck, a memory error detector
==443714== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443714== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443714== Command: ./test_stock_funcs stock_set_best4
==443714== 
==443714== 
==443714== HEAP SUMMARY:
==443714==     in use at exit: 0 bytes in 0 blocks
==443714==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==443714== 
==443714== All heap blocks were freed -- no leaks are possible
==443714== 
==443714== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
