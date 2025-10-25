#include "stock.h"

/*
 * PROBLEM 3: main() in stock_main.c
 *
 * The program must support three command line forms.
 * 1. ./stock_main <stockfile> <max_height>
 * 2. ./stock_main <stockfile> <max_height> <start> 
 * 3. ./stock_main <stockfile> <max_height> <start> <stop>
 *
 * All forms have a the stock file as the first command line argument
 * and the maximum plotting height as the 2nd argument. Forms 2 and 3
 * optionally specify a starting time index (inclusive) and stopping
 * time index (exclusive) to plot a time range for the stock prices. 
 *
 * NOTES
 * - It is a good idea to check that the number of command line
 *   arguments is either 3 (Form 1) or 4 (Form 2) or 5 (form 3) if
 *   not, bail out from the program. There may or may not be an
 *   automated test that checks that no action is taken when an
 *   incorrect number of command line arguments appear but there will
 *   definitely be tests for each of the forms indicated so a logical
 *   and clean structure that attends to them is a good idea.
 * - All command line arguments come into C programs as strings
 *   (char*).  That means the numbers on the command line like
 *   `max_height` will also be a string of characters and need to be
 *   converted to an int to be used in the program.  The atoi()
 *   function is useful for this: search for documentation on it and
 *   use it for the conversion.
 * - Make sure to check that loading stock data from a file
 *   succeeds. If not, print the following error message:
 *
 *     Failed to load stock file, exiting
 *
 *   This message is in addition to the error message that is printed
 *   by the stock_load() function. Return 1 from main() to indicate
 *   that the program was not successful.
 * - If stock data is successfully loaded, perform the requested
 *   plotting using appropriate functions. Don't forget to free
 *   heap-allocated memory before ending the program.
 *
 * NOTE: a second main() function is required for Problem 4 in a
 * different file.
 */
int main(int argc, char *argv[]) {
    int max_height = 0;
    int start = 0;
    int stop = 0;
    
    switch(argc) {
        case 3:
            max_height = atoi(argv[2]);
            
            break;
        
        case 4:
            max_height = atoi(argv[2]);
            start = atoi(argv[3]);
            
            break;
            
        case 5:
            max_height = atoi(argv[2]);
            start = atoi(argv[3]);
            stop = atoi(argv[4]);
            
            break;
        default:
            printf("%s\n", "usage: ./stock_main <stockfile> <max_height> [start] [stop]");
        
            exit(EXIT_FAILURE);
    }
    
    stock_t *stock = stock_new();
    
    int sl = stock_load(stock, argv[1]);
    
    if (sl != 0) {
        stock_free(stock);
        
        printf("%s\n", "Failed to load stock file, exiting");
        
        exit(EXIT_FAILURE);
    } else {
        if (argc == 3 || argc == 4) {
            stop = stock->count;
        }
    }
    
    stock_set_hilo(stock);
    
    //int ssb = stock_set_best(stock);
    int ssb = stock_set_best_linear(stock);
    
    stock_print(stock);
    
    if (ssb == 0) {
        stock_plot(stock, max_height, start, stop);
    }
    
    stock_free(stock);
    
    return EXIT_SUCCESS;
}
