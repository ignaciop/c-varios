(TEST 3) stock_set_hilo3 : ok
=============================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_set_hilo3
-------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_set_hilo3
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
    // Checks behavior of stock_set_hilo() in length 0 and length 1 .     // Checks behavior of stock_set_hilo() in length 0 and length 1
    // arrays                                                       .     // arrays
    double prices0[0] = {};                                         .     double prices0[0] = {};
    stock_t stock0 = {                                              .     stock_t stock0 = {
      .data_file = "0prices.txt",                                   .       .data_file = "0prices.txt",
      .count = 0,                                                   .       .count = 0,
      .prices = prices0,                                            .       .prices = prices0,
      .lo_index =  -1,                                              .       .lo_index  = -1,
      .hi_index =  -1,                                              .       .hi_index  = -1,
      .best_buy  = -1,                                              .       .best_buy  = -1,
      .best_sell = -1,                                              .       .best_sell = -1,
    };                                                              .     };
    stock_set_hilo(&stock0);                                        .     stock_set_hilo(&stock0);
    stock_print(&stock0);                                           .     stock_print(&stock0);
                                                                    . 
    double prices1[1] = {123.45};                                   .     double prices1[1] = {123.45};
    stock_t stock1 = {                                              .     stock_t stock1 = {
      .data_file = "1prices.txt",                                   .       .data_file = "1prices.txt",
      .count = 1,                                                   .       .count = 1,
      .prices = prices1,                                            .       .prices = prices1,
      .lo_index =  -1,                                              .       .lo_index  = -1,
      .hi_index =  -1,                                              .       .hi_index  = -1,
      .best_buy  = -1,                                              .       .best_buy  = -1,
      .best_sell = -1,                                              .       .best_sell = -1,
    };                                                              .     };
    stock_set_hilo(&stock1);                                        .     stock_set_hilo(&stock1);
    stock_print(&stock1);                                           .     stock_print(&stock1);
}                                                                   . }
==STOCK DATA==                                                      . ==STOCK DATA==
data_file: 0prices.txt                                              . data_file: 0prices.txt
count: 0                                                            . count: 0
prices: []                                                          . prices: []
lo_index:  -1                                                       . lo_index: -1
hi_index:  -1                                                       . hi_index: -1
best_buy:  -1                                                       . best_buy: -1
best_sell: -1                                                       . best_sell: -1
profit:    0.00                                                     . profit: 0.00
==STOCK DATA==                                                      . ==STOCK DATA==
data_file: 1prices.txt                                              . data_file: 1prices.txt
count: 1                                                            . count: 1
prices: [123.45]                                                    . prices: [123.45]
lo_index:  0                                                        . lo_index: 0
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
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_set_hilo3
which may be pasted onto a command line to run it.

```
==443710== Memcheck, a memory error detector
==443710== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443710== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443710== Command: ./test_stock_funcs stock_set_hilo3
==443710== 
==443710== 
==443710== HEAP SUMMARY:
==443710==     in use at exit: 0 bytes in 0 blocks
==443710==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==443710== 
==443710== All heap blocks were freed -- no leaks are possible
==443710== 
==443710== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
