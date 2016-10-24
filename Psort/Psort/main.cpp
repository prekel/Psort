#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#define long long long

using namespace std;

const int m = 100;
int a[m], i, b[m];

void quicksort(int l, int r, int s)
{
	int i = 0, j = r - 1, x, mid;

	cerr << "quicksort " << setw(6) << l << setw(6) << r << setw(3) << s << endl;

	mid = (l + r) / 2;
	x = a[mid];

	i = l;
	j = r;

	while (i <= j)
	{
		while (a[i] < x) i++;
		while (a[j] > x) j--;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}

	if (j > l) quicksort(l, j, s + 1);
	if (r > i) quicksort(i, r, s + 1);
}

int mergesort(int l, int r, int s)
{
	if (l == r) return 0;

	int m, k, i, j;

	cerr << "mergesort " << setw(6) << l << setw(6) << r << setw(3) << s << endl;

	m = (l + r) / 2;
	mergesort(l, m, s + 1);
	mergesort(m + 1, r, s + 1);
	k = l; i = l; j = m + 1;
	while (k <= r)
		if (i <= m && (j > r || a[i] < a[j]))
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	for (i = l; i <= r; i++)
		a[i] = b[i];
}

int main()
{
	srand(time(0));

	for (i = 0; i < m; i++)
	{
		a[i] = rand();
	}

	mergesort(0, m, 0);

	return 0;
}