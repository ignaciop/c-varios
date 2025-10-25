(TEST 2) stock_set_hilo2 : ok
=============================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_set_hilo2
-------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_set_hilo2
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                        ===ACTUAL===
{                                                                 . {
    // Checks if stock_set_hilo() correctly sets the lo_index and .     // Checks if stock_set_hilo() correctly sets the lo_index and
    // hi_index fields in a larger prices array                   .     // hi_index fields in a larger prices array
    double prices[10] = {                                         .     double prices[10] = {
      125.72, 190.04, 45.25, 32.37, 40.99,                        .       125.72, 190.04, 45.25, 32.37, 40.99, 
      168.00, 16.03, 14.11, 50.00, 96.89,                         .       168.00, 16.03, 14.11, 50.00, 96.89,
    };                                                            .     };
    stock_t *stock = stock_new();                                 .     stock_t *stock = stock_new();
                                                                  . 
    stock->data_file = strdup("bouncy-prices.txt");               .     stock->data_file = strdup("bouncy-prices.txt");
    stock->count = 10;                                            .     stock->count = 10;
    stock->prices = malloc(sizeof(double)*10);                    .     stock->prices = malloc(sizeof(double)*10);
    memcpy(stock->prices, prices, sizeof(double)*10);             .     memcpy(stock->prices, prices, sizeof(double)*10);
    stock->lo_index =  -1;                                        .     stock->lo_index = -1;
    stock->hi_index =  -1;                                        .     stock->hi_index = -1;
    stock->best_buy  = -1;                                        .     stock->best_buy  = -1;
    stock->best_sell = -1;                                        .     stock->best_sell = -1;
                                                                  . 
    stock_set_hilo(stock);                                        .     stock_set_hilo(stock);
    stock_print(stock);                                           .     stock_print(stock);
                                                                  . 
    stock_free(stock);                                            .     stock_free(stock);
}                                                                 . }
==STOCK DATA==                                                    . ==STOCK DATA==
data_file: bouncy-prices.txt                                      . data_file: bouncy-prices.txt
count: 10                                                         . count: 10
prices: [125.72, 190.04, 45.25, ...]                              . prices: [125.72, 190.04, 45.25, ...]
lo_index:  7                                                      . lo_index: 7
hi_index:  1                                                      . hi_index: 1
best_buy:  -1                                                     . best_buy: -1
best_sell: -1                                                     . best_sell: -1
profit:    0.00                                                   . profit: 0.00

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_set_hilo2
which may be pasted onto a command line to run it.

```
==443709== Memcheck, a memory error detector
==443709== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443709== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443709== Command: ./test_stock_funcs stock_set_hilo2
==443709== 
==443709== 
==443709== HEAP SUMMARY:
==443709==     in use at exit: 0 bytes in 0 blocks
==443709==   total heap usage: 3 allocs, 3 frees, 138 bytes allocated
==443709== 
==443709== All heap blocks were freed -- no leaks are possible
==443709== 
==443709== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
