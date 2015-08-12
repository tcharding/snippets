#include "tch.h"
#include "data_t.h"

/*
 * Abstract Data Type
 */

/* dt_creat: create and initialise new dt, free with dt_free() */
data_t *dt_creat(const char *s)
{
	data_t *new;
	
	if ((new = (data_t *)malloc(sizeof(data_t))) == NULL)
		return NULL;
	if ((new->s = malloc(sizeof(s))) == NULL) {
		free(new);
		return NULL;
	}
	strcpy(new->s, s);
	return new;
}

/* dt_free: free memory created with dt_creat(), or dt_clone() */
void dt_free(data_t *dt)
{
	if (dt != NULL) {
		free(dt->s);
	}
}

/* dt_clone: return copy of dt, free with dt_free() */
data_t *dt_clone(const data_t *dt)
{
	data_t *new;

	if ((new = dt_creat(dt->s)) == NULL)
		return NULL;
	
	return new;
}

/* dt_dump: write dt to stream */
void dt_dump(const data_t *dt, FILE *stream)
{
	if (dt != NULL) {
		if (dt->s != NULL)
			fprintf(stream, "%s", dt->s);
	} else
		fprintf(stream, "NULL");
			
}
