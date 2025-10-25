(TEST 20) stock_demo : ok
=========================

COMMENTS
--------
Runs the provided stock_demo application which demonstrates all of the
stock functions and checks for output.

PROGRAM: ./stock_demo
---------------------
To run this individual test in GDB use the command:
  gdb --args ./stock_demo
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                       ===ACTUAL===
PRINTING ALL PRICES HEIGHT 15    . PRINTING ALL PRICES HEIGHT 15
==PLOT DATA==                    . ==PLOT DATA==
start/stop:  0 15                . start/stop: 0 15
max_height:  15                  . max_height: 15
price range: 309.00              . price range: 309.00
plot step:   20.60               . plot step: 20.60
           +--B=S----------+     .            +--B=S----------+
    302.40 |    H   *      |     .     302.40 |    H   *      |
    281.80 | *  H   *      |     .     281.80 | *  H   *      |
    261.20 | *  H   *      |     .     261.20 | *  H   *      |
    240.60 | *  H   *      |     .     240.60 | *  H   *      |
    220.00 |**  H   *      |     .     220.00 |**  H   *      |
    199.40 |**  H * *      |     .     199.40 |**  H * *      |
    178.80 |**  H** *  *   |     .     178.80 |**  H** *  *   |
    158.20 |**  H** *  ** *|     .     158.20 |**  H** *  ** *|
    137.60 |**  H****  ****|     .     137.60 |**  H****  ****|
    117.00 |**  H****  ****|     .     117.00 |**  H****  ****|
     96.40 |**  H****  ****|     .      96.40 |**  H****  ****|
     75.80 |** *H***** ****|     .      75.80 |** *H***** ****|
     55.20 |** *H***** ****|     .      55.20 |** *H***** ****|
     34.60 |** *H***** ****|     .      34.60 |** *H***** ****|
     14.00 |****H*****L****|     .      14.00 |****H*****L****|
           +^----^----^----+     .            +^----^----^----+
            0    5    10         .             0    5    10   
PRINTING PRICES 5 to 10 HEIGHT 8 . PRINTING PRICES 5 to 10 HEIGHT 8
==PLOT DATA==                    . ==PLOT DATA==
start/stop:  5 10                . start/stop: 5 10
max_height:  8                   . max_height: 8
price range: 309.00              . price range: 309.00
plot step:   38.62               . plot step: 38.62
           +-----+               .            +-----+
    284.38 |   * |               .     284.38 |   * |
    245.75 |   * |               .     245.75 |   * |
    207.12 |   * |               .     207.12 |   * |
    168.50 |** * |               .     168.50 |** * |
    129.88 |**** |               .     129.88 |**** |
     91.25 |**** |               .      91.25 |**** |
     52.62 |*****|               .      52.62 |*****|
     14.00 |*****|               .      14.00 |*****|
           +^----+               .            +^----+
            5                    .             5    

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./stock_demo
which may be pasted onto a command line to run it.

```
==443728== Memcheck, a memory error detector
==443728== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443728== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443728== Command: ./stock_demo
==443728== 
==443728== 
==443728== HEAP SUMMARY:
==443728==     in use at exit: 0 bytes in 0 blocks
==443728==   total heap usage: 7 allocs, 7 frees, 9,325 bytes allocated
==443728== 
==443728== All heap blocks were freed -- no leaks are possible
==443728== 
==443728== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
