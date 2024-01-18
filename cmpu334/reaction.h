#ifndef REACTION_H
#define REACTION_H

#include <pthread.h>

struct reaction {
	int oxygen_count;
	int hydrogen_count;
	pthread_mutex_t lock;
	pthread_cond_t oxygen_cond;
	pthread_cond_t hydrogen_cond;
};

/* Forward declaration. This function is implemented in reaction-runner.c,
 * but you needn't care what it does. Just be sure it's called when
 * appropriate within reaction_o()/reaction_h().
 */
void make_water();
void reaction_init(struct reaction *reaction);
void reaction_h(struct reaction *reaction);
void reaction_o(struct reaction *reaction);

#endif