// Test of pair vs tuples. Using
// rand() to generate the numbers
// and sort() to order them.
// Compiled with
// g++ tupleVSpair.cpp -std=c++11 -o run
#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <tuple>
#include <utility>
#include <algorithm>
using namespace std;

const int MAXN = 1e7;

tuple<int, int> tp_2[MAXN];
tuple<int, int, int> tp_3[MAXN];
tuple<int, int, int, int> tp_4[MAXN];
pair<int, int> pr_2[MAXN];
pair<int, pair<int, int>> pr_3[MAXN];
pair<int, pair<int, pair<int, int>>> pr_4[MAXN];
long int st, tp_fill, tp_sort, pr_fill, pr_sort;

int main ()
{
	srand (clock());
	long int st = clock();

	printf ("All arrays have a size of %d elements, and time measure in clock cicles.\n", MAXN);
	printf ("With two values:\n");
	st = clock ();
	for (int i = 0; i < MAXN; i++)
		tp_2[i] = make_tuple (rand(), rand());
	tp_fill = clock()-st;
	printf ("    Tuple to fill values: %ld\n", tp_fill);
	st = clock ();
	sort (tp_2, tp_2+MAXN);
	tp_sort = clock()-st;
	printf ("    Tuple to sort values: %ld\n", tp_sort);

	st = clock();
	for (int i = 0; i < MAXN; i++)
		pr_2[i] = make_pair(rand(), rand());
	pr_fill = clock()-st;
	printf ("    Pair to fill values: %ld\n", pr_fill);
	st = clock ();
	sort (pr_2, pr_2+MAXN);
	pr_sort = clock()-st;
	printf ("    Pair to sort values: %ld\n", pr_sort);
	printf ("    Pair was %lf times than tuple to fill.\n", (double) tp_fill/pr_fill);
	printf ("    Pair was %lf times than tuple to sort.\n", (double) tp_sort/pr_sort);

	putchar ('\n');

	printf ("With three values:\n");
	st = clock ();
	for (int i = 0; i < MAXN; i++)
		tp_3[i] = make_tuple (rand(), rand(), rand());
	tp_fill = clock()-st;
	printf ("    Tuple to fill values: %ld\n", tp_fill);
	st = clock ();
	sort (tp_3, tp_3+MAXN);
	tp_sort = clock()-st;
	printf ("    Tuple to sort values: %ld\n", tp_sort);

	st = clock();
	for (int i = 0; i < MAXN; i++)
		pr_3[i] = make_pair(rand(), make_pair(rand(), rand()));
	pr_fill = clock()-st;
	printf ("    Pair to fill values: %ld\n", pr_fill);
	st = clock ();
	sort (pr_3, pr_3+MAXN);
	pr_sort = clock()-st;
	printf ("    Pair to sort values: %ld\n", pr_sort);
	printf ("    Pair was %lf times faster than tuple to fill.\n", (double) tp_fill/pr_fill);
	printf ("    Pair was %lf times faster than tuple to sort.\n", (double) tp_sort/pr_sort);

	putchar ('\n');

	printf ("With four values:\n");
	st = clock ();
	for (int i = 0; i < MAXN; i++)
		tp_4[i] = make_tuple (rand(), rand(), rand(), rand());
	tp_fill = clock()-st;
	printf ("    Tuple to fill values: %ld\n", tp_fill);
	st = clock ();
	sort (tp_4, tp_4+MAXN);
	tp_sort = clock()-st;
	printf ("    Tuple to sort values: %ld\n", tp_sort);

	st = clock();
	for (int i = 0; i < MAXN; i++)
		pr_4[i] = make_pair(rand(), make_pair(rand(), make_pair(rand(), rand())));
	pr_fill = clock()-st;
	printf ("    Pair to fill values: %ld\n", pr_fill);
	st = clock ();
	sort (pr_4, pr_4+MAXN);
	pr_sort = clock()-st;
	printf ("    Pair to sort values: %ld\n", pr_sort);
	printf ("    Pair was %lf times faster than tuple to fill.\n", (double) tp_fill/pr_fill);
	printf ("    Pair was %lf times faster than tuple to sort.\n", (double) tp_sort/pr_sort);



	return 0;
}
