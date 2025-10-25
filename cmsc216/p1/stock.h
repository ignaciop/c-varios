/* stock.h: header for stock plotting problem */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>              /* for toupper() / tolower() */

typedef struct {
  char *data_file;              /* name of the data file stock data was loaded from */
  int count;                    /* length of prices array */
  double *prices;               /* array of stock prices at different time points */
  int lo_index;                 /* index of the lowest price */
  int hi_index;                 /* index of the highest price */
  int best_buy;                 /* index at which to buy to get best profit */
  int best_sell;                /* index at which to sell to get best profit */
} stock_t;

/* stock_funcs.c */
void stock_print(const stock_t *stock);
stock_t *stock_new(void);
void stock_free(stock_t *stock);
void stock_set_hilo(stock_t *stock);
int stock_set_best(stock_t *stock);
int count_lines(const char *filename);
int stock_load(stock_t *stock, const char *filename);
void stock_plot(const stock_t *stock, const int max_height, const int start, const int stop);
void stock_multiplot(stock_t **stocks, const int stocks_count, const int max_height);
stock_t **stock_load_all(char *filenames[], const int stock_count);
int stock_set_best_linear(stock_t *stock);
