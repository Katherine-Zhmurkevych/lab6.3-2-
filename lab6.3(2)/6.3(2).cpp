//рекурсивний спосіб
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void create(int* a, const int size, const int Low, const int High, int index)
{
	a[index] = Low + rand() % (High - Low + 1);
	if (index < size - 1)
		create(a, size, Low, High, index + 1);
}
void print(int* a, const int size, int index)
{
	cout << setw(4) << a[index];
	if (index < size - 1)
		print(a, size, index + 1);
	else
		cout << endl;
}
int calculateAmountOfPositiveNumbers(int* a, const int size, int index, int amount)
{
	if (index == size)
	{
		return amount;
	}
	else 
		if (a[index] > 0)
		{
			amount++;
			index++;
			calculateAmountOfPositiveNumbers(a, size, index, amount);
		}
		else
		{
			index++;
			calculateAmountOfPositiveNumbers(a, size, index, amount);
		}
}
int main()
{
	srand((unsigned)time(NULL)); 
	const int n = 5;
	int a[n];
	int Low = -100;
	int High = 100;
	int index = 0;
	int amount = 0;
	create(a, n, Low, High, 0);
	print(a, n, 0);
	cout << "amount of positive nubers in array is " << calculateAmountOfPositiveNumbers(a, n, index, amount);
	return 0;
}