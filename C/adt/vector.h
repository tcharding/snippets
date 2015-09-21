y#ifndef _VECTOR_H
#define _VECTOR_H

/* 
 * Vector of data_t objects (non-orthogonal)
 */

typedef struct vec {
	int size;
	int cnt;
	data_t **v;
} vec_t;

vec_t *v_creat(void);
void v_free(vec_t *vt);
int v_adds(vec_t *vt, const char *s);
int v_foreach(vec_t *vt, int (*fnc)(char *));
char **v_dup(vec_t *vt);

#endif	/* _VECTOR_H */
