(TEST 2) stock_multimain 15 Two Stocks Equal Length : ok
========================================================

COMMENTS
--------
Runs the ~stock_multimain~ program on a two input files to see if the
correct output is produced. The input files have the same length so
all columns of plotting will be filled with all stocks.

PROGRAM: ./stock_multimain 15 data/stock-jagged.txt data/stock-min-after-max.txt
--------------------------------------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./stock_multimain 15 data/stock-jagged.txt data/stock-min-after-max.txt
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                  ===ACTUAL===
==MULTIPLOT DATA==                          . ==MULTIPLOT DATA==
max_height:  15                             . max_height: 15
stop_count:  15                             . stop_count: 15
min price:   14.00                          . min price: 14.00
max price:   323.00                         . max price: 323.00
price range: 309.00                         . price range: 309.00
plot step:   20.60                          . plot step: 20.60
==LEGEND==                                  . ==LEGEND==
a : data/stock-jagged.txt                   . a : data/stock-jagged.txt
b : data/stock-min-after-max.txt            . b : data/stock-min-after-max.txt
                                            ( 
           +------------------------------+ .            +------------------------------+
    302.40 |         B       b            | .     302.40 |         B       b            |
    281.80 |   b     B       b            | .     281.80 |   b     B       b            |
    261.20 |   b     B       b    A       | .     261.20 |   b     B       b    A       |
    240.60 |  ab     B       b  a A       | .     240.60 |  ab     B       b  a A       |
    220.00 | bab     B  a    b  a A       | .     220.00 | bab     B  a    b  a A       |
    199.40 | bab     B  ab   b  a A       | .     199.40 | bab     B  ab   b  a A       |
    178.80 | bab     B bab   b  a Ab      | .     178.80 | bab     B bab   b  a Ab      |
    158.20 | bab    aB bab   b  a Ab b   b| .     158.20 | bab    aB bab   b  a Ab b   b|
    137.60 | bab  a aB bab b b  a Ab b b b| .     137.60 | bab  a aB bab b b  a Ab b b b|
    117.00 | baba a aB bab b b  a Ab b b b| .     117.00 | baba a aB bab b b  a Ab b b b|
     96.40 |ababa a aB bab b b  a Ab b bab| .      96.40 |ababa a aB bab b b  a Ab b bab|
     75.80 |ababa abaBabab b b ba Ab b bab| .      75.80 |ababa abaBabab b b ba Ab b bab|
     55.20 |ababa abaBababab b ba Abababab| .      55.20 |ababa abaBababab b ba Abababab|
     34.60 |ababa abaBabababAbaba Abababab| .      34.60 |ababa abaBabababAbaba Abababab|
     14.00 |ababababaBabababAbabaBAbababab| .      14.00 |ababababaBabababAbabaBAbababab|
           +^---------^---------^---------+ .            +^---------^---------^---------+
            0         5         10          .             0         5         10        

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./stock_multimain 15 data/stock-jagged.txt data/stock-min-after-max.txt
which may be pasted onto a command line to run it.

```
==443888== Memcheck, a memory error detector
==443888== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443888== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443888== Command: ./stock_multimain 15 data/stock-jagged.txt data/stock-min-after-max.txt
==443888== 
==443888== 
==443888== HEAP SUMMARY:
==443888==     in use at exit: 0 bytes in 0 blocks
==443888==   total heap usage: 18 allocs, 18 frees, 18,726 bytes allocated
==443888== 
==443888== All heap blocks were freed -- no leaks are possible
==443888== 
==443888== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
