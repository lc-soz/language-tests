//Test the imprecision of pow function
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function receives two values. Returns
// a^b, calculate this with a loop.
long long unsigned pow_loop (long long unsigned a, int b)
{
	long long unsigned ans = a;
	for (int i = 1; i < b; i++)
		ans *= a;
	return ans;
}

int main (void)
{
	long long unsigned dif;
	for (long long unsigned i = 1e7; i < 4e9; i+=1) {
		dif = abs(pow_loop (i, 2) - (long long) pow(i, 2));
		if (dif) {
			printf ("%llu %llu %llu %llu\n", i, pow_loop (i, 2), (long long unsigned) pow (i, 2), dif);
			break;
		}
	}

	return 0;
}
