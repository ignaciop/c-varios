#include "stock.h"

/*
 * PROBLEM 4: main() function in stock_multimain.c: Load multiple
 * stock files and plot them together.
 *
 * The program must support an arbitrary number of command line
 * arguments according to the pattern:
 * 1. ./stock_multimain <max_height> <stockfile1>
 * 2. ./stock_multimain <max_height> <stockfile1> <stockfile2>
 * 3. ./stock_multimain <max_height> <stockfile1> <stockfile2> <stockfile3>
 * 4. etc.
 * The first parameter is the maximum height to plot which remaining
 * arguments as filenames containing the stock data to use in the
 * multiplot.
 *
 * `stock_load_all()` is used to load the stock files. If something goes
 * wrong, prints the error message:
 *   Problems loading all stock files, exiting
 * and exit with return code 1.
 *
 * The high/low prices are set for each stock using an appropriate
 * service function and the stocks are plotted using
 * `stock_multiplot()`
 *
 * SAMPLE OUTPUT OF STOCK_MULTIMAIN
 * >> ./stock_multimain 10 data/s01.txt data/s02.txt data/s03.txt
 * ==MULTIPLOT DATA==
 * max_height:  10
 * stop_count:  10
 * min price:   1.00
 * max price:   99.00
 * price range: 98.00
 * plot step:   9.80
 * ==LEGEND==
 * a : data/s01.txt
 * b : data/s02.txt
 * c : data/s03.txt
 *
 *            +------------------------------+
 *      89.20 |    B                         |
 *      79.40 |    B  bC               Abc  c|
 *      69.60 |    B  bC               Abc  c|
 *      59.80 |  c B  bC   a c         Abc bc|
 *      50.00 |  c B  bC   a c       b Abc bc|
 *      40.20 |a c B  bCa ca c       b Abc bc|
 *      30.40 |a caB abCabca c       b Abc bc|
 *      20.60 |a caB abCabcabca   b  b Abc bc|
 *      10.80 |abcaB abCabcabcaBc b ab Abc bc|
 *       1.00 |abcaBcabCabcabcaBcAbCabcAbcabc|
 *            +^--------------^--------------+
 *             0              5              
 *
 * NOTES
 * - If fewer than 1 stock file is provided, print a usage
 *   message. This case won't be tested but is instructive.
 * - It is handy to use pointer arithmetic to locate where in argv[]
 *   the names of stock files begin so that this portion of the array
 *   can be passed directly to `stock_load_all()` and spare one the
 *   need of copying strings.
 * - Typically the function will load all stock files required, then
 *   loop through and initialize their high/low price indices with an
 *   appropriate function and then call the multi-plot function to
 *   show them.  There is no need to set the best buy/sell indices in
 *   this application.
 * - The normal `stock_set_best()` function MUST be present with
 *   Quadratic complexity (or worse)
 * - The linear time version must also be present 
 * - The linear time version MUST be used in `main()` and pass test cases
 *   associated with running the whole program.
 */
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("%s\n", "usage: ./stock_multimain <max_height> <stockfile1> [stockfile2] [...]");
        
        exit(EXIT_FAILURE);
    }
    
    int stock_files_count = argc - 2;
    int max_height = atoi(argv[1]);
    
    char **filenames = (char **)malloc(sizeof(char *) * stock_files_count);
    
    if (filenames == NULL) {
        perror("Cannot allocate memory for new filenames array.\n");
        
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < stock_files_count; ++i) {
        filenames[i] = strdup(argv[i + 2]);
    }
    
    stock_t **stocks = stock_load_all(filenames, stock_files_count);
    
    for (int i = 0; i < stock_files_count; ++i) {
        stock_set_hilo(stocks[i]);
    }

    stock_multiplot(stocks, stock_files_count, max_height);
    
    
    for (int i = 0; i < stock_files_count; ++i) {
        stock_free(stocks[i]);
        
        free(filenames[i]);
        filenames[i] = NULL;
    }
    
    free(stocks);
    stocks = NULL;
    
    free(filenames);
    filenames = NULL;
    
    return EXIT_SUCCESS;
}
