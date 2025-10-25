(TEST 5) stock_multimain 20 Apple and Google 10 day : ok
========================================================

COMMENTS
--------
Runs the ~stock_multimain~ program on a two actual company stock files
to see if the correct output is produced. All files have the same
length in this case.

PROGRAM: ./stock_multimain 20 data/stock-daily12-aapl_us_d.txt data/stock-daily12-googl_us_d.txt
------------------------------------------------------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./stock_multimain 20 data/stock-daily12-aapl_us_d.txt data/stock-daily12-googl_us_d.txt
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                 ===ACTUAL===
==MULTIPLOT DATA==                         . ==MULTIPLOT DATA==
max_height:  20                            . max_height: 20
stop_count:  12                            . stop_count: 12
min price:   199.32                        . min price: 199.32
max price:   233.33                        . max price: 233.33
price range: 34.01                         . price range: 34.01
plot step:   1.70                          . plot step: 1.70
==LEGEND==                                 . ==LEGEND==
a : data/stock-daily12-aapl_us_d.txt       . a : data/stock-daily12-aapl_us_d.txt
b : data/stock-daily12-googl_us_d.txt      . b : data/stock-daily12-googl_us_d.txt
                                           ( 
           +------------------------+      .            +------------------------+
    231.63 |  A a                   |      .     231.63 |  A a                   |
    229.93 |  A a a a a           a |      .     229.93 |  A a a a a           a |
    228.23 |a A a a a a         a a |      .     228.23 |a A a a a a         a a |
    226.53 |a A a a a a     a a a a |      .     226.53 |a A a a a a     a a a a |
    224.83 |a A a a a a a A a a a a |      .     224.83 |a A a a a a a A a a a a |
    223.13 |a A a a a a a A a a a a |      .     223.13 |a A a a a a a A a a a a |
    221.43 |a A a a a a a A a a a a |      .     221.43 |a A a a a a a A a a a a |
    219.73 |a A a a a a a A a a a a |      .     219.73 |a A a a a a a A a a a a |
    218.03 |a A a a a a a A a a a a |      .     218.03 |a A a a a a a A a a a a |
    216.32 |a A a a a a a A a a a a |      .     216.32 |a A a a a a a A a a a a |
    214.62 |a A a a a a a A a a a a |      .     214.62 |a A a a a a a A a a a a |
    212.92 |a A a a a a a A a a a a |      .     212.92 |a A a a a a a A a a a a |
    211.22 |a A a a a a a A a a a a |      .     211.22 |a A a a a a a A a a a a |
    209.52 |a A a a a a a A a a a a |      .     209.52 |a A a a a a a A a a a a |
    207.82 |a A a a a a a A a aBa a |      .     207.82 |a A a a a a a A a aBa a |
    206.12 |a A a a a a a A a aBabab|      .     206.12 |a A a a a a a A a aBabab|
    204.42 |a A a a a a a A abaBabab|      .     204.42 |a A a a a a a A abaBabab|
    202.72 |abA abababa a A abaBabab|      .     202.72 |abA abababa a A abaBabab|
    201.02 |abAbababababa A abaBabab|      .     201.02 |abAbababababa A abaBabab|
    199.32 |abAbababababaBAbabaBabab|      .     199.32 |abAbababababaBAbabaBabab|
           +^---------^---------^---+      .            +^---------^---------^---+
            0         5         10         .             0         5         10        

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./stock_multimain 20 data/stock-daily12-aapl_us_d.txt data/stock-daily12-googl_us_d.txt
which may be pasted onto a command line to run it.

```
==443891== Memcheck, a memory error detector
==443891== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443891== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443891== Command: ./stock_multimain 20 data/stock-daily12-aapl_us_d.txt data/stock-daily12-googl_us_d.txt
==443891== 
==443891== 
==443891== HEAP SUMMARY:
==443891==     in use at exit: 0 bytes in 0 blocks
==443891==   total heap usage: 18 allocs, 18 frees, 18,710 bytes allocated
==443891== 
==443891== All heap blocks were freed -- no leaks are possible
==443891== 
==443891== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
