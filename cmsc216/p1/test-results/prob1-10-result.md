(TEST 10) stock_print5 : ok
===========================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_print5
----------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_print5
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
    // Same as previous test but also sets best buy/sell index and     .     // Same as previous test but also sets best buy/sell index and
    // checks for correct printing. This should give a non-zero profit .     // checks for correct printing. This should give a non-zero profit
    // as well.                                                        .     // as well.
                                                                       . 
    double prices[5] = {10.0, 5.0, 15.0, 20.0, 5.0};                   .     double prices[5] = {10.0, 5.0, 15.0, 20.0, 5.0};
                                                                       . 
    stock_t stock = {                                                  .     stock_t stock = {
      .data_file = "more-stock-data.txt",                              .       .data_file = "more-stock-data.txt",
      .count = 5,                                                      .       .count = 5,
      .prices = prices,                                                .       .prices = prices,
      .lo_index =  1,                                                  .       .lo_index  = 1,
      .hi_index =  3,                                                  .       .hi_index  = 3,
      .best_buy  = 1,                                                  .       .best_buy  = 1,
      .best_sell = 3,                                                  .       .best_sell = 3,
    };                                                                 .     };
    stock_print(&stock);                                               .     stock_print(&stock);
}                                                                      . }
==STOCK DATA==                                                         . ==STOCK DATA==
data_file: more-stock-data.txt                                         . data_file: more-stock-data.txt
count: 5                                                               . count: 5
prices: [10.00, 5.00, 15.00, ...]                                      . prices: [10.00, 5.00, 15.00, ...]
lo_index:  1                                                           . lo_index: 1
hi_index:  3                                                           . hi_index: 3
best_buy:  1                                                           . best_buy: 1
best_sell: 3                                                           . best_sell: 3
profit:    15.00                                                       . profit: 15.00

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_print5
which may be pasted onto a command line to run it.

```
==443620== Memcheck, a memory error detector
==443620== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443620== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443620== Command: ./test_stock_funcs stock_print5
==443620== 
==443620== 
==443620== HEAP SUMMARY:
==443620==     in use at exit: 0 bytes in 0 blocks
==443620==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==443620== 
==443620== All heap blocks were freed -- no leaks are possible
==443620== 
==443620== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
