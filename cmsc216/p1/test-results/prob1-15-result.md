(TEST 15) stock_print_final : ok
================================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_print_final
---------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_print_final
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
    // Checks printing is correct for a more complex stock that is .     // Checks printing is correct for a more complex stock that is
    // allocated/free'd using standard functions.                  .     // allocated/free'd using standard functions.
    double prices[10] = {                                          .     double prices[10] = {
      125.72, 190.04, 45.25, 32.37, 40.99,                         .       125.72, 190.04, 45.25, 32.37, 40.99, 
      168.00, 16.03, 14.11, 50.00, 96.89,                          .       168.00, 16.03, 14.11, 50.00, 96.89,
    };                                                             .     };
    stock_t *stock = stock_new();                                  .     stock_t *stock = stock_new();
                                                                   . 
    stock->data_file = strdup("bouncy-prices.txt");                .     stock->data_file = strdup("bouncy-prices.txt");
    stock->count = 10;                                             .     stock->count = 10;
    stock->prices = malloc(sizeof(double)*10);                     .     stock->prices = malloc(sizeof(double)*10);
    memcpy(stock->prices, prices, sizeof(double)*10);              .     memcpy(stock->prices, prices, sizeof(double)*10);
    stock->lo_index = 7;                                           .     stock->lo_index = 7;
    stock->hi_index = 2;                                           .     stock->hi_index = 2;
    stock->best_buy  = 3;                                          .     stock->best_buy  = 3;
    stock->best_sell = 5;                                          .     stock->best_sell = 5;
                                                                   . 
    stock_print(stock);                                            .     stock_print(stock);
                                                                   . 
    stock_free(stock);                                             .     stock_free(stock);
}                                                                  . }
==STOCK DATA==                                                     . ==STOCK DATA==
data_file: bouncy-prices.txt                                       . data_file: bouncy-prices.txt
count: 10                                                          . count: 10
prices: [125.72, 190.04, 45.25, ...]                               . prices: [125.72, 190.04, 45.25, ...]
lo_index:  7                                                       . lo_index: 7
hi_index:  2                                                       . hi_index: 2
best_buy:  3                                                       . best_buy: 3
best_sell: 5                                                       . best_sell: 5
profit:    135.63                                                  . profit: 135.63

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_print_final
which may be pasted onto a command line to run it.

```
==443625== Memcheck, a memory error detector
==443625== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443625== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443625== Command: ./test_stock_funcs stock_print_final
==443625== 
==443625== 
==443625== HEAP SUMMARY:
==443625==     in use at exit: 0 bytes in 0 blocks
==443625==   total heap usage: 3 allocs, 3 frees, 138 bytes allocated
==443625== 
==443625== All heap blocks were freed -- no leaks are possible
==443625== 
==443625== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
