#include <iostream>
#include <iomanip>
#include <random>
#include <ctime>
#define long long long

using namespace std;

const int m = 1000;
int a[m], i;

void quickSort(int l, int r, int s)
{
	int i = 0, j = r - 1, x, mid;

	cerr << "quickSort " << setw(6) << l << setw(6) << r << setw(3) << s << endl;

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

	if (j > l) quickSort(l, j, s + 1);
	if (r > i) quickSort(i, r, s + 1);
}

int main()
{
	srand(time(0));

	for (i = 0; i < m; i++)
	{
		a[i] = rand();
	}

	quickSort(0, m, 0);

	return 0;
}