#ifndef _STACK_H
#define _STACK_H
#include "data_t.h"

/* 
 * Stack of data_t objects
 */


int st_push(const data_t *);
data_t *st_pop(void);

#endif	/* _STACK_H */
