(TEST 2) stock_main fail to open : ok
=====================================

COMMENTS
--------
Runs on a stock file that does not exist.  This will lead to and error
and exit. Note there are 3 separate error messages complaining
1. From count_lines() in stock_funcs.c
2. From stock_load() in stock_funcs.c
3. From main() in stock_main.c

PROGRAM: ./stock_main data/does-not-exist.txt 20
------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./stock_main data/does-not-exist.txt 20
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                                  ===ACTUAL===
Could not open file 'data/does-not-exist.txt', cannot count lines           . Could not open file 'data/does-not-exist.txt', cannot count lines
Unable to open stock file 'data/does-not-exist.txt', cannot load stock data . Unable to open stock file 'data/does-not-exist.txt', cannot load stock data
Failed to load stock file, exiting                                          . Failed to load stock file, exiting

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./stock_main data/does-not-exist.txt 20
which may be pasted onto a command line to run it.

```
==443833== Memcheck, a memory error detector
==443833== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443833== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443833== Command: ./stock_main data/does-not-exist.txt 20
==443833== 
==443833== 
==443833== HEAP SUMMARY:
==443833==     in use at exit: 0 bytes in 0 blocks
==443833==   total heap usage: 3 allocs, 3 frees, 984 bytes allocated
==443833== 
==443833== All heap blocks were freed -- no leaks are possible
==443833== 
==443833== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
