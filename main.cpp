#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#include <vector>
#include <queue>
#define long long long

using namespace std;

const int m = 100000;
int a[m], i, b[m], pqs;
long t0, t;

int Psort(int l, int r, int s);

int quicksort(int l, int r, int s)
{
	int i = 0, j = r - 1, x, mid;

	//cerr << "quicksort         " << setw(7) << l << setw(7) << r << setw(7) << r - l << setw(4) << s << endl;

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

	if (j > l) Psort(l, j, s + 1);
	if (r > i) Psort(i, r, s + 1);
	return 0;
}

int mergesort(int l, int r, int s)
{
	if (l == r) return 0;

	int m, k, i, j;

	//cerr << "     mergesort    " << setw(7) << l << setw(7) << r << setw(7) << r - l << setw(4) << s << endl;

	m = (l + r) / 2;
	Psort(l, m, s + 1);
	Psort(m + 1, r, s + 1);
	k = l; i = l; j = m + 1;
	while (k <= r)
		if (i <= m && (j > r || a[i] < a[j]))
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	for (i = l; i <= r; i++)
		a[i] = b[i];
	return 0;
}

int priorityqueuesort(int l, int r, int s)
{
	priority_queue <int> h;
	int i;

	//cerr << "priorityqueuesort " << setw(7) << l << setw(7) << r << setw(7) << r - l << setw(4) << s << endl;

	for (i = l; i <= r; i++)
	{
		h.push(a[i]);
	}
	for (i = r; i >= l; i--)
	{
		a[i] = h.top();
		h.pop();
	}
	return 0;
}

int Psort(int l, int r, int s)
{
	if (r - l <= pqs)
		priorityqueuesort(l, r, s);
	else if (rand() % 2)
		quicksort(l, r, s);
	else
		mergesort(l, r, s);
	return 0;
}

int main()
{
	srand(time(0));
	pqs = min(max(10, m / 100), 512);

	for (i = 0; i < m; i++)
	{
		a[i] = rand();
	}

	t0 = clock();
	Psort(0, m, 0);
	t = clock() - t0;

	return 0;
}