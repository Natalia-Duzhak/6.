#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* a, int n,const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < n - 1)
		Create(a, n, Low, High, i + 1);
}
void Print(int* a, int n, int i)
{
	cout  << setw(2)  << setw(4) << a[i] << " ";
	if (i < n - 1)
		Print(a, n, i + 1);
	else
		cout << endl;
}
int Max(int* a, int n, int i, int max)
{
	if  ((a[i] > max)&&((a[i] % 2) == 0))
		max = a[i];
	if (i < n - 1)
		return Max(a, n, i + 1, max);
	else
		return max;
}
int main()
{
	int n, Low, High;
	srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
	cout << "number of elements: "; cin >> n;
	cout << "the minimum value : "; cin >> Low;
	cout << "the maximum value : "; cin >> High;
	int* a = new int[n];
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	cout << "max even number = " << Max(a, n, 1, a[0]) << endl;
	delete[]a;
	return 0;
}