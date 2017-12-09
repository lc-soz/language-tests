#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <queue>

const int DIF_TESTS = 100, TESTS = 10, ARR_SIZE = 2e5;

int i, j, k;
int base[ARR_SIZE], arr[ARR_SIZE];
long int bef, now, avr_sort, avr_pq;
double avr_dif;
std::priority_queue <int> pq;

int main (void) {
	srand (time(NULL));
	printf ("|  SORT  |   PQ   | SORT/PQ |\n");
	for (k = 0; k < DIF_TESTS; k++) {
		avr_sort = avr_pq = 0;
		for (i = 0; i < ARR_SIZE; i++)
			base[i] = rand();
		for (i = 0; i < ARR_SIZE; i++)
			arr[i] = base[i];
		//puts("SORT");
		for (i = 0; i < TESTS+2; i++) {
			bef = clock();
			std::sort (arr, arr+ARR_SIZE);
			now = clock()-bef;
			if (i > 1) {
				avr_sort += now;
				//printf ("%8ld %8ld\n", now, avr_sort/(i-1));
			}
			for (j = 0; j < ARR_SIZE; j++)
				arr[j] = base[j];
		}
		avr_sort /= i-2;
		//puts("\nPRIORITY_QUEUE");
		for (i = 0; i < TESTS+2; i++) {
			bef = clock();
			for (j = 0; j < ARR_SIZE; j++)
				pq.push (base[i]);
			now = clock()-bef;
			if (i > 1) {
				avr_pq += now;
				//printf ("%8ld %8ld\n", now, avr_pq/(i-1));
			}
			while (!pq.empty())
				pq.pop();
		}
		avr_pq /= i-2;
		//puts ("");
		avr_dif += (double)avr_sort/avr_pq;
		printf ("|%8ld|%8ld|%.7lf|\n", avr_sort, avr_pq, avr_dif/(k+1));
	}

	return 0;
}
