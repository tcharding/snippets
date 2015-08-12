/* attribution: UNIX Systems Programming - Robbins and Robbins */

/* external linkage */
int getcount(void);
void clearcount(void);
void bubblesort(int a[], int n);

/* internal linkage */
static int onepass(int a[], int n);
static int count = 0;

/* bubblesort: a[0] < a[1] .. < a[n-1] */
void bubblesort(int a[], int n)
{
	int i;

	for (i = 0; i < n-1; i++)
		if (!onepass(a, n-i))
			break;
}

void clearcount(void)
{
	count = 0;
}

int getcount(void)
{
	return count;
}

/* onepass: return true if interchanges are made */
static int onepass(int a[], int n)
{
	int i, interchanges, tmp;

	for (i = 0; i < n-1; i++)
		if (a[i] > a[i+1]) {
			tmp = a[i];
			a[i] = a[i+1];
			a[i+1] = tmp;
			interchanges = 1;
			count++;
		}
	return interchanges;
}

