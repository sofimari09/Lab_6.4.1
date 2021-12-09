#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(double* a, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		a[i] = Low + (double)rand() /RAND_MAX* (High - Low );
	//a[i]=Low + rand() % (High - Low + 1);
}

void Print(double* a, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << a[i];
	cout << endl;
}
int Sum(double* a, const int size)
{
	int S = 0;
	for (int i = 0; i < size; i++)
		if (i%2!=0)
			S += a[i];
	return S;
}
int Sum1(double* a, const int size)
{
	int first, last, i;
	double sum = 0;

	
	for ( first = 0; first < size; first++)
	{
		if (a[first] < 0)
			break;
	}
	for ( last = size - 1; last > first; last--)
	{
		if (a[last] < 0)
			break;
	}
	for (i = first + 1; i < last; i++)
	{
		sum += a[i];
	}
	
	return sum;
}
void del(double* a, const int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (abs(a[i]) < 1)
		{
			for (int j = i; j < size - 1; j++)
			{
				a[j] = a[j + 1];
			}
			a[size - 1] = 0;
		}
	}
}

void Sort(double* a, const int size)
{
	for (int i = 1; i < size; i++)
		for (int j = 0; j < size - i; j++)
		{
			if (abs(a[j]) < 1)
				a[j] = 0;
			if (a[j] == 0)
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
}

int main()
{
	srand((unsigned)time(NULL));

	 int n;
	cout << "n="; cin >> n;
	double* a=new double[n];

	int Low;
	cout << "Low = "; cin >> Low;
	int High;
	cout << "High = "; cin >> High;
	Create(a, n, Low, High);
	Print(a, n);
	cout << "The sum of elements with odd numbers =" << Sum(a,n) << endl;
	cout<<"The sum between first and last elements<0 = "<<Sum1(a,n)<<endl;
	del(a, n);
	 Sort(a, n) ;
	 Print(a, n);
	return 0;
}