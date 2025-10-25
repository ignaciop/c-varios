(TEST 6) stock_print1 : ok
==========================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_print1
----------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_print1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                    ===ACTUAL===
{                                                             . {
    // Tests whether stock_print() correctly prints a freshly .     // Tests whether stock_print() correctly prints a freshly
    // allocated stock after stock_new().                     .     // allocated stock after stock_new().
                                                              . 
    stock_t *stock = stock_new();                             .     stock_t *stock = stock_new();
    stock_print(stock);                                       .     stock_print(stock);
    stock_free(stock);                                        .     stock_free(stock);
}                                                             . }
==STOCK DATA==                                                . ==STOCK DATA==
data_file: NULL                                               . data_file: NULL
count: -1                                                     . count: -1
prices: NULL                                                  . prices: NULL
lo_index:  -1                                                 . lo_index: -1
hi_index:  -1                                                 . hi_index: -1
best_buy:  -1                                                 . best_buy: -1
best_sell: -1                                                 . best_sell: -1
profit:    0.00                                               . profit: 0.00

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_print1
which may be pasted onto a command line to run it.

```
==443616== Memcheck, a memory error detector
==443616== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443616== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443616== Command: ./test_stock_funcs stock_print1
==443616== 
==443616== 
==443616== HEAP SUMMARY:
==443616==     in use at exit: 0 bytes in 0 blocks
==443616==   total heap usage: 1 allocs, 1 frees, 40 bytes allocated
==443616== 
==443616== All heap blocks were freed -- no leaks are possible
==443616== 
==443616== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
