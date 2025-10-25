(TEST 5) stock_set_best2 : ok
=============================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_set_best2
-------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_set_best2
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
    // Checks for correct setting of best buy/sell point; in this case .     // Checks for correct setting of best buy/sell point; in this case
    // the best buy does matches the minimum price but the best sell   .     // the best buy does matches the minimum price but the best sell
    // point does not match the maximum                                .     // point does not match the maximum
    double prices[13] = {                                              .     double prices[13] = {
      50.0, 45.0, 25.0, 10.0, 12.0,                                    .       50.0, 45.0, 25.0, 10.0, 12.0,
      15.0, 35.0, 34.0, 18.5, 16.5,                                    .       15.0, 35.0, 34.0, 18.5, 16.5,
      15.5, 10.5,                                                      .       15.5, 10.5,
    };                                                                 .     };
    stock_t stock = {                                                  .     stock_t stock = {
      .data_file = "prices.txt",                                       .       .data_file = "prices.txt",
      .count = 13,                                                     .       .count = 13,
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
count: 13                                                              . count: 13
prices: [50.00, 45.00, 25.00, ...]                                     . prices: [50.00, 45.00, 25.00, ...]
lo_index:  12                                                          . lo_index: 12
hi_index:  0                                                           . hi_index: 0
best_buy:  3                                                           . best_buy: 3
best_sell: 6                                                           . best_sell: 6
profit:    25.00                                                       . profit: 25.00

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_set_best2
which may be pasted onto a command line to run it.

```
==443713== Memcheck, a memory error detector
==443713== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443713== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443713== Command: ./test_stock_funcs stock_set_best2
==443713== 
==443713== 
==443713== HEAP SUMMARY:
==443713==     in use at exit: 0 bytes in 0 blocks
==443713==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==443713== 
==443713== All heap blocks were freed -- no leaks are possible
==443713== 
==443713== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
