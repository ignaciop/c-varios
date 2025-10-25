(TEST 3) stock_multimain 12 Two Stocks Unequal Length : ok
==========================================================

COMMENTS
--------
Runs the ~stock_multimain~ program on a two input files to see if the
correct output is produced. The input files have different lengths so
some ending columns for one stock will be blank while the other stock
has bars.

PROGRAM: ./stock_multimain 20 data/stock-jagged.txt data/stock-ascending.txt
----------------------------------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./stock_multimain 20 data/stock-jagged.txt data/stock-ascending.txt
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
max_height:  20                             . max_height: 20
stop_count:  15                             . stop_count: 15
min price:   10.00                          . min price: 10.00
max price:   270.00                         . max price: 270.00
price range: 260.00                         . price range: 260.00
plot step:   13.00                          . plot step: 13.00
==LEGEND==                                  . ==LEGEND==
a : data/stock-jagged.txt                   . a : data/stock-jagged.txt
b : data/stock-ascending.txt                . b : data/stock-ascending.txt
                                            ( 
           +------------------------------+ .            +------------------------------+
    257.00 |                      A       | .     257.00 |                      A       |
    244.00 |  a                 a A       | .     244.00 |  a                 a A       |
    231.00 |  a         a       a A       | .     231.00 |  a         a       a A       |
    218.00 |  a         a       a A       | .     218.00 |  a         a       a A       |
    205.00 |  a         a       a A       | .     205.00 |  a         a       a A       |
    192.00 |  a         a       a A       | .     192.00 |  a         a       a A       |
    179.00 |  a         a       a A       | .     179.00 |  a         a       a A       |
    166.00 |  a     a   a       a A       | .     166.00 |  a     a   a       a A       |
    153.00 |  a     a   a       a A       | .     153.00 |  a     a   a       a A       |
    140.00 |  a   a a   a       a A       | .     140.00 |  a   a a   a       a A       |
    127.00 |  a a a a   a       a A       | .     127.00 |  a a a a   a       a A       |
    114.00 |  a a a a   a       a A       | .     114.00 |  a a a a   a       a A       |
    101.00 |a a a a a   a       a A     a | .     101.00 |a a a a a   a       a A     a |
     88.00 |a a a a a a a    b Ba A     a | .      88.00 |a a a a a a a    b Ba A     a |
     75.00 |a a a a a a a  b b Ba A     a | .      75.00 |a a a a a a a  b b Ba A     a |
     62.00 |a a a a a a ab b b Ba A   a a | .      62.00 |a a a a a a ab b b Ba A   a a |
     49.00 |a a a a abababab b Ba A a a a | .      49.00 |a a a a abababab b Ba A a a a |
     36.00 |a a a abababababAbaBa A a a a | .      36.00 |a a a abababababAbaBa A a a a |
     23.00 |a a ababababababAbaBa A a a a | .      23.00 |a a ababababababAbaBa A a a a |
     10.00 |aBabababababababAbaBa A a a a | .      10.00 |aBabababababababAbaBa A a a a |
           +^---------^---------^---------+ .            +^---------^---------^---------+
            0         5         10          .             0         5         10        

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./stock_multimain 20 data/stock-jagged.txt data/stock-ascending.txt
which may be pasted onto a command line to run it.

```
==443887== Memcheck, a memory error detector
==443887== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443887== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443887== Command: ./stock_multimain 20 data/stock-jagged.txt data/stock-ascending.txt
==443887== 
==443887== 
==443887== HEAP SUMMARY:
==443887==     in use at exit: 0 bytes in 0 blocks
==443887==   total heap usage: 18 allocs, 18 frees, 18,678 bytes allocated
==443887== 
==443887== All heap blocks were freed -- no leaks are possible
==443887== 
==443887== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
