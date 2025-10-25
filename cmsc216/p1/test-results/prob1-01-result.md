(TEST 1) stock_new : ok
=======================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_new
-------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_new
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
    // Tests stock_new() function and whether it initializes fields .     // Tests stock_new() function and whether it initializes fields
    // correctly before returning a stock.                          .     // correctly before returning a stock.
                                                                    . 
    stock_t *stock = stock_new(); // call function to allocate/init .     stock_t *stock = stock_new(); // call function to allocate/init
                                                                    . 
    printf("stock->data_file: %p\n" , stock->data_file);            .     printf("stock->data_file: %p\n" , stock->data_file);
    printf("stock->count:     %d\n" , stock->count);                .     printf("stock->count:     %d\n" , stock->count);
    printf("stock->prices:    %p\n" , stock->prices);               .     printf("stock->prices:    %p\n" , stock->prices);
    printf("stock->lo_index:  %d\n" , stock->lo_index);             .     printf("stock->lo_index:  %d\n" , stock->lo_index);
    printf("stock->hi_index:  %d\n" , stock->hi_index);             .     printf("stock->hi_index:  %d\n" , stock->hi_index);
    printf("stock->best_buy:  %d\n" , stock->best_buy);             .     printf("stock->best_buy:  %d\n" , stock->best_buy);
    printf("stock->best_sell: %d\n" , stock->best_sell);            .     printf("stock->best_sell: %d\n" , stock->best_sell);
                                                                    . 
    free(stock);                // de-allocate manually             .     free(stock);                // de-allocate manually
}                                                                   . }
stock->data_file: (nil)                                             . stock->data_file: (nil)
stock->count:     -1                                                . stock->count:     -1
stock->prices:    (nil)                                             . stock->prices:    (nil)
stock->lo_index:  -1                                                . stock->lo_index:  -1
stock->hi_index:  -1                                                . stock->hi_index:  -1
stock->best_buy:  -1                                                . stock->best_buy:  -1
stock->best_sell: -1                                                . stock->best_sell: -1

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_new
which may be pasted onto a command line to run it.

```
==443611== Memcheck, a memory error detector
==443611== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443611== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443611== Command: ./test_stock_funcs stock_new
==443611== 
==443611== 
==443611== HEAP SUMMARY:
==443611==     in use at exit: 0 bytes in 0 blocks
==443611==   total heap usage: 1 allocs, 1 frees, 40 bytes allocated
==443611== 
==443611== All heap blocks were freed -- no leaks are possible
==443611== 
==443611== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
