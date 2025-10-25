(TEST 9) stock_multimain open fail 1 : ok
=========================================

COMMENTS
--------
Checks that stock_multimain properly handles the case where a file
among the stock cannot be opened. Ensures that an error message is
printed and that memory is de-allocated before returning and exit code
of 1. In this case the missing file is the first file mentioned.

PROGRAM: ./stock_multimain 15 data/no-such-file.txt data/s02.txt data/s03.txt data/s04.txt
------------------------------------------------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./stock_multimain 15 data/no-such-file.txt data/s02.txt data/s03.txt data/s04.txt
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                                ===ACTUAL===
Could not open file 'data/no-such-file.txt', cannot count lines           . Could not open file 'data/no-such-file.txt', cannot count lines
Unable to open stock file 'data/no-such-file.txt', cannot load stock data . Unable to open stock file 'data/no-such-file.txt', cannot load stock data
Failed to load stock file 0                                               . Failed to load stock file 0
Problems loading all stock files, exiting                                 . Problems loading all stock files, exiting

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./stock_multimain 15 data/no-such-file.txt data/s02.txt data/s03.txt data/s04.txt
which may be pasted onto a command line to run it.

```
==443895== Memcheck, a memory error detector
==443895== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443895== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443895== Command: ./stock_multimain 15 data/no-such-file.txt data/s02.txt data/s03.txt data/s04.txt
==443895== 
==443895== 
==443895== HEAP SUMMARY:
==443895==     in use at exit: 0 bytes in 0 blocks
==443895==   total heap usage: 9 allocs, 9 frees, 1,109 bytes allocated
==443895== 
==443895== All heap blocks were freed -- no leaks are possible
==443895== 
==443895== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
