#include "tch.h"
#include "data_t.h"
#include "stack.h"
#define INIT 1

static struct {
	int size;
	int cnt;
	data_t **v;
} tab;

/* static prototypes */

/* st_push: add dt to end of tab, return stack size */
int st_push(const data_t *dt)
{
	int size;
	data_t **tmpv;

	if (tab.size == 0) {	/* first time through */
		size = INIT * sizeof(data_t *);
		if ((tab.v = malloc(size)) == NULL)
			err_sys("malloc failed");
		tab.size = INIT;
	} else if (tab.cnt >= tab.size) { /* re-size */
		size = tab.size * 2 * sizeof(data_t *);
		if ((tmpv = realloc(tab.v, size)) == NULL)
			err_sys("realloc failed");
		tab.v = tmpv;
		tab.size = size;
	}
	tab.v[tab.cnt++] = dt_clone(dt); /* insert copy */
	return tab.cnt;
}

/* st_pop: return last element from tab, NULL if tab is empty */
data_t *st_pop(void)
{
	if (tab.cnt <= 0)
		return NULL;
	return tab.v[tab.cnt--];
}

