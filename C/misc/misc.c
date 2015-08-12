/* nunits: get number of required to hold 'n' units in 'b' size chunks */
int nunits(int b, int n)
{
	return ((n - 1) / b);
}
