(TEST 12) stock_load pathological : ok
======================================

COMMENTS
--------


Test Segment 1 : ok
-------------------

### PROGRAM: ./test_stock_funcs stock_load_1price
To run this individual test in GDB use the command:
gdb --args ./test_stock_funcs stock_load_1price
but any input to the program must be typed within the debugger

### FAILURE MESSAGES
None

### SIDE-BY-SIDE DIFF of Expected vs Actual
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                               ===ACTUAL===
{                                                        . {
    // stock_load() calls on price arrays of 1           .     // stock_load() calls on price arrays of 1 
    stock_t *stock = stock_new();                        .     stock_t *stock = stock_new();
    int ret = stock_load(stock, "data/stock-1only.txt"); .     int ret = stock_load(stock, "data/stock-1only.txt");
    printf("ret: %d\n", ret);                            .     printf("ret: %d\n", ret);
    stock_print(stock);                                  .     stock_print(stock);
    stock_free(stock);                                   .     stock_free(stock);
}                                                        . }
ret: 0                                                   . ret: 0
==STOCK DATA==                                           . ==STOCK DATA==
data_file: data/stock-1only.txt                          . data_file: data/stock-1only.txt
count: 1                                                 . count: 1
prices: [70.00]                                          . prices: [70.00]
lo_index:  -1                                            . lo_index: -1
hi_index:  -1                                            . hi_index: -1
best_buy:  -1                                            . best_buy: -1
best_sell: -1                                            . best_sell: -1
profit:    0.00                                          . profit: 0.00

```

### LINE-BY-LINE DIFF of Expected vs Actual
No differences found

### VALGRIND REPORT
The program is run on under valgrind as
stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_load_1price
which may be pasted onto a command line to run it.

```
==443720== Memcheck, a memory error detector
==443720== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443720== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443720== Command: ./test_stock_funcs stock_load_1price
==443720== 
==443720== 
==443720== HEAP SUMMARY:
==443720==     in use at exit: 0 bytes in 0 blocks
==443720==   total heap usage: 7 allocs, 7 frees, 9,205 bytes allocated
==443720== 
==443720== All heap blocks were freed -- no leaks are possible
==443720== 
==443720== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Test Segment 2 : ok
-------------------

### PROGRAM: ./test_stock_funcs stock_load_empty
To run this individual test in GDB use the command:
gdb --args ./test_stock_funcs stock_load_empty
but any input to the program must be typed within the debugger

### FAILURE MESSAGES
None

### SIDE-BY-SIDE DIFF of Expected vs Actual
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                             ===ACTUAL===
{                                                                      . {
    // Load a completely empty stock file - should give count of 0 and .     // Load a completely empty stock file - should give count of 0 and
    // an empty prices array.                                          .     // an empty prices array.
    stock_t *stock = stock_new();                                      .     stock_t *stock = stock_new();
    int ret = stock_load(stock, "data/stock-empty.txt");               .     int ret = stock_load(stock, "data/stock-empty.txt");
    printf("ret: %d\n", ret);                                          .     printf("ret: %d\n", ret);
    stock_print(stock);                                                .     stock_print(stock);
    stock_free(stock);                                                 .     stock_free(stock);
}                                                                      . }
ret: 0                                                                 . ret: 0
==STOCK DATA==                                                         . ==STOCK DATA==
data_file: data/stock-empty.txt                                        . data_file: data/stock-empty.txt
count: 0                                                               . count: 0
prices: []                                                             . prices: []
lo_index:  -1                                                          . lo_index: -1
hi_index:  -1                                                          . hi_index: -1
best_buy:  -1                                                          . best_buy: -1
best_sell: -1                                                          . best_sell: -1
profit:    0.00                                                        . profit: 0.00

```

### LINE-BY-LINE DIFF of Expected vs Actual
No differences found

### VALGRIND REPORT
The program is run on under valgrind as
stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_load_empty
which may be pasted onto a command line to run it.

```
==443788== Memcheck, a memory error detector
==443788== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443788== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443788== Command: ./test_stock_funcs stock_load_empty
==443788== 
==443788== 
==443788== HEAP SUMMARY:
==443788==     in use at exit: 0 bytes in 0 blocks
==443788==   total heap usage: 6 allocs, 6 frees, 5,101 bytes allocated
==443788== 
==443788== All heap blocks were freed -- no leaks are possible
==443788== 
==443788== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

Test Segment 3 : ok
-------------------

### PROGRAM: ./test_stock_funcs stock_load_no_file
To run this individual test in GDB use the command:
gdb --args ./test_stock_funcs stock_load_no_file
but any input to the program must be typed within the debugger

### FAILURE MESSAGES
None

### SIDE-BY-SIDE DIFF of Expected vs Actual
. lines match; | lines differ; < expected line missing; > extra line in actual

```sdiff
===EXPECT===                                                             ===ACTUAL===
{                                                                      . {
    // Attempt to load a non-existent file which should fail and leave .     // Attempt to load a non-existent file which should fail and leave
    // the stock struct un-altered.                                    .     // the stock struct un-altered.
    stock_t *stock = stock_new();                                      .     stock_t *stock = stock_new();
    int ret = stock_load(stock, "data/not-there.txt");                 .     int ret = stock_load(stock, "data/not-there.txt");
    printf("ret: %d\n", ret);                                          .     printf("ret: %d\n", ret);
    stock_print(stock);                                                .     stock_print(stock);
    stock_free(stock);                                                 .     stock_free(stock);
}                                                                      . }
Could not open file 'data/not-there.txt', cannot count lines           . Could not open file 'data/not-there.txt', cannot count lines
Unable to open stock file 'data/not-there.txt', cannot load stock data . Unable to open stock file 'data/not-there.txt', cannot load stock data
ret: -1                                                                . ret: -1
==STOCK DATA==                                                         . ==STOCK DATA==
data_file: NULL                                                        . data_file: NULL
count: -1                                                              . count: -1
prices: NULL                                                           . prices: NULL
lo_index:  -1                                                          . lo_index: -1
hi_index:  -1                                                          . hi_index: -1
best_buy:  -1                                                          . best_buy: -1
best_sell: -1                                                          . best_sell: -1
profit:    0.00                                                        . profit: 0.00

```

### LINE-BY-LINE DIFF of Expected vs Actual
No differences found

### VALGRIND REPORT
The program is run on under valgrind as
stdbuf -i 0 -o 0 -e 0 valgrind --error-exitcode=13 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./test_stock_funcs stock_load_no_file
which may be pasted onto a command line to run it.

```
==443799== Memcheck, a memory error detector
==443799== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==443799== Using Valgrind-3.24.0 and LibVEX; rerun with -h for copyright info
==443799== Command: ./test_stock_funcs stock_load_no_file
==443799== 
==443799== 
==443799== HEAP SUMMARY:
==443799==     in use at exit: 0 bytes in 0 blocks
==443799==   total heap usage: 3 allocs, 3 frees, 984 bytes allocated
==443799== 
==443799== All heap blocks were freed -- no leaks are possible
==443799== 
==443799== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

### SUMMARY
Test Passed
