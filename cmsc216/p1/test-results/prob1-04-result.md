(TEST 4) stock_free3 : ok
=========================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_free3
---------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_free3
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                                ===ACTUAL===
{                                                                         . {
    // Tests whether stock_free() correctly free()'s the 'prices' field   .     // Tests whether stock_free() correctly free()'s the 'prices' field
    // if it is set after using stock_new(). Valgrind will report         .     // if it is set after using stock_new(). Valgrind will report
    // leaked memory if free() is not called on 'stock->prices'.          .     // leaked memory if free() is not called on 'stock->prices'.
                                                                          . 
    printf("Allocating with stock_new()\n");                              .     printf("Allocating with stock_new()\n");
    stock_t *stock = stock_new(); // call function to allocate/init       .     stock_t *stock = stock_new(); // call function to allocate/init
                                                                          . 
    printf("Assigning prices field fresh memory\n");                      .     printf("Assigning prices field fresh memory\n");
    stock->prices = malloc(sizeof(double) * 5);                           .     stock->prices = malloc(sizeof(double) * 5);
    double prices[5] = {10.0, 5.0, 15.0, 20.0, 5.0};                      .     double prices[5] = {10.0, 5.0, 15.0, 20.0, 5.0};
    memcpy(stock->prices, prices, sizeof(double)*5);  // copies to prices .     memcpy(stock->prices, prices, sizeof(double)*5);  // copies to prices
                                                                          . 
    printf("De-allocating with stock_free()\n");                          .     printf("De-allocating with stock_free()\n");
    stock_free(stock);                                                    .     stock_free(stock);
                                                                          . 
    printf("Complete\n");                                                 .     printf("Complete\n");
}                                                                         . }
Allocating with stock_new()                                               . Allocating with stock_new()
Assigning prices field fresh memory                                       . Assigning prices field fresh memory
De-allocating with stock_free()                                           . De-allocating with stock_free()
Complete                                                                  . Complete

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_free3
which may be pasted onto a command line to run it.

```
==443614== Memcheck, a memory error detector
==443614== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443614== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443614== Command: ./test_stock_funcs stock_free3
==443614== 
==443614== 
==443614== HEAP SUMMARY:
==443614==     in use at exit: 0 bytes in 0 blocks
==443614==   total heap usage: 2 allocs, 2 frees, 80 bytes allocated
==443614== 
==443614== All heap blocks were freed -- no leaks are possible
==443614== 
==443614== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
