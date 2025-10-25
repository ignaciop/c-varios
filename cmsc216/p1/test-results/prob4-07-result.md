(TEST 7) stock_multimain 25 3 company varied day : ok
=====================================================

COMMENTS
--------
Runs the ~stock_multimain~ program on a three actual company stock
files to see if the correct output is produced.  The files have
different lengths so that some plot bars will be blank for some
companies at the end of the plot.

PROGRAM: ./stock_multimain 20 data/stock-daily8-aapl_us_d.txt data/stock-daily12-googl_us_d.txt data/stock-daily10-nvda_us_d.txt
--------------------------------------------------------------------------------------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./stock_multimain 20 data/stock-daily8-aapl_us_d.txt data/stock-daily12-googl_us_d.txt data/stock-daily10-nvda_us_d.txt
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                ===ACTUAL===
==MULTIPLOT DATA==                                        . ==MULTIPLOT DATA==
max_height:  20                                           . max_height: 20
stop_count:  12                                           . stop_count: 12
min price:   174.98                                       . min price: 174.98
max price:   233.33                                       . max price: 233.33
price range: 58.35                                        . price range: 58.35
plot step:   2.92                                         . plot step: 2.92
==LEGEND==                                                . ==LEGEND==
a : data/stock-daily8-aapl_us_d.txt                       . a : data/stock-daily8-aapl_us_d.txt
b : data/stock-daily12-googl_us_d.txt                     . b : data/stock-daily12-googl_us_d.txt
c : data/stock-daily10-nvda_us_d.txt                      . c : data/stock-daily10-nvda_us_d.txt
                                                          ( 
           +------------------------------------+         .            +------------------------------------+
    230.41 |   A  a  a  a  a                    |         .     230.41 |   A  a  a  a  a                    |
    227.50 |a  A  a  a  a  a                    |         .     227.50 |a  A  a  a  a  a                    |
    224.58 |a  A  a  a  a  a  a  A              |         .     224.58 |a  A  a  a  a  a  a  A              |
    221.66 |a  A  a  a  a  a  a  A              |         .     221.66 |a  A  a  a  a  a  a  A              |
    218.74 |a  A  a  a  a  a  a  A              |         .     218.74 |a  A  a  a  a  a  a  A              |
    215.83 |a  A  a  a  a  a  a  A              |         .     215.83 |a  A  a  a  a  a  a  A              |
    212.91 |a  A  a  a  a  a  a  A              |         .     212.91 |a  A  a  a  a  a  a  A              |
    209.99 |a  A  a  a  a  a  a  A              |         .     209.99 |a  A  a  a  a  a  a  A              |
    207.07 |a  A  a  a  a  a  a  A      B  b  b |         .     207.07 |a  A  a  a  a  a  a  A      B  b  b |
    204.16 |a  A  a  a  a  a  a  A   b  B  b  b |         .     204.16 |a  A  a  a  a  a  a  A   b  B  b  b |
    201.24 |ab Ab ab ab ab ab a  A   b  B  b  b |         .     201.24 |ab Ab ab ab ab ab a  A   b  B  b  b |
    198.32 |ab Ab ab ab ab ab aB Ab  b  B  b  b |         .     198.32 |ab Ab ab ab ab ab aB Ab  b  B  b  b |
    195.40 |ab Ab ab ab ab ab aB Ab  b  B  b  b |         .     195.40 |ab Ab ab ab ab ab aB Ab  b  B  b  b |
    192.49 |ab Ab ab ab ab ab aB Ab  b  B  b  b |         .     192.49 |ab Ab ab ab ab ab aB Ab  b  B  b  b |
    189.57 |ab Ab ab ab ab ab aB Ab  b  B  b  b |         .     189.57 |ab Ab ab ab ab ab aB Ab  b  B  b  b |
    186.65 |ab Ab ab ab ab ab aB Ab  b  B  b  b |         .     186.65 |ab Ab ab ab ab ab aB Ab  b  B  b  b |
    183.73 |ab Ab ab ab ab ab aB Ab  b  B  b  b |         .     183.73 |ab Ab ab ab ab ab aB Ab  b  B  b  b |
    180.81 |abCAbcabcab abcab aB Ab  b  B  b  b |         .     180.81 |abCAbcabcab abcab aB Ab  b  B  b  b |
    177.90 |abCAbcabcabcabcab aB Ab  bc Bc b  b |         .     177.90 |abCAbcabcabcabcab aB Ab  bc Bc b  b |
    174.98 |abCAbcabcabcabcabcaBcAbC bc Bc b  b |         .     174.98 |abCAbcabcabcabcabcaBcAbC bc Bc b  b |
           +^--------------^--------------^-----+         .            +^--------------^--------------^-----+
            0              5              10              .             0              5              10             

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./stock_multimain 20 data/stock-daily8-aapl_us_d.txt data/stock-daily12-googl_us_d.txt data/stock-daily10-nvda_us_d.txt
which may be pasted onto a command line to run it.

```
==443893== Memcheck, a memory error detector
==443893== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443893== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443893== Command: ./stock_multimain 20 data/stock-daily8-aapl_us_d.txt data/stock-daily12-googl_us_d.txt data/stock-daily10-nvda_us_d.txt
==443893== 
==443893== 
==443893== HEAP SUMMARY:
==443893==     in use at exit: 0 bytes in 0 blocks
==443893==   total heap usage: 26 allocs, 26 frees, 28,014 bytes allocated
==443893== 
==443893== All heap blocks were freed -- no leaks are possible
==443893== 
==443893== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
