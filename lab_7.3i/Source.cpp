#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int k, const int n, const int Low,
	const int High);
void Input(int** a, const int k, const int n);
void Print(int** a, const int k, const int n);
int Sum(int** a, const int k, const int n, int& S);
int main()
{
	srand((unsigned)time(NULL));
	//int Low = -17;
	//int High = 15;
	int k, n;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;
	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	//Create(a, k, n, Low, High);
	Input(a, k, n);
	Print(a, k, n);
	int S = 0;
	if (Sum(a, k, n, S) > 0)
		cout << "count = " << S << endl;
	else
		cout << "there are no rows without negative elements" << endl;
	cout << endl;
	return 0;
}
void Create(int** a, const int k, const int n, const int Low,
	const int High)
{
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Input(int** a, const int k, const int n)
{
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << "a[" << i << "][" << j << "] = ";
				cin >> a[i][j];
			}
			cout << endl;
		}
}
void Print(int** a, const int k, const int n)
{
	cout << endl;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
int Sum(int** a, const int k, const int n, int& S)
{
	int count;
	for (int j = 0; j < n; j++)
	{
		count = 0;
		for (int i = 0; i < k; i++)
			if (a[i][j] < 0)
			{
				count++;
				break;
			}
		if (count == 0)
		{
			for (int i = 0; i < k; i++)
				if (a[i][j] >= 0)
					S +=a[i][j];
		}
	}

	return S;
}

