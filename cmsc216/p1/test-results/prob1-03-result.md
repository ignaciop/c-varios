(TEST 3) stock_free2 : ok
=========================

COMMENTS
--------


PROGRAM: ./test_stock_funcs stock_free2
---------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs stock_free2
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
    // field if it is set after using stock_new(). Valgrind will     .     // field if it is set after using stock_new(). Valgrind will
    // report leaked memory if free() is not called on               .     // report leaked memory if free() is not called on
    // 'stock->data_file'.                                           .     // 'stock->data_file'.
                                                                     . 
    printf("Allocating with stock_new()\n");                         .     printf("Allocating with stock_new()\n");
    stock_t *stock = stock_new(); // call function to allocate/init  .     stock_t *stock = stock_new(); // call function to allocate/init
                                                                     . 
    printf("Assigning data_file field fresh memory\n");              .     printf("Assigning data_file field fresh memory\n");
    stock->data_file = malloc(sizeof(char) * 20);                    .     stock->data_file = malloc(sizeof(char) * 20);
    strcpy(stock->data_file, "some-file-name.txt");                  .     strcpy(stock->data_file, "some-file-name.txt");
                                                                     . 
    printf("De-allocating with stock_free()\n");                     .     printf("De-allocating with stock_free()\n");
    stock_free(stock);                                               .     stock_free(stock);
                                                                     . 
    printf("Complete\n");                                            .     printf("Complete\n");
}                                                                    . }
Allocating with stock_new()                                          . Allocating with stock_new()
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
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_free2
which may be pasted onto a command line to run it.

```
==443612== Memcheck, a memory error detector
==443612== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443612== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443612== Command: ./test_stock_funcs stock_free2
==443612== 
==443612== 
==443612== HEAP SUMMARY:
==443612==     in use at exit: 0 bytes in 0 blocks
==443612==   total heap usage: 2 allocs, 2 frees, 60 bytes allocated
==443612== 
==443612== All heap blocks were freed -- no leaks are possible
==443612== 
==443612== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
