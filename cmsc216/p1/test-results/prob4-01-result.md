(TEST 1) stock_multimain 10 Single Stock : ok
=============================================

COMMENTS
--------
Runs the ~stock_multimain~ program on a the file data/stock-jagged.txt
to see if the correct output is produced. This run is a single stock
rather than multiple stocks

PROGRAM: ./stock_multimain 10 data/stock-jagged.txt
---------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./stock_multimain 10 data/stock-jagged.txt
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                   ===ACTUAL===
==MULTIPLOT DATA==           . ==MULTIPLOT DATA==
max_height:  10              . max_height: 10
stop_count:  15              . stop_count: 15
min price:   38.00           . min price: 38.00
max price:   270.00          . max price: 270.00
price range: 232.00          . price range: 232.00
plot step:   23.20           . plot step: 23.20
==LEGEND==                   . ==LEGEND==
a : data/stock-jagged.txt    . a : data/stock-jagged.txt
                             ( 
           +---------------+ .            +---------------+
    246.80 | a        aA   | .     246.80 | a        aA   |
    223.60 | a    a   aA   | .     223.60 | a    a   aA   |
    200.40 | a    a   aA   | .     200.40 | a    a   aA   |
    177.20 | a    a   aA   | .     177.20 | a    a   aA   |
    154.00 | a  a a   aA   | .     154.00 | a  a a   aA   |
    130.80 | aaaa a   aA   | .     130.80 | aaaa a   aA   |
    107.60 | aaaa a   aA   | .     107.60 | aaaa a   aA   |
     84.40 |aaaaaaa   aA  a| .      84.40 |aaaaaaa   aA  a|
     61.20 |aaaaaaa   aA aa| .      61.20 |aaaaaaa   aA aa|
     38.00 |aaaaaaaaAaaAaaa| .      38.00 |aaaaaaaaAaaAaaa|
           +^----^----^----+ .            +^----^----^----+
            0    5    10     .             0    5    10   

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./stock_multimain 10 data/stock-jagged.txt
which may be pasted onto a command line to run it.

```
==443889== Memcheck, a memory error detector
==443889== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443889== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443889== Command: ./stock_multimain 10 data/stock-jagged.txt
==443889== 
==443889== 
==443889== HEAP SUMMARY:
==443889==     in use at exit: 0 bytes in 0 blocks
==443889==   total heap usage: 10 allocs, 10 frees, 9,356 bytes allocated
==443889== 
==443889== All heap blocks were freed -- no leaks are possible
==443889== 
==443889== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
