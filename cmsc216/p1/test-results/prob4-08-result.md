(TEST 8) stock_multimain stress : ok
====================================

COMMENTS
--------
Plot 20 stock files together to ensure that the program holds up under
stress. Not all stock files have the same length.

PROGRAM: ./stock_multimain 15 data/s01.txt data/s02.txt data/s03.txt data/s04.txt data/s05.txt data/s06.txt data/s07.txt data/s08.txt data/s09.txt data/s10.txt data/s11.txt data/s12.txt data/s13.txt data/s14.txt data/s15.txt data/s16.txt data/s17.txt data/s18.txt data/s19.txt data/s20.txt
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
To run this individual test in GDB use the command:
  gdb --args ./stock_multimain 15 data/s01.txt data/s02.txt data/s03.txt data/s04.txt data/s05.txt data/s06.txt data/s07.txt data/s08.txt data/s09.txt data/s10.txt data/s11.txt data/s12.txt data/s13.txt data/s14.txt data/s15.txt data/s16.txt data/s17.txt data/s18.txt data/s19.txt data/s20.txt
but any input to the program must be typed within the debugger

FAILURE MESSAGES
----------------
None

SIDE-BY-SIDE DIFF of Expected vs Actual
---------------------------------------
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                                                                                                                                                                            ===ACTUAL===
==MULTIPLOT DATA==                                                                                                                                                                                                    . ==MULTIPLOT DATA==
max_height:  15                                                                                                                                                                                                       . max_height: 15
stop_count:  10                                                                                                                                                                                                       . stop_count: 10
min price:   0.00                                                                                                                                                                                                     . min price: 0.00
max price:   99.00                                                                                                                                                                                                    . max price: 99.00
price range: 99.00                                                                                                                                                                                                    . price range: 99.00
plot step:   6.60                                                                                                                                                                                                     . plot step: 6.60
==LEGEND==                                                                                                                                                                                                            . ==LEGEND==
a : data/s01.txt                                                                                                                                                                                                      . a : data/s01.txt
b : data/s02.txt                                                                                                                                                                                                      . b : data/s02.txt
c : data/s03.txt                                                                                                                                                                                                      . c : data/s03.txt
d : data/s04.txt                                                                                                                                                                                                      . d : data/s04.txt
e : data/s05.txt                                                                                                                                                                                                      . e : data/s05.txt
f : data/s06.txt                                                                                                                                                                                                      . f : data/s06.txt
g : data/s07.txt                                                                                                                                                                                                      . g : data/s07.txt
h : data/s08.txt                                                                                                                                                                                                      . h : data/s08.txt
i : data/s09.txt                                                                                                                                                                                                      . i : data/s09.txt
j : data/s10.txt                                                                                                                                                                                                      . j : data/s10.txt
k : data/s11.txt                                                                                                                                                                                                      . k : data/s11.txt
l : data/s12.txt                                                                                                                                                                                                      . l : data/s12.txt
m : data/s13.txt                                                                                                                                                                                                      . m : data/s13.txt
n : data/s14.txt                                                                                                                                                                                                      . n : data/s14.txt
o : data/s15.txt                                                                                                                                                                                                      . o : data/s15.txt
p : data/s16.txt                                                                                                                                                                                                      . p : data/s16.txt
q : data/s17.txt                                                                                                                                                                                                      . q : data/s17.txt
r : data/s18.txt                                                                                                                                                                                                      . r : data/s18.txt
s : data/s19.txt                                                                                                                                                                                                      . s : data/s19.txt
t : data/s20.txt                                                                                                                                                                                                      . t : data/s20.txt
                                                                                                                                                                                                                      ( 
           +--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+ .            +--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
     92.40 |              o      B   f             T        I  L      S      F                            O                               G i    N                                                              Q   | .      92.40 |              o      B   f             T        I  L      S      F                            O                               G i    N                                                              Q   |
     85.80 |           l  o q    B   f             T  C   g I  L      St     F                     Hi     O    t                        E G i    N                     P    Abc                   c     i       Q   | .      85.80 |           l  o q    B   f             T  C   g I  L      St     F                     Hi     O    t                        E G i    N                     P    Abc                   c     i       Q   |
     79.20 |    e      l  o q    B D f h J         T bC   ghI  LM     St    eF h                   Hi   m O    t                        E G i    N                  m  P  s Abc e             s   c     i       Q   | .      79.20 |    e      l  o q    B D f h J         T bC   ghI  LM     St    eF h                   Hi   m O    t                        E G i    N                  m  P  s Abc e             s   c     i       Q   |
     72.60 |    e      l  o q    B D fgh J         T bC   ghIj LM     St    eF h                   Hi   mnO   st                        E Ghi    N                  m  P Rs Abc e             s   c     i     opQ   | .      72.60 |    e      l  o q    B D fgh J         T bC   ghIj LM     St    eF h                   Hi   mnO   st                        E Ghi    N                  m  P Rs Abc e             s   c     i     opQ   |
     66.00 |  c ef     l  opq    B D fgh J   no    T bC   ghIj LM  p  St    eF hi                  Hi   mnO  rst   de            r      EfGhi    N            gh  K m  P Rs Abc e             s  bc     i     opQ   | .      66.00 |  c ef     l  opq    B D fgh J   no    T bC   ghIj LM  p  St    eF hi                  Hi   mnO  rst   de            r      EfGhi    N            gh  K m  P Rs Abc e             s  bc     i     opQ   |
     59.40 |  cdef   j l  opq    B D fgh Jk  no    T bC   ghIj LM  p  St    eF hi  lm    r  a c    Hi  lmnOp rst   de            r      EfGhi k  N            gh  K m  P Rs Abc e   i         s  bc     i     opQ   | .      59.40 |  cdef   j l  opq    B D fgh Jk  no    T bC   ghIj LM  p  St    eF hi  lm    r  a c    Hi  lmnOp rst   de            r      EfGhi k  N            gh  K m  P Rs Abc e   i         s  bc     i     opQ   |
     52.80 |  cdef   j l  opq    B D fgh Jk  no q  T bC   ghIj LM op rSt    eF hi  lm  pqr  a c   gHi  lmnOp rst   de           qr      EfGhi k mN p     b    gh  K m  P Rs Abc e   i         s  bc   g i     opQ s | .      52.80 |  cdef   j l  opq    B D fgh Jk  no q  T bC   ghIj LM op rSt    eF hi  lm  pqr  a c   gHi  lmnOp rst   de           qr      EfGhi k mN p     b    gh  K m  P Rs Abc e   i         s  bc   g i     opQ s |
     46.20 |  cdef   j l  opq    B D fgh Jk  no qr T bC   ghIj LM op rSta   eF hiJ lm  pqr  a cd  gHi  lmnOpqrst   de   i       qr      EfGhi klmN p     b    gh  K m  PqRs Abc e   i  l  op  s  bc   g i     opQ s | .      46.20 |  cdef   j l  opq    B D fgh Jk  no qr T bC   ghIj LM op rSta   eF hiJ lm  pqr  a cd  gHi  lmnOpqrst   de   i       qr      EfGhi klmN p     b    gh  K m  PqRs Abc e   i  l  op  s  bc   g i     opQ s |
     39.60 |a cdef   j l  opq    B D fgh Jkl no qrsT bC e ghIjkLM op rSta c eF hiJ lm  pqr  a cd  gHi  lmnOpqrst   de   i       qr      EfGhi klmNop rs  b    gh  K mnoPqRs Abc efg i  lm op  s  bc e g i     opQ s | .      39.60 |a cdef   j l  opq    B D fgh Jkl no qrsT bC e ghIjkLM op rSta c eF hiJ lm  pqr  a cd  gHi  lmnOpqrst   de   i       qr      EfGhi klmNop rs  b    gh  K mnoPqRs Abc efg i  lm op  s  bc e g i     opQ s |
     33.00 |a cdef   j l  opq   aB Defgh Jkl no qrsTabC e ghIjkLM op rStabc eF hiJ lm  pqr  a cd fgHi  lmnOpqrst   de   i  l    qr      EfGhi klmNop rs  b  e gh  K mnoPqRs Abc efg i  lm op  s  bc e g i   m opQ s | .      33.00 |a cdef   j l  opq   aB Defgh Jkl no qrsTabC e ghIjkLM op rStabc eF hiJ lm  pqr  a cd fgHi  lmnOpqrst   de   i  l    qr      EfGhi klmNop rs  b  e gh  K mnoPqRs Abc efg i  lm op  s  bc e g i   m opQ s |
     26.40 |a cdef   jkl  opq   aB Defgh Jkl no qrsTabC e ghIjkLM opQrStabc eF hiJ lmn pqr  a cd fgHi  lmnOpqrsta  de   i  l   pqrs     EfGhi klmNopqrs  b  e ghi KlmnoPqRs Abc efg i  lm opq s  bc efghi k m opQ s | .      26.40 |a cdef   jkl  opq   aB Defgh Jkl no qrsTabC e ghIjkLM opQrStabc eF hiJ lmn pqr  a cd fgHi  lmnOpqrsta  de   i  l   pqrs     EfGhi klmNopqrs  b  e ghi KlmnoPqRs Abc efg i  lm opq s  bc efghi k m opQ s |
     19.80 |a cdef   jklm opq  taB DefghiJkl no qrsTabC e ghIjkLM opQrStabc eF hiJ lmnOpqrstabcd fgHi  lmnOpqrsta  de g i  lmnopqrs  b  EfGhi klmNopqrs  b  e ghi KlmnoPqRs Abc efg i  lm opq s  bc efghi k m opQ s | .      19.80 |a cdef   jklm opq  taB DefghiJkl no qrsTabC e ghIjkLM opQrStabc eF hiJ lmnOpqrstabcd fgHi  lmnOpqrsta  de g i  lmnopqrs  b  EfGhi klmNopqrs  b  e ghi KlmnoPqRs Abc efg i  lm opq s  bc efghi k m opQ s |
     13.20 |abcdef   jklm opq  taB DefghiJkl no qrsTabC e ghIjkLM opQrStabc eF hiJ lmnOpqrstabcdEfgHi  lmnOpqrsta cde g i  lmnopqrs  b  EfGhi klmNopqrs  b  e ghi KlmnoPqRs Abc efghi  lm opqrs  bc efghi k m opQ s | .      13.20 |abcdef   jklm opq  taB DefghiJkl no qrsTabC e ghIjkLM opQrStabc eF hiJ lmnOpqrstabcdEfgHi  lmnOpqrsta cde g i  lmnopqrs  b  EfGhi klmNopqrs  b  e ghi KlmnoPqRs Abc efghi  lm opqrs  bc efghi k m opQ s |
      6.60 |abcdefgh jklmnopqR taBcDefghiJkl noPqrsTabCDeFghIjkLM opQrStabcdeFGhiJ lmnOpqrstabcdEfgHi klmnOpqrstaBcdefg i  lmnopqrs  b  EfGhi klmNopqrs ab  efghi KlmnoPqRs Abc efghi  lm opqrs abc efghi kLm opQ s | .       6.60 |abcdefgh jklmnopqR taBcDefghiJkl noPqrsTabCDeFghIjkLM opQrStabcdeFGhiJ lmnOpqrstabcdEfgHi klmnOpqrstaBcdefg i  lmnopqrs  b  EfGhi klmNopqrs ab  efghi KlmnoPqRs Abc efghi  lm opqrs abc efghi kLm opQ s |
      0.00 |abcdefghIjklmnopqRStaBcDefghiJklMnoPqrsTabCDeFghIjkLMNopQrStabcdeFGhiJklmnOpqrstabcdEfgHi klmnOpqrstaBcdefgHi klmnopqrsTAbC EfGhi klmNopqrs abc efghi KlmnoPqRs Abc efghi Klm opqrs abc efghi kLm opQ s | .       0.00 |abcdefghIjklmnopqRStaBcDefghiJklMnoPqrsTabCDeFghIjkLMNopQrStabcdeFGhiJklmnOpqrstabcdEfgHi klmnOpqrstaBcdefgHi klmnopqrsTAbC EfGhi klmNopqrs abc efghi KlmnoPqRs Abc efghi Klm opqrs abc efghi kLm opQ s |
           +^---------------------------------------------------------------------------------------------------^---------------------------------------------------------------------------------------------------+ .            +^---------------------------------------------------------------------------------------------------^---------------------------------------------------------------------------------------------------+
            0                                                                                                   5                                                                                                     .             0                                                                                                   5                                                                                                   

```

LINE-BY-LINE DIFF of Expected vs Actual
---------------------------------------
No differences found

VALGRIND REPORT
---------------
The program is run on under valgrind as
  stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./stock_multimain 15 data/s01.txt data/s02.txt data/s03.txt data/s04.txt data/s05.txt data/s06.txt data/s07.txt data/s08.txt data/s09.txt data/s10.txt data/s11.txt data/s12.txt data/s13.txt data/s14.txt data/s15.txt data/s16.txt data/s17.txt data/s18.txt data/s19.txt data/s20.txt
which may be pasted onto a command line to run it.

```
==443894== Memcheck, a memory error detector
==443894== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443894== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443894== Command: ./stock_multimain 15 data/s01.txt data/s02.txt data/s03.txt data/s04.txt data/s05.txt data/s06.txt data/s07.txt data/s08.txt data/s09.txt data/s10.txt data/s11.txt data/s12.txt data/s13.txt data/s14.txt data/s15.txt data/s16.txt data/s17.txt data/s18.txt data/s19.txt data/s20.txt
==443894== 
==443894== 
==443894== HEAP SUMMARY:
==443894==     in use at exit: 0 bytes in 0 blocks
==443894==   total heap usage: 162 allocs, 162 frees, 185,824 bytes allocated
==443894== 
==443894== All heap blocks were freed -- no leaks are possible
==443894== 
==443894== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

SUMMARY
-------
Test Passed
