#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

int fact(int n)
{
	int fact = 1;
	int k;
	for (k = 1; k <= n; k++);
	{
		fact = fact * k;
	}
	return fact;
}

void replacements(int n)
{
	int* a = new int[n];
	for (int k = 0; k < n; k++)
	{
		a[k] = k + 1;
	}

	sort(a, a + n);
	cout << n << "! =" << fact(n) << "replacements from" << n << " elements:" << endl;
	do
	{
		for (int k = 0; k < n; k++)
		{
			cout << setw(2) << a[k];
		}
		cout << endl;
	} while (next_permutation(a, a + n));
}

void kombs(int n, int r)
{
	vector<bool> v(n);

	fill(v.begin(), v.begin() + r, true);

	cout << n << "! / (" << r << "! * (" << n << " - " << r << ")) \n (" << fact(n) / (fact(r) * fact(n - r)) << ") Combinations with " << n << " by " << r << ":" << endl;
	do
	{
		for (int i = 0; i < n; ++i)
		{
			if (v[i])
			{
				cout << setw(2) << (i + 1);
			}
		}
		cout << endl;
	} while (prev_permutation(v.begin(), v.end()));
}

void taskone()
{
	int n = 0;
	cout << "TASK 1: \nn = ";
	cin >> n;

	replacements(n);
}

void tasktwo()
{
	int n = 0;
	int r = 0;
	cout << endl;
	cout << "TASK 2:\nwith(n) = ";
	cin >> n;
	cout << "by(r) = ";
	cin >> r;
	cout << endl;
	r = abs(r);

	kombs(n, r);
}

int main()
{
	taskone();
	tasktwo();
}