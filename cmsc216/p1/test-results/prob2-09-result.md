(TEST 9) stock_load1 : ok
=========================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_load1
---------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_load1
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                         ===ACTUAL===
{                                                                  . {
    // Checks stock_load() on a small data file to determine if it .     // Checks stock_load() on a small data file to determine if it
    // correctly loads a small number of prices into an existing   .     // correctly loads a small number of prices into an existing
    // stock.                                                      .     // stock.
    stock_t *stock = stock_new();                                  .     stock_t *stock = stock_new();
    int ret = stock_load(stock, "data/stock-3only.txt");           .     int ret = stock_load(stock, "data/stock-3only.txt");
    printf("ret: %d\n", ret);                                      .     printf("ret: %d\n", ret);
    stock_print(stock);                                            .     stock_print(stock);
    stock_free(stock);                                             .     stock_free(stock);
}                                                                  . }
ret: 0                                                             . ret: 0
==STOCK DATA==                                                     . ==STOCK DATA==
data_file: data/stock-3only.txt                                    . data_file: data/stock-3only.txt
count: 3                                                           . count: 3
prices: [103.07, 45.26, 59.43]                                     . prices: [103.07, 45.26, 59.43]
lo_index:  -1                                                      . lo_index: -1
hi_index:  -1                                                      . hi_index: -1
best_buy:  -1                                                      . best_buy: -1
best_sell: -1                                                      . best_sell: -1
profit:    0.00                                                    . profit: 0.00

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_load1
which may be pasted onto a command line to run it.

```
==443718== Memcheck, a memory error detector
==443718== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443718== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443718== Command: ./test_stock_funcs stock_load1
==443718== 
==443718== 
==443718== HEAP SUMMARY:
==443718==     in use at exit: 0 bytes in 0 blocks
==443718==   total heap usage: 7 allocs, 7 frees, 9,221 bytes allocated
==443718== 
==443718== All heap blocks were freed -- no leaks are possible
==443718== 
==443718== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
