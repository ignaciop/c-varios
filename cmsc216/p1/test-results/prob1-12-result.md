(TEST 12) stock_print_prices_1 : ok
===================================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_print_prices_1
------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_print_prices_1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                               ===ACTUAL===
{                                                        . {
    // Checks printing 1-length prices array is correct. .     // Checks printing 1-length prices array is correct.
    double prices[1] = {45.25};                          .     double prices[1] = {45.25};
                                                         . 
    stock_t stock = {                                    .     stock_t stock = {
      .data_file = "some-file.txt",                      .       .data_file = "some-file.txt",
      .count = 1,                                        .       .count = 1,
      .prices = prices,                                  .       .prices = prices,
      .lo_index =  -1,                                   .       .lo_index  = -1,
      .hi_index =  -1,                                   .       .hi_index  = -1,
      .best_buy  = -1,                                   .       .best_buy  = -1,
      .best_sell = -1,                                   .       .best_sell = -1,
    };                                                   .     };
    stock_print(&stock);                                 .     stock_print(&stock);
}                                                        . }
==STOCK DATA==                                           . ==STOCK DATA==
data_file: some-file.txt                                 . data_file: some-file.txt
count: 1                                                 . count: 1
prices: [45.25]                                          . prices: [45.25]
lo_index:  -1                                            . lo_index: -1
hi_index:  -1                                            . hi_index: -1
best_buy:  -1                                            . best_buy: -1
best_sell: -1                                            . best_sell: -1
profit:    0.00                                          . profit: 0.00

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_print_prices_1
which may be pasted onto a command line to run it.

```
==443622== Memcheck, a memory error detector
==443622== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443622== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443622== Command: ./test_stock_funcs stock_print_prices_1
==443622== 
==443622== 
==443622== HEAP SUMMARY:
==443622==     in use at exit: 0 bytes in 0 blocks
==443622==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==443622== 
==443622== All heap blocks were freed -- no leaks are possible
==443622== 
==443622== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
