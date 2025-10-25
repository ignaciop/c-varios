(TEST 8) count_lines : ok
=========================

COMMENTS
--------


PROGRAM: ./test_stock_funcs count_lines
---------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./test_stock_funcs count_lines
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
    // Checks several calls to count_lines() on different files in the .     // Checks several calls to count_lines() on different files in the
    // data/ directory.  This directory must be present with the       .     // data/ directory.  This directory must be present with the
    // provided data files for the tests to work correctly.            .     // provided data files for the tests to work correctly.
    int ret = count_lines("data/stock-3only.txt");                     .     int ret = count_lines("data/stock-3only.txt");
    printf("ret: %d\n", ret);                                          .     printf("ret: %d\n", ret);
}                                                                      . }
ret: 3                                                                 . ret: 3
{                                                                      . {
    int ret = count_lines("data/stock-ascending.txt");                 .     int ret = count_lines("data/stock-ascending.txt");
    printf("ret: %d\n", ret);                                          .     printf("ret: %d\n", ret);
}                                                                      . }
ret: 10                                                                . ret: 10
{                                                                      . {
    int ret = count_lines("data/stock-FB-08-02-2021.txt");             .     int ret = count_lines("data/stock-FB-08-02-2021.txt");
    printf("ret: %d\n", ret);                                          .     printf("ret: %d\n", ret);
}                                                                      . }
ret: 543                                                               . ret: 543
{                                                                      . {
    int ret = count_lines("data/stock-empty.txt");                     .     int ret = count_lines("data/stock-empty.txt");
    printf("ret: %d\n", ret);                                          .     printf("ret: %d\n", ret);
}                                                                      . }
ret: 0                                                                 . ret: 0
{                                                                      . {
    int ret = count_lines("data/not-there.txt");                       .     int ret = count_lines("data/not-there.txt");
    printf("ret: %d\n", ret);                                          .     printf("ret: %d\n", ret);
}                                                                      . }
Could not open file 'data/not-there.txt', cannot count lines           . Could not open file 'data/not-there.txt', cannot count lines
ret: -1                                                                . ret: -1

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs count_lines
which may be pasted onto a command line to run it.

```
==443716== Memcheck, a memory error detector
==443716== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443716== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443716== Command: ./test_stock_funcs count_lines
==443716== 
==443716== 
==443716== HEAP SUMMARY:
==443716==     in use at exit: 0 bytes in 0 blocks
==443716==   total heap usage: 9 allocs, 9 frees, 18,744 bytes allocated
==443716== 
==443716== All heap blocks were freed -- no leaks are possible
==443716== 
==443716== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
