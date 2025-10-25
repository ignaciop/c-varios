(TEST 4) stock_set_best1 : ok
=============================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_set_best1
-------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_set_best1
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
    // Checks for correct setting of best buy/sell point which aligns  .     // Checks for correct setting of best buy/sell point which aligns
    // with the stock min/max prices in this test                      .     // with the stock min/max prices in this test
    double prices[9] = {                                               .     double prices[9] = {
      45.0, 35.0, 25.0, 15.0, 5.0,                                     .       45.0, 35.0, 25.0, 15.0, 5.0,
      10.0, 20.0, 30.0, 7.0,                                           .       10.0, 20.0, 30.0, 7.0,
    };                                                                 .     };
    stock_t stock = {                                                  .     stock_t stock = {
      .data_file = "prices.txt",                                       .       .data_file = "prices.txt",
      .count = 9,                                                      .       .count = 9,
      .prices = prices,                                                .       .prices = prices,
      .lo_index =  -1,                                                 .       .lo_index  = -1,
      .hi_index =  -1,                                                 .       .hi_index  = -1,
      .best_buy  = -1,                                                 .       .best_buy  = -1,
      .best_sell = -1,                                                 .       .best_sell = -1,
    };                                                                 .     };
    int ret = stock_set_best(&stock);                                  .     int ret = stock_set_best(&stock);
    stock_set_hilo(&stock);                                            .     stock_set_hilo(&stock);
    printf("ret: %d\n", ret);                                          .     printf("ret: %d\n", ret);
    stock_print(&stock);                                               .     stock_print(&stock);
}                                                                      . }
ret: 0                                                                 . ret: 0
==STOCK DATA==                                                         . ==STOCK DATA==
data_file: prices.txt                                                  . data_file: prices.txt
count: 9                                                               . count: 9
prices: [45.00, 35.00, 25.00, ...]                                     . prices: [45.00, 35.00, 25.00, ...]
lo_index:  4                                                           . lo_index: 4
hi_index:  0                                                           . hi_index: 0
best_buy:  4                                                           . best_buy: 4
best_sell: 7                                                           . best_sell: 7
profit:    25.00                                                       . profit: 25.00
{                                                                      . {
    // Checks for correct setting of best buy/sell point; in this case .     // Checks for correct setting of best buy/sell point; in this case
    // the best buy does not match the minimum price but the best sell .     // the best buy does not match the minimum price but the best sell
    // point does match the maximum                                    .     // point does match the maximum
    double prices[10] = {                                              .     double prices[10] = {
      30.0, 20.0, 30.0, 40.0, 50.0,                                    .       30.0, 20.0, 30.0, 40.0, 50.0,
      45.0, 35.0, 25.0, 15.0, 5.0,                                     .       45.0, 35.0, 25.0, 15.0, 5.0,
    };                                                                 .     };
    stock_t stock = {                                                  .     stock_t stock = {
      .data_file = "prices.txt",                                       .       .data_file = "prices.txt",
      .count = 10,                                                     .       .count = 10,
      .prices = prices,                                                .       .prices = prices,
      .lo_index =  -1,                                                 .       .lo_index  = -1,
      .hi_index =  -1,                                                 .       .hi_index  = -1,
      .best_buy  = -1,                                                 .       .best_buy  = -1,
      .best_sell = -1,                                                 .       .best_sell = -1,
    };                                                                 .     };
    int ret = stock_set_best(&stock);                                  .     int ret = stock_set_best(&stock);
    stock_set_hilo(&stock);                                            .     stock_set_hilo(&stock);
    printf("ret: %d\n", ret);                                          .     printf("ret: %d\n", ret);
    stock_print(&stock);                                               .     stock_print(&stock);
}                                                                      . }
ret: 0                                                                 . ret: 0
==STOCK DATA==                                                         . ==STOCK DATA==
data_file: prices.txt                                                  . data_file: prices.txt
count: 10                                                              . count: 10
prices: [30.00, 20.00, 30.00, ...]                                     . prices: [30.00, 20.00, 30.00, ...]
lo_index:  9                                                           . lo_index: 9
hi_index:  4                                                           . hi_index: 4
best_buy:  1                                                           . best_buy: 1
best_sell: 4                                                           . best_sell: 4
profit:    30.00                                                       . profit: 30.00

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_set_best1
which may be pasted onto a command line to run it.

```
==443711== Memcheck, a memory error detector
==443711== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443711== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443711== Command: ./test_stock_funcs stock_set_best1
==443711== 
==443711== 
==443711== HEAP SUMMARY:
==443711==     in use at exit: 0 bytes in 0 blocks
==443711==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==443711== 
==443711== All heap blocks were freed -- no leaks are possible
==443711== 
==443711== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
