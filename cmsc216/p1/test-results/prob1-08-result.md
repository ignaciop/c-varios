(TEST 8) stock_print3 : ok
==========================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_print3
----------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_print3
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
    // Allocates a stack-based stock then fills in some values for it  .     // Allocates a stack-based stock then fills in some values for it
    // and checks for correct printing. The prices array has 5         .     // and checks for correct printing. The prices array has 5
    // elements so checks for correct printing of the first 3 elements .     // elements so checks for correct printing of the first 3 elements
    // plus the ... elipses.                                           .     // plus the ... elipses.
                                                                       . 
    double prices[5] = {10.0, 5.0, 15.0, 20.0, 5.0};                   .     double prices[5] = {10.0, 5.0, 15.0, 20.0, 5.0};
                                                                       . 
    stock_t stock = {                                                  .     stock_t stock = {
      .data_file = "a-data-file.txt",                                  .       .data_file = "a-data-file.txt",
      .count = 5,                                                      .       .count = 5,
      .prices = prices,                                                .       .prices = prices,
      .lo_index =  -1,                                                 .       .lo_index  = -1,
      .hi_index =  -1,                                                 .       .hi_index  = -1,
      .best_buy  = -1,                                                 .       .best_buy  = -1,
      .best_sell = -1,                                                 .       .best_sell = -1,
    };                                                                 .     };
    stock_print(&stock);                                               .     stock_print(&stock);
}                                                                      . }
==STOCK DATA==                                                         . ==STOCK DATA==
data_file: a-data-file.txt                                             . data_file: a-data-file.txt
count: 5                                                               . count: 5
prices: [10.00, 5.00, 15.00, ...]                                      . prices: [10.00, 5.00, 15.00, ...]
lo_index:  -1                                                          . lo_index: -1
hi_index:  -1                                                          . hi_index: -1
best_buy:  -1                                                          . best_buy: -1
best_sell: -1                                                          . best_sell: -1
profit:    0.00                                                        . profit: 0.00

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_print3
which may be pasted onto a command line to run it.

```
==443618== Memcheck, a memory error detector
==443618== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443618== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443618== Command: ./test_stock_funcs stock_print3
==443618== 
==443618== 
==443618== HEAP SUMMARY:
==443618==     in use at exit: 0 bytes in 0 blocks
==443618==   total heap usage: 0 allocs, 0 frees, 0 bytes allocated
==443618== 
==443618== All heap blocks were freed -- no leaks are possible
==443618== 
==443618== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
