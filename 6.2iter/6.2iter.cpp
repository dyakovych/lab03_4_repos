// Лабораторна робота № 6.2 (ітераційний спосіб)
// Варіант 9
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// сума індексів непарних елементів
int SumIndexOdd(int* a, const int size)
{
    int S = 0;
    for (int i = 0; i < size; i++)
        if (a[i] % 2 != 0)
            S += i;
    return S;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 15;
    int a[n];

    int Low = -10;
    int High = 10;

    Create(a, n, Low, High);
    Print(a, n);

    cout << "Sum of indices = " << SumIndexOdd(a, n) << endl;

    return 0;
}