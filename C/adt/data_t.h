#ifndef _DATA_T_H
#define _DATA_T_H

/* 
 * Abstract Data Type
 */

typedef struct data_t {
	char *s;
} data_t;

data_t *dt_creat(const char *s);
void dt_free(data_t *dt);
data_t *dt_clone(const data_t *dt);
void dt_dump(const data_t *dt, FILE *stream);

#endif	/* _DATA_T_H */
