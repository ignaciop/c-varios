(TEST 6) stock_multimain 20 4 company 10 day : ok
=================================================

COMMENTS
--------
Runs the ~stock_multimain~ program on a four actual company stock
files to see if the correct output is produced.  All files have the
same length in this case.

PROGRAM: ./stock_multimain 20 data/stock-daily10-aapl_us_d.txt data/stock-daily10-googl_us_d.txt data/stock-daily10-nvda_us_d.txt data/stock-daily10-meta_us_d.txt
------------------------------------------------------------------------------------------------------------------------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./stock_multimain 20 data/stock-daily10-aapl_us_d.txt data/stock-daily10-googl_us_d.txt data/stock-daily10-nvda_us_d.txt data/stock-daily10-meta_us_d.txt
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                            ===ACTUAL===
==MULTIPLOT DATA==                                    . ==MULTIPLOT DATA==
max_height:  20                                       . max_height: 20
stop_count:  10                                       . stop_count: 10
min price:   174.98                                   . min price: 174.98
max price:   790.00                                   . max price: 790.00
price range: 615.02                                   . price range: 615.02
plot step:   30.75                                    . plot step: 30.75
==LEGEND==                                            . ==LEGEND==
a : data/stock-daily10-aapl_us_d.txt                  . a : data/stock-daily10-aapl_us_d.txt
b : data/stock-daily10-googl_us_d.txt                 . b : data/stock-daily10-googl_us_d.txt
c : data/stock-daily10-nvda_us_d.txt                  . c : data/stock-daily10-nvda_us_d.txt
d : data/stock-daily10-meta_us_d.txt                  . d : data/stock-daily10-meta_us_d.txt
                                                      ( 
           +----------------------------------------+ .            +----------------------------------------+
    759.25 |   D   d   d   d   d                    | .     759.25 |   D   d   d   d   d                    |
    728.50 |   D   d   d   d   d   d   d   D   d   d| .     728.50 |   D   d   d   d   d   d   d   D   d   d|
    697.75 |   D   d   d   d   d   d   d   D   d   d| .     697.75 |   D   d   d   d   d   d   d   D   d   d|
    667.00 |   D   d   d   d   d   d   d   D   d   d| .     667.00 |   D   d   d   d   d   d   d   D   d   d|
    636.25 |   D   d   d   d   d   d   d   D   d   d| .     636.25 |   D   d   d   d   d   d   d   D   d   d|
    605.49 |   D   d   d   d   d   d   d   D   d   d| .     605.49 |   D   d   d   d   d   d   d   D   d   d|
    574.74 |   D   d   d   d   d   d   d   D   d   d| .     574.74 |   D   d   d   d   d   d   d   D   d   d|
    543.99 |   D   d   d   d   d   d   d   D   d   d| .     543.99 |   D   d   d   d   d   d   d   D   d   d|
    513.24 |   D   d   d   d   d   d   d   D   d   d| .     513.24 |   D   d   d   d   d   d   d   D   d   d|
    482.49 |   D   d   d   d   d   d   d   D   d   d| .     482.49 |   D   d   d   d   d   d   d   D   d   d|
    451.74 |   D   d   d   d   d   d   d   D   d   d| .     451.74 |   D   d   d   d   d   d   d   D   d   d|
    420.99 |   D   d   d   d   d   d   d   D   d   d| .     420.99 |   D   d   d   d   d   d   d   D   d   d|
    390.24 |   D   d   d   d   d   d   d   D   d   d| .     390.24 |   D   d   d   d   d   d   d   D   d   d|
    359.49 |   D   d   d   d   d   d   d   D   d   d| .     359.49 |   D   d   d   d   d   d   d   D   d   d|
    328.74 |   D   d   d   d   d   d   d   D   d   d| .     328.74 |   D   d   d   d   d   d   d   D   d   d|
    297.98 |   D   d   d   d   d   d   d   D   d   d| .     297.98 |   D   d   d   d   d   d   d   D   d   d|
    267.23 |   D   d   d   d   d   d   d   D   d   d| .     267.23 |   D   d   d   d   d   d   d   D   d   d|
    236.48 |   D   d   d   d   d   d   d   D   d   d| .     236.48 |   D   d   d   d   d   d   d   D   d   d|
    205.73 |a  DA  da  da  da  da  da  dA  Dab daB d| .     205.73 |a  DA  da  da  da  da  da  dA  Dab daB d|
    174.98 |abCDAbcdabcdabcdabcdabcdaBcdAbCDabcdaBcd| .     174.98 |abCDAbcdabcdabcdabcdabcdaBcdAbCDabcdaBcd|
           +^-------------------^-------------------+ .            +^-------------------^-------------------+
            0                   5                     .             0                   5                   

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./stock_multimain 20 data/stock-daily10-aapl_us_d.txt data/stock-daily10-googl_us_d.txt data/stock-daily10-nvda_us_d.txt data/stock-daily10-meta_us_d.txt
which may be pasted onto a command line to run it.

```
==443892== Memcheck, a memory error detector
==443892== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443892== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443892== Command: ./stock_multimain 20 data/stock-daily10-aapl_us_d.txt data/stock-daily10-googl_us_d.txt data/stock-daily10-nvda_us_d.txt data/stock-daily10-meta_us_d.txt
==443892== 
==443892== 
==443892== HEAP SUMMARY:
==443892==     in use at exit: 0 bytes in 0 blocks
==443892==   total heap usage: 34 allocs, 34 frees, 37,354 bytes allocated
==443892== 
==443892== All heap blocks were freed -- no leaks are possible
==443892== 
==443892== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
