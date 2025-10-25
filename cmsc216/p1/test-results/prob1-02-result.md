(TEST 2) stock_free1 : ok
=========================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_free1
---------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_free1
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
    // Tests stock_free() function and whether it frees a stock     .     // Tests stock_free() function and whether it frees a stock
    // allocated by stock_new() correctly                           .     // allocated by stock_new() correctly
                                                                    . 
    printf("Allocating with stock_new()\n");                        .     printf("Allocating with stock_new()\n");
    stock_t *stock = stock_new(); // call function to allocate/init .     stock_t *stock = stock_new(); // call function to allocate/init
                                                                    . 
    if(stock == NULL){                                              .     if(stock == NULL){
      printf("ERROR: got a NULL pointer from stock_new()\n");       .       printf("ERROR: got a NULL pointer from stock_new()\n");
    }                                                               .     }
    else{                                                           .     else{
      printf("De-allocating with stock_free()\n");                  .       printf("De-allocating with stock_free()\n");
      stock_free(stock);                                            .       stock_free(stock);
      printf("Complete\n");                                         .       printf("Complete\n");
    }                                                               .     }
}                                                                   . }
Allocating with stock_new()                                         . Allocating with stock_new()
De-allocating with stock_free()                                     . De-allocating with stock_free()
Complete                                                            . Complete

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_free1
which may be pasted onto a command line to run it.

```
==443613== Memcheck, a memory error detector
==443613== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443613== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443613== Command: ./test_stock_funcs stock_free1
==443613== 
==443613== 
==443613== HEAP SUMMARY:
==443613==     in use at exit: 0 bytes in 0 blocks
==443613==   total heap usage: 1 allocs, 1 frees, 40 bytes allocated
==443613== 
==443613== All heap blocks were freed -- no leaks are possible
==443613== 
==443613== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
