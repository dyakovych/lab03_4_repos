// Лабораторна робота № 6.1 (ітераційний спосіб)
// Варіант 9
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* b, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        b[i] = Low + rand() % (High - Low + 1);
}

void Print(int* b, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << b[i];
    cout << endl;
}

int Count(int* b, const int size)
{
    int k = 0;
    for (int i = 0; i < size; i++)
        if (b[i] > 0 && b[i] % 2 != 0)
            k++;
    return k;
}

int Sum(int* b, const int size)
{
    int S = 0;
    for (int i = 0; i < size; i++)
        if (b[i] > 0 && b[i] % 2 != 0)
            S += b[i];
    return S;
}

void Zero(int* b, const int size)
{
    for (int i = 0; i < size; i++)
        if (b[i] > 0 && b[i] % 2 != 0)
            b[i] = 0;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 23;
    int b[n];

    int Low = -25;
    int High = 80;

    Create(b, n, Low, High);
    Print(b, n);

    cout << "Count = " << Count(b, n) << endl;
    cout << "Sum   = " << Sum(b, n) << endl;

    Zero(b, n);
    Print(b, n);

    return 0;
}