(TEST 11) stock_load3 : ok
==========================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_load3
---------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_load3
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                           ===ACTUAL===
{                                                                    . {
    // Checks loading a stock file via stock_load() on a file in the .     // Checks loading a stock file via stock_load() on a file in the
    // data/ directory.  This directory must be present with the     .     // data/ directory.  This directory must be present with the
    // provided data files for the tests to work correctly.          .     // provided data files for the tests to work correctly.
    stock_t *stock = stock_new();                                    .     stock_t *stock = stock_new();
    int ret = stock_load(stock, "data/stock-GOOG-08-02-2021.txt");   .     int ret = stock_load(stock, "data/stock-GOOG-08-02-2021.txt");
    printf("ret: %d\n", ret);                                        .     printf("ret: %d\n", ret);
    stock_print(stock);                                              .     stock_print(stock);
    stock_free(stock);                                               .     stock_free(stock);
}                                                                    . }
ret: 0                                                               . ret: 0
==STOCK DATA==                                                       . ==STOCK DATA==
data_file: data/stock-GOOG-08-02-2021.txt                            . data_file: data/stock-GOOG-08-02-2021.txt
count: 345                                                           . count: 345
prices: [2715.00, 2715.00, 2711.00, ...]                             . prices: [2715.00, 2715.00, 2711.00, ...]
lo_index:  -1                                                        . lo_index: -1
hi_index:  -1                                                        . hi_index: -1
best_buy:  -1                                                        . best_buy: -1
best_sell: -1                                                        . best_sell: -1
profit:    0.00                                                      . profit: 0.00

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_load3
which may be pasted onto a command line to run it.

```
==443719== Memcheck, a memory error detector
==443719== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443719== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443719== Command: ./test_stock_funcs stock_load3
==443719== 
==443719== 
==443719== HEAP SUMMARY:
==443719==     in use at exit: 0 bytes in 0 blocks
==443719==   total heap usage: 7 allocs, 7 frees, 11,967 bytes allocated
==443719== 
==443719== All heap blocks were freed -- no leaks are possible
==443719== 
==443719== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
