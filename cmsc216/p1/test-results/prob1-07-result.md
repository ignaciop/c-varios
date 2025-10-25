(TEST 7) stock_print2 : ok
==========================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_print2
----------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_print2
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                  ===ACTUAL===
{                                                           . {
    // Allocates a stack-based stock and checks for correct .     // Allocates a stack-based stock and checks for correct
    // printing. No free-ing is requred in this case.       .     // printing. No free-ing is requred in this case.
                                                            . 
    stock_t stock = {                                       .     stock_t stock = {
      .data_file = NULL,                                    .       .data_file = NULL,
      .count = -1,                                          .       .count = -1,
      .prices = NULL,                                       .       .prices = NULL,
      .lo_index =  -1,                                      .       .lo_index  = -1,
      .hi_index =  -1,                                      .       .hi_index  = -1,
      .best_buy  = -1,                                      .       .best_buy  = -1,
      .best_sell = -1,                                      .       .best_sell = -1,
    };                                                      .     };
    stock_print(&stock);                                    .     stock_print(&stock);
}                                                           . }
==STOCK DATA==                                              . ==STOCK DATA==
data_file: NULL                                             . data_file: NULL
count: -1                                                   . count: -1
prices: NULL                                                . prices: NULL
lo_index:  -1                                               . lo_index: -1
hi_index:  -1                                               . hi_index: -1
best_buy:  -1                                               . best_buy: -1
best_sell: -1                                               . best_sell: -1
profit:    0.00                                             . profit: 0.00

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_print2
which may be pasted onto a command line to run it.

```
==443617== Memcheck, a memory error detector
==443617== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443617== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443617== Command: ./test_stock_funcs stock_print2
==443617== 
==443617== 
==443617== HEAP SUMMARY:
==443617==     in use at exit: 0 bytes in 0 blocks
==443617==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==443617== 
==443617== All heap blocks were freed -- no leaks are possible
==443617== 
==443617== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
