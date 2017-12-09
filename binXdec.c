#include <stdio.h>
#include <time.h>

// Receives amount of times that it
// should cycle through values in
// binary.
long fun_bin (long long unsigned a)
{
	long long unsigned x = 1;
	long now = clock();
	for (long long unsigned i = 0; i < a; i++) {
		for (int j = 0; j < 18; j++)
			a << 1;
		for (int j = 0; j < 18; j++)
			a >> 1;
	}
	return clock() - now;
}

// Receives amount of times that it
// should cycle through values in
// decimal.
long fun_dec (long long unsigned a)
{
	long long unsigned x = 1;
	long now = clock();
	for (long long unsigned i = 0; i < a; i++) {
		for (int j = 0; j < 18; j++)
			a * 2;
		for (int j = 0; j < 18; j++)
			a / 2;
	}
	return clock() - now;
}

int main (void)
{
	long long unsigned MAXN = 1e7;
	int ans = 0;
	for (int i = 0; i < 1e4; i++) {
		ans = fun_bin (MAXN) - fun_dec (MAXN);
		printf ("%d\n", ans);
	}
	return 0;
}
