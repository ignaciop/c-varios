(TEST 4) stock_multimain 13 Three Stocks Unequal Length : ok
============================================================

COMMENTS
--------
Runs the ~stock_multimain~ program on a three input files to see if
the correct output is produced. The input files have different lengths
so some ending columns for one stock will be blank while the other
stock has bars.

PROGRAM: ./stock_multimain 20 data/stock-valley.txt data/stock-jagged.txt data/stock-ascending.txt
--------------------------------------------------------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./stock_multimain 20 data/stock-valley.txt data/stock-jagged.txt data/stock-ascending.txt
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                 ===ACTUAL===
==MULTIPLOT DATA==                                         . ==MULTIPLOT DATA==
max_height:  20                                            . max_height: 20
stop_count:  15                                            . stop_count: 15
min price:   10.00                                         . min price: 10.00
max price:   270.00                                        . max price: 270.00
price range: 260.00                                        . price range: 260.00
plot step:   13.00                                         . plot step: 13.00
==LEGEND==                                                 . ==LEGEND==
a : data/stock-valley.txt                                  . a : data/stock-valley.txt
b : data/stock-jagged.txt                                  . b : data/stock-jagged.txt
c : data/stock-ascending.txt                               . c : data/stock-ascending.txt
                                                           ( 
           +---------------------------------------------+ .            +---------------------------------------------+
    257.00 |                                  B          | .     257.00 |                                  B          |
    244.00 |    b                          b  B          | .     244.00 |    b                          b  B          |
    231.00 |    b              b           b  B          | .     231.00 |    b              b           b  B          |
    218.00 |    b              b           b  B          | .     218.00 |    b              b           b  B          |
    205.00 |    b              b           b  B          | .     205.00 |    b              b           b  B          |
    192.00 |    b              b           b  B          | .     192.00 |    b              b           b  B          |
    179.00 |    b              b           b  B          | .     179.00 |    b              b           b  B          |
    166.00 |    b        b     b           b  B          | .     166.00 |    b        b     b           b  B          |
    153.00 |    b        b     b           b  B          | .     153.00 |    b        b     b           b  B          |
    140.00 |    b     b  b     b           b  B          | .     140.00 |    b     b  b     b           b  B          |
    127.00 |    b  b  b  b     b           b  B          | .     127.00 |    b  b  b  b     b           b  B          |
    114.00 |    b  b  b  b     b           b  B          | .     114.00 |    b  b  b  b     b           b  B          |
    101.00 | b  b  b  b  b     b           b AB        b | .     101.00 | b  b  b  b  b     b           b AB        b |
     88.00 |ab ab  b  b  b  b  b      c  Cab AB        b | .      88.00 |ab ab  b  b  b  b  b      c  Cab AB        b |
     75.00 |ab ab ab  b  b  b  b   ca ca Cab AB        b | .      75.00 |ab ab ab  b  b  b  b   ca ca Cab AB        b |
     62.00 |ab ab ab ab  b  b  bca ca ca Cab AB     b  b | .      62.00 |ab ab ab ab  b  b  bca ca ca Cab AB     b  b |
     49.00 |ab ab ab ab abcAbcabcabca ca Cab AB  b  b  b | .      49.00 |ab ab ab ab abcAbcabcabca ca Cab AB  b  b  b |
     36.00 |ab ab ab abcabcAbcabcabcaBcabCab AB  b  b  b | .      36.00 |ab ab ab abcabcAbcabcabcaBcabCab AB  b  b  b |
     23.00 |ab ab abcabcabcAbcabcabcaBcabCab AB  b  b  b | .      23.00 |ab ab abcabcabcAbcabcabcaBcabCab AB  b  b  b |
     10.00 |abCabcabcabcabcAbcabcabcaBcabCab AB  b  b  b | .      10.00 |abCabcabcabcabcAbcabcabcaBcabCab AB  b  b  b |
           +^--------------^--------------^--------------+ .            +^--------------^--------------^--------------+
            0              5              10               .             0              5              10             

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./stock_multimain 20 data/stock-valley.txt data/stock-jagged.txt data/stock-ascending.txt
which may be pasted onto a command line to run it.

```
==443890== Memcheck, a memory error detector
==443890== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443890== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443890== Command: ./stock_multimain 20 data/stock-valley.txt data/stock-jagged.txt data/stock-ascending.txt
==443890== 
==443890== 
==443890== HEAP SUMMARY:
==443890==     in use at exit: 0 bytes in 0 blocks
==443890==   total heap usage: 26 allocs, 26 frees, 28,010 bytes allocated
==443890== 
==443890== All heap blocks were freed -- no leaks are possible
==443890== 
==443890== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
