// Лабораторна робота № 6.1 (рекурсивний спосіб)
// Варіант 9
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* b, const int size, const int Low, const int High, int i)
{
    b[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(b, size, Low, High, i + 1);
}

void Print(int* b, const int size, int i)
{
    cout << setw(4) << b[i];
    if (i < size - 1)
        Print(b, size, i + 1);
    else
        cout << endl;
}

int Count(int* b, const int size, int i)
{
    if (i < size)
    {
        if (b[i] > 0 && b[i] % 2 != 0)
            return 1 + Count(b, size, i + 1);
        else
            return Count(b, size, i + 1);
    }
    else
        return 0;
}

int Sum(int* b, const int size, int i)
{
    if (i < size)
    {
        if (b[i] > 0 && b[i] % 2 != 0)
            return b[i] + Sum(b, size, i + 1);
        else
            return Sum(b, size, i + 1);
    }
    else
        return 0;
}

void Zero(int* b, const int size, int i)
{
    if (b[i] > 0 && b[i] % 2 != 0)
        b[i] = 0;
    if (i < size - 1)
        Zero(b, size, i + 1);
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 23;
    int b[n];

    int Low = -25;
    int High = 80;

    Create(b, n, Low, High, 0);
    Print(b, n, 0);

    cout << "Count = " << Count(b, n, 0) << endl;
    cout << "Sum   = " << Sum(b, n, 0) << endl;

    Zero(b, n, 0);
    Print(b, n, 0);

    return 0;
}