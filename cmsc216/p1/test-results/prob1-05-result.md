(TEST 5) stock_free4 : ok
=========================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_free4
---------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_free4
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
    // Tests whether stock_free() correctly free()'s the 'data_file' .     // Tests whether stock_free() correctly free()'s the 'data_file'
    // and 'prices' fields if they are non-NULL.                     .     // and 'prices' fields if they are non-NULL.
                                                                     . 
    printf("Allocating with stock_new()\n");                         .     printf("Allocating with stock_new()\n");
    stock_t *stock = stock_new(); // call function to allocate/init  .     stock_t *stock = stock_new(); // call function to allocate/init
                                                                     . 
    printf("Assigning prices field fresh memory\n");                 .     printf("Assigning prices field fresh memory\n");
    stock->prices = malloc(sizeof(double) * 5);                      .     stock->prices = malloc(sizeof(double) * 5);
                                                                     . 
    printf("Assigning data_file field fresh memory\n");              .     printf("Assigning data_file field fresh memory\n");
    stock->data_file = strdup("another-file-name-of-some-sort.txt"); .     stock->data_file = strdup("another-file-name-of-some-sort.txt");
                                                                     . 
    printf("De-allocating with stock_free()\n");                     .     printf("De-allocating with stock_free()\n");
    stock_free(stock);                                               .     stock_free(stock);
                                                                     . 
    printf("Complete\n");                                            .     printf("Complete\n");
}                                                                    . }
Allocating with stock_new()                                          . Allocating with stock_new()
Assigning prices field fresh memory                                  . Assigning prices field fresh memory
Assigning data_file field fresh memory                               . Assigning data_file field fresh memory
De-allocating with stock_free()                                      . De-allocating with stock_free()
Complete                                                             . Complete

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_free4
which may be pasted onto a command line to run it.

```
==443615== Memcheck, a memory error detector
==443615== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443615== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443615== Command: ./test_stock_funcs stock_free4
==443615== 
==443615== 
==443615== HEAP SUMMARY:
==443615==     in use at exit: 0 bytes in 0 blocks
==443615==   total heap usage: 3 allocs, 3 frees, 115 bytes allocated
==443615== 
==443615== All heap blocks were freed -- no leaks are possible
==443615== 
==443615== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
