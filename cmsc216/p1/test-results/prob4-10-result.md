(TEST 10) stock_multimain open fail 2 : ok
==========================================

COMMENTS
--------
Checks that stock_multimain properly handles the case where a file
among the stock cannot be opened. Ensures that an error message is
printed and that memory is de-allocated before returning and exit code
of 1. In this case the missing file is in the middle of the requested
files so that any loaded files must be de-allocated before reporting
the loading function returns.

PROGRAM: ./stock_multimain 15 data/s01.txt data/s02.txt data/s03.txt data/notaround.txt data/s05.txt
----------------------------------------------------------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./stock_multimain 15 data/s01.txt data/s02.txt data/s03.txt data/notaround.txt data/s05.txt
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                             ===ACTUAL===
Could not open file 'data/notaround.txt', cannot count lines           . Could not open file 'data/notaround.txt', cannot count lines
Unable to open stock file 'data/notaround.txt', cannot load stock data . Unable to open stock file 'data/notaround.txt', cannot load stock data
Failed to load stock file 3                                            . Failed to load stock file 3
Problems loading all stock files, exiting                              . Problems loading all stock files, exiting

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./stock_multimain 15 data/s01.txt data/s02.txt data/s03.txt data/notaround.txt data/s05.txt
which may be pasted onto a command line to run it.

```
==443896== Memcheck, a memory error detector
==443896== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443896== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443896== Command: ./stock_multimain 15 data/s01.txt data/s02.txt data/s03.txt data/notaround.txt data/s05.txt
==443896== 
==443896== 
==443896== HEAP SUMMARY:
==443896==     in use at exit: 0 bytes in 0 blocks
==443896==   total heap usage: 31 allocs, 31 frees, 28,942 bytes allocated
==443896== 
==443896== All heap blocks were freed -- no leaks are possible
==443896== 
==443896== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
