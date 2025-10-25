/* stock_funcs.c: support functions for the stock_main program. */

#include "stock.h"

/*
 * PROBLEM 1: Allocate a new stock struct and initialize its fields.
 * Integer fields like 'count' and 'lo_index' should be initialied to -1.
 * Pointer fields like 'prices' should be initialized to NULL. 
 * The stock should be heap-allocated using malloc() and returned.
 * Since this is an allocation function, no use of 'free()' should appear.
 */
stock_t *stock_new(void) {
    stock_t *ns = (stock_t *)malloc(sizeof(stock_t));
    
    if (ns == NULL) {
        perror("Cannot allocate memory for new stock.\n");
        
        exit(EXIT_FAILURE);
    }
    
    ns->data_file = NULL;
    ns->count = -1;
    ns->prices = NULL;
    ns->lo_index = -1;
    ns->hi_index = -1;
    ns->best_buy = -1;
    ns->best_sell = -1;
    
    return ns;
}

/*
 * PROBLEM 1: Free a stock. Check the 'data_file' and 'prices' fields:
 * if they are non-NULL, then free them. Then free the pointer to 'stock' itself.
 */
void stock_free(stock_t *stock) {
    if (stock != NULL) {
        if (stock->data_file != NULL) {
            free(stock->data_file);
            stock->data_file = NULL;
        }
        
        if (stock->prices != NULL) {
            free(stock->prices);
            stock->prices = NULL;
        }
        
        free(stock);
        stock = NULL;
    }
}

/*
 * PROBLEM 1: Prints data about a stock that is passed in via a pointer.
 * Uses the syntax ptr->field to access fields of the struct pointed by 'stock'.
 * Output follows the general convention:
 *
 * ==STOCK DATA==
 * data_file: data/stock-jagged.txt                      
 * count: 15
 * prices: [103.00, 250.00, 133.00, ...]
 * lo_index:  8
 * hi_index:  11
 * best_buy:  8
 * best_sell: 11
 * profit:    232.00
 *
 * Each line prints a field of the stock_t struct. In all cases,
 * floating point numbers are printed with 2 decimal digits of
 * accuracy.
 *
 * NULLS FOR FIELDS
 * The fields 'data_file' and 'prices' may be NULL in which case they
 * will be printed specially as in
 * 
 * data_file: NULL
 * prices: NULL
 *
 * This requires a manual if/else check for NULL values for these  pointers.
 * 
 * PRICES FIELD
 * When printing the 'prices' field, if the 'count' field is 0 to 3,
 * print the entire array as in
 *
 * prices: []                        # count == 0
 * prices: [70.00]                   # count == 1
 * prices: [50.00, 90.00]            # count == 2
 * prices: [59.00, 45.00, 103.00]    # count == 3
 *
 * Otherwise, print the first 3 elements with a ... at the end as in
 *
 * prices: [10.00, 20.00, 30.00, ...] # count > 3
 *
 * PROFIT
 * There is no 'profit' field in the struct. Instead, calculate the
 * profit as the difference between the price at the 'best_sell' index
 * and 'best_buy' index.  If these indices are -1 indicating the best
 * buy/sell time is not known or not viable, print a proit of 0.0
 */
void stock_print(const stock_t *stock) {
    if (stock != NULL) {
        const int prices_print_limit = 3;
        
        double profit = 0.0;
        
        printf("%s\n", "==STOCK DATA==");
        printf("data_file: %s\n", (stock->data_file != NULL) ? stock->data_file : "NULL");
        printf("count: %d\n", stock->count);
        printf("%s", "prices: ");
        
        if (stock->prices != NULL) {
            printf("%s", "[");
            
            for (int i = 0; i < stock->count; ++i) {
                if (i < prices_print_limit) {
                    printf((i == stock->count - 1) ? "%.2f" : "%.2f, ", stock->prices[i]);
                } else {
                    printf("%s", "...");
                    
                    break;
                }
            }
            
            printf("%s\n", "]");
            
            if ((stock->best_buy != -1) && (stock->best_sell != -1)) {
                double best_buy = stock->prices[stock->best_buy];
                double best_sell = stock->prices[stock->best_sell];
                
                profit = best_sell - best_buy;
            }
        } else {
            printf("%s\n", "NULL");
        }
        
        printf("lo_index: %d\n", stock->lo_index);
        printf("hi_index: %d\n", stock->hi_index);
        printf("best_buy: %d\n", stock->best_buy);
        printf("best_sell: %d\n", stock->best_sell);
        printf("profit: %.2f\n", profit);
    }
}

/*
 * PROBLEM 2: Sets the index of 'lo_index' and 'hi_index' fields of
 * the stock to be the positions in 'prices' of the lowest and highest
 * values present in it.
 * Uses a simple loop over the array 'prices' which is 'count' elements long 
 * to examine each for high/low.
 * If 'count' is zero, makes no changes to 'lo_index' and 'hi_index'.
 */
void stock_set_hilo(stock_t *stock) {
    if (stock != NULL && stock->prices != NULL && stock->count != 0) {
        double min_price = stock->prices[0];
        double max_price = stock->prices[0];
        
        stock->lo_index = 0;
        stock->hi_index = 0;
        
        for (int i = 1; i < stock->count; ++i) {
            if (stock->prices[i] < min_price) {
                stock->lo_index = i;
                min_price = stock->prices[i];
            }
            
            if (stock->prices[i] > max_price) {
                stock->hi_index = i;
                max_price = stock->prices[i];
            }
        }
    }
}

/*
 * PROBLEM 2: Sets the 'best_buy' and 'best_sell' fields of 'stock'.
 * This corresponds to the pair which produces the best profit. 
 * On determining the best buy/sell indices which produce a positive
 * profit, sets these fields in 'stock' and returns 0.
 * If there is no buy/sell point which would result in a positive profit,
 * sets the 'best_buy' and 'best_sell' indices to -1 and returns -1.
 * Always calculates the earliest buy/sell pair of indices that would get the
 * best profit: if 5,8 and 5,9 and 7,10 all give the same, maximal
 * profit, the best buy/sell indices are set to 5,8.
 * 
 * ALGORITHM NOTES
 * One intuitive algorithm to compute this is to try every possible
 * buy index (outer loop) and every possible sell index after it
 * (inner loop) looking for the maximum profit produced in it.
 * This is a O(N^2) algorithm with N = count.
 * Using this algorithm is a good start.
 *
 * Some MAKEUP CREDIT will be awarded for implementing a more
 * efficient, O(N) algorithm but THIS FUNCTION MUST IMPLEMENT THE
 * O(N^2) ALGORITHM to earn credit.
 * Implement the O(N) version elsewhere for Makeup Credit.
 */
int stock_set_best(stock_t *stock) {
    int best_found = -1;
    
    if (stock != NULL && stock->prices != NULL) {
        stock->best_buy = -1;
        stock->best_sell = -1;
    
        double best_profit = 0.0;
        
        for (int i = 0; i < stock->count; ++i) {
            for (int j = i + 1; j < stock->count; ++j) {
                double diff_prices = stock->prices[j] - stock->prices[i];
                
                if (diff_prices > best_profit) {
                    stock->best_buy = i;
                    stock->best_sell = j;
                    
                    best_profit = diff_prices;
                    
                    best_found = 0;
                }
            }
        }
    }
    
    return best_found;
}

/*
 * PROBLEM 2: Opens file named 'filename' and counts how many times
 * the '\n' newline character appears in it which corresponds to how
 * many lines of text are in it.
 * Makes use of either fscanf() with the %c format to read single characters 
 * or alternative I/O functions like fgetc().
 * Closes the file before returning a count of how many lines are it it.
 * If for any reason the file cannot be opened, prints a message like
 *
 *   Could not open file '<FILENAME>', cannot count lines
 *
 * with <FILENAME> substituted for the name of the file.
 * Returns -1 to indicate failure in this case.
 */
int count_lines(const char *filename) {
    int total_lines = 0;
    
    FILE *fp = fopen(filename, "r");
	
	if (fp == NULL) {
		printf("Could not open file '%s', cannot count lines\n", filename);
		
		total_lines = -1;
	} else {
        char ic = ' ';
        
	    while ((ic = fgetc(fp)) != EOF) {
	        if (ic == '\n') {
	            ++total_lines;
	        }
	    }
	    
	    fclose(fp);
	}

    return total_lines;
}

/*
 * PROBLEM 2: Loads a stock from file 'filename' into 'stock' filling
 * its 'prices' and 'count' fields in.
 * Makes use of the count_lines() function to determine how many lines are 
 * in the file which will dictate 'count' and the length of 'prices'.
 * Allocates space in the heap for the stock's 'prices' array, opens the 
 * 'filename' and iterates through reading prices into the array.
 * The data format for prices files is
 *
 * time_03 133.00
 * time_04 143.00
 * time_05 168.00
 * time_06 91.00
 * 
 * where each line has a time as as single string and a price which is
 * floating point number. The times can be ignored which can be
 * accomplished with a fscanf() call with format "%*s" to read a
 * string but ignore/discard it.
 * 
 * Assigns the 'datafile' field to be a duplicated string of
 * 'filename' for which 'strdup()' is extremely useful. This string
 * must be free()'d later likely in 'stock_free()'
 * 
 * On successfully loading the stock, returns 0.
 *
 * If 'filename' cannot be opened, prints the message 
 * 
 *   Unable to open stock file '<FILENAME>', cannot load stock data
 *
 * with '<FILENAME>' substituted in for the name of the stock and
 * returns -1.
 */
int stock_load(stock_t *stock, const char *filename) {
    int stock_loaded = -1;
    
    if (stock != NULL) {
        stock->count = count_lines(filename);
        
        FILE *fp = fopen(filename, "r");
	    
	    if (fp == NULL) {
		    printf("Unable to open stock file '%s', cannot load stock data\n", filename);
	    } else {
	        stock->data_file = strdup(filename);
	
	        stock->prices = (double *)malloc(sizeof(double) * stock->count);
	        
	        if (stock->prices == NULL) {
                perror("Cannot allocate memory for new stock prices array.\n");
        
                exit(EXIT_FAILURE);
            }
            
	        for (int i = 0; i < stock->count; ++i) {
	            fscanf(fp, "%*s %lf", &(stock->prices[i]));
	        }
	        
	        fclose(fp);
	        
	        stock_loaded = 0;
	    }
    }
    
    return stock_loaded;
}

/*
 * PROBLEM 2: Plots a graphical representation of stock information.
 * First calculates and prints plot which is in the following format:
 *
 * ==PLOT DATA==
 * start/stop:  0 15
 * max_height:  14
 * price range: 309.00
 * plot step:   22.07
 *            +--B=S----------+
 *     300.93 |    H   *      |
 *     278.86 | *  H   *      |
 *     256.79 | *  H   *      |
 *     234.71 | *  H   *      |
 *     212.64 |**  H   *      |
 *     190.57 |**  H * *      |
 *     168.50 |**  H** *  *  *|
 *     146.43 |**  H** *  ****|
 *     124.36 |**  H****  ****|
 *     102.29 |**  H****  ****|
 *      80.21 |** *H***** ****|
 *      58.14 |** *H***** ****|
 *      36.07 |** *H***** ****|
 *      14.00 |****H*****L****|
 *            +^----^----^----+
 *             0    5    10   
 * 
 * Here brief notes on the format with more detail in the project specification.
 * - Parameters start, stop, and max_height are printed first along with
 *   calculated information like the price_range (uses hi_index and
 *   lo_index)
 * - The main body of the plot is exactly max_height characters high. The
 *   lowest line is the price at lo_index; the highest is hi_index minus
 *   plot_step
 * - The vertical axis prices can be printed with the format specifier
 *   %10.2f to give the correct leading whitespace with 2 digits of
 *   accuracy
 * - If the hi and lo prices appear in the range, their bar is printed
 *   with an H or an L while all other stocks are printed with a *
 * - The top axis may include a B and an S at the positions of the
 *   best_buy and best_sell index with a = between these to show the
 *   period of ownership.
 * - The bottom axis shows tic marks as ^ and below them index labels at
 *   values divisible by 5. For the numeric index labels, it is easiest
 *   to print spaces to a value divisible by 5 then use the format
 *   specifier %-5d to print integers: this aligns left and prints
 *   whitespace padding on the right to width 5. In a loop, one can
 *   advance by +5 each time a label is printed.
 */
void stock_plot(const stock_t *stock, const int max_height, const int start, const int stop) {
    if (stock != NULL) {
        if (max_height > 0 && start >= 0 && stop > 0 && stop > start) {
            double price_range = stock->prices[stock->hi_index] - stock->prices[stock->lo_index];
            double plot_step = price_range / max_height;
            
            printf("%s\n", "==PLOT DATA==");
            printf("start/stop: %d %d\n", start, stop);
            printf("max_height: %d\n", max_height);
            printf("price range: %.2f\n", price_range);
            printf("plot step: %.2f\n", plot_step);
            
            printf("%10s +","");
            
            for (int i = start; i < stop; ++i) {
                if (i == stock->best_buy) {
                    printf("%s", "B");
                } else if (i == stock->best_sell) {
                    printf("%s", "S");
                } else if (i > stock->best_buy && i < stock->best_sell) {
                    printf("%s", "=");
                } else {
                    printf("%s", "-");
                }
            }
            
            printf("%s\n","+");
            
            for (int h = max_height - 1; h >= 0; --h) {
                double thresh = h * plot_step + stock->prices[stock->lo_index];
                
                printf("%10.2f |", thresh);
                
                for (int i = start; i < stop; ++i) {
                    if (stock->prices[i] >= thresh) {
                        if (i == stock->hi_index) {
                            printf("%s", "H");
                        } else if (i == stock->lo_index) {
                            printf("%s", "L");
                        } else {
                            printf("%s", "*");
                        }  
                    } else {
                        printf("%s", " ");
                    }
                }
                
                printf("%s\n", "|");
            }
            
            printf("%10s +","");
            
            for (int i = start; i < stop; ++i) {
                printf("%s", (i % 5 == 0) ? "^" : "-");
            }
            
            printf("%s\n","+");
            
            printf("%11s ","");
            
            for (int i = start; i < stop; ++i) {
                if (i % 5 == 0) {
                    printf("%-5d", i);
                }
            }
            
            printf("\n");
        }
    }
}

/*
 * PROBLEM 4: Loads all files named in `filenames[]` as stocks and
 * returns an array of pointers to those stocks. The length of the
 * `filenames[]` array is given in `stock_count`. Uses `stock_new() /
 * stock_load()` to create and load individual stocks. If any stock
 * fails to load, prints an error message
 *
 * Failed to load stock file <I>
 *
 * with <I> substituted for the index of the problematic file, then
 * de-allocates all memory that has so far been allocated and returns
 * NULL to indicate failures.
 */
stock_t **stock_load_all(char *filenames[], const int stock_count) {
    stock_t **nss = (stock_t **)malloc(sizeof(stock_t *) * stock_count);
    
    if (nss == NULL) {
        perror("Cannot allocate memory for new stocks array.\n");
        
        exit(EXIT_FAILURE);
    }
    
    for (int i = 0; i < stock_count; ++i) {
        nss[i] = stock_new();
        
        int sl = stock_load(nss[i], filenames[i]);
        
        if (sl != 0) {
            printf("Failed to load stock file %d\n", i);
            
            for (int j = 0; j <= i; ++j) {
                stock_free(nss[j]);
            }
            
            free(nss);
            nss = NULL;
            
            for (int k = 0; k < stock_count; ++k) {
                free(filenames[k]);
                filenames[k] = NULL;
            }
            
            free(filenames);
            filenames = NULL;
            
            printf("%s\n", "Problems loading all stock files, exiting");
            
            exit(EXIT_FAILURE);
        }
    }
    
    return nss;
}

/* max stocks supported for mult-stock printing in Problem 4 */
#define STOCKS_MAX_COUNT 26 

/* characters to use for plotting stocks */
const char stock_chars[STOCKS_MAX_COUNT + 1] = "abcdefghijklmnopqrstuvwxyz";

/*
 * PROBLEM 4: Plot all of the stocks in the `stocks` array which is
 * `stocks_count` elements long. 
 *
 * EXAMPLE PLOT:
 *
 * ==MULTIPLOT DATA==
 * max_height:  10
 * stop_count:  15
 * min price:   38.00
 * max price:   270.00
 * price range: 232.00
 * plot step:   23.20
 * ==LEGEND==
 * a : data/stock-valley.txt
 * b : data/stock-jagged.txt
 *
 *            +------------------------------+
 *     246.80 |   b                 b B      |
 *     223.60 |   b         b       b B      |
 *     200.40 |   b         b       b B      |
 *     177.20 |   b         b       b B      |
 *     154.00 |   b     b   b       b B      |
 *     130.80 |   b b b b   b       b B      |
 *     107.60 |   b b b b   b       b B      |
 *      84.40 |abab b b b b b    a abAB     b|
 *      61.20 |abababab b b ba a a abAB   b b|
 *      38.00 |abababababAbababaBababAB b b b|
 *            +^---------^---------^---------+
 *             0         5         10        
 *
 * DETAILS
 *
 * Plots start with the ==MULTIPLOT DATA== shown above which shows
 * basic plotting parameters. The stop index, minimum price, and
 * maximum price are set by finding the maximum count and min/max
 * price among all stocks in the array.
 *
 * The ==LEGEND== shows the character which will be printed associated
 * with each stock file. These are drawn from the provided
 * `stock_chars[]` array with the 0th stock printed using the 0th
 * character, 1th stock the 1th character, and so on. For each stock,
 * the columns of the low and high prices for the stock are printed as
 * upper case characters using the library `toupper()` conversion
 * function to make it easier to identify the extrema for stocks.
 *
 * When plotting, each stock is printed in its own column. If there
 * are 2 stocks, then each "time" index will have two columns as shown
 * above. If there are 8 stocks, then each time index will have 8
 * columns. The plotting area will be stocks_count*stop_count
 * characters wide. If a stock has a lower count (shorter prices
 * array) than stop_count, then blanks are printed in the columns
 * beyond its count (true for the `a` stock above in the last few
 * columns).
 *
 * If `stocks_count` is larger than `STOCKS_MAX_COUNT`, prints message
 *   ERROR: stocks array length <COUNT> exceeds max <MAX>\n
 * with <COUNT> and <MAX> substituted and immediately returns.
 *
 * NOTES
 * - The `stocks` variable is an array of pointers; that means the
 *   syntax `stocks[i]->field` accesses some field for the ith
 *   stock. Adapt this syntax to the various cases of accessing data
 *   for an individual stock.
 * - Unlike the single plotting, plot parameters like the stop_count and
 *   min/max price must be determined by analyzing all stocks. Use a
 *   loop to iterate through to find the extreme values among stocks.
 * - The plotting procedure itself will be similar to `stock_plot()`
 *   except for an additional layer of looping: for time index <i>,
 *   loop through all stocks and print their characters. Copying in
 *   code from `stock_plot()` is a good idea and then making
 *   adjustments is likely to yield good results.
 * - Multiplots always start at time index 0 and go to the time index
 *   of the stock with the largest prices[] count.
 * - When plotting a stock, check that it has a count that is above
 *   the current time index so that it will have data in its prices[]
 *   array. Not all stocks in a multiplot will have the same count of
 *   prices so it is possible to go out of bounds in arrays if one is
 *   not careful.
 * - The axis are wider: stop_count*stock_count characters wide. Use
 *   this in some loops to print boundaries.
 * - The axis label ticks are tricky. TRY USING PRINTF() by printing
 *   the numeric label in a field of 5 characters wide, then print
 *   additional 5-wide characters based stock_count to line up the
 *   next location that needs a numeric label.
 * - The function assumes that the high and low price indices have
 *   been set for all stocks prior to them being passed in. A main()
 *   is a good spot to do this. Since the best buy/sell points do not
 *   show in this function, these fields can remain uninitialized not
 *   affect the function's behavior.
 */
void stock_multiplot(stock_t **stocks, const int stocks_count, const int max_height) {
    if (stocks != NULL && *stocks != NULL) {
        if (max_height > 0 && stocks_count <= STOCKS_MAX_COUNT) {
            double min_price = stocks[0]->prices[stocks[0]->lo_index];
            double max_price = stocks[0]->prices[stocks[0]->hi_index];
            int stop_count = stocks[0]->count;
            
            for (int i = 0; i < stocks_count; ++i) {
                double minp = stocks[i]->prices[stocks[i]->lo_index];
                double maxp = stocks[i]->prices[stocks[i]->hi_index];
                int st = stocks[i]->count;
                
                if (minp < min_price) {
                    min_price = minp;
                }
                
                if (maxp > max_price) {
                    max_price = maxp;
                }
                
                if (st >= stop_count) {
                    stop_count = st;
                }
            }
            
            double price_range = max_price - min_price;
            double plot_step = price_range / max_height;
            
            printf("%s\n", "==MULTIPLOT DATA==");
            printf("max_height: %d\n", max_height);
            printf("stop_count: %d\n", stop_count);
            printf("min price: %.2f\n", min_price);
            printf("max price: %.2f\n", max_price);
            printf("price range: %.2f\n", price_range);
            printf("plot step: %.2f\n", plot_step);
            printf("%s\n", "==LEGEND==");
            
            for (int i = 0; i < stocks_count; ++i) {
                printf("%c : %s\n", stock_chars[i], stocks[i]->data_file);
            }
            
            int hf_size = stocks_count * stop_count;
            
            printf("%10s +", "");
            
            for (int i = 0; i < hf_size; ++i) {
                printf("%s", "-");
            }
            
            printf("%s\n", "+");
            
            for (int h = max_height - 1; h >= 0; --h) {
                double thresh = h * plot_step + min_price;
                
                printf("%10.2f |", thresh);
                
                for (int j = 0; j < stop_count; ++j) {
                    /* For each stock */
                    for (int i = 0; i < stocks_count; ++i) {
                        /* Only print if price at time j for stock i is >= threshold */
                        if (j < stocks[i]->count && stocks[i]->prices[j] >= thresh) {
                            char c = ((j == stocks[i]->hi_index) || (j == stocks[i]->lo_index)) ? toupper(stock_chars[i]) : tolower(stock_chars[i]);
                            
                            printf("%c", c);
                        } else {
                            printf("%s", " ");
                        }
                    }
                }
                
                printf("%s\n", "|");
            }
            
            printf("%10s +", "");
            
            int fs = stocks_count * 5;
            
            for (int i = 0; i < hf_size; ++i) {
                printf("%s", (i % fs == 0) ? "^" : "-");
            }
            
            printf("%s\n", "+");
            
            printf("%11s ", "");
            
            for (int i = 0; i < stop_count; i += 5) {
                printf("%-*d", fs, i);
                
            }
            
            printf("\n");
        } else {
            printf("ERROR: stocks array length %d exceeds max %d", stocks_count, STOCKS_MAX_COUNT);
        }
    }
}

/*
 * OPTIONAL MAKEUP CREDIT: Identical to stock_set_best() except uses a
 * linear time algorithm to determine the best buy/sell times
 */
int stock_set_best_linear(stock_t *stock) {
    int best_found = -1;

    if (stock != NULL && stock->prices != NULL && stock->count > 1) {
        stock->best_buy = 0;
        stock->best_sell = 1;

        int min_index = 0;
        double min_price = stock->prices[0];
        double max_profit = stock->prices[1] - stock->prices[0];

        for (int i = 1; i < stock->count; ++i) {
            double current_profit = stock->prices[i] - min_price;

            if (current_profit > max_profit) {
                max_profit = current_profit;
                stock->best_buy = min_index;
                stock->best_sell = i;
                
                best_found = 0;
            }

            if (stock->prices[i] < min_price) {
                min_price = stock->prices[i];
                min_index = i;
            }
        }

        /* If max profit is not positive, don't set buy/sell */
        if (max_profit <= 0) {
            stock->best_buy = -1;
            stock->best_sell = -1;
        } else {
            best_found = 0;
        }
    }

    return best_found;
}
