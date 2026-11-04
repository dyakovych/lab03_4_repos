// 6.3rec.cpp
// Лабораторна робота № 6.3
// Рекурсивний спосіб, варіант 9

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Звичайна рекурсивна функція
int Sum(int* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] % 2 != 0)
            return a[i] + Sum(a, size, i + 1);
        else
            return Sum(a, size, i + 1);
    }
    else
        return 0;
}

// Шаблон рекурсивної функції
template <typename T>
T Sum(T* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] % 2 != 0)
            return a[i] + Sum<T>(a, size, i + 1);
        else
            return Sum<T>(a, size, i + 1);
    }
    else
        return T();
}

// Формування масиву
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);

    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// Виведення масиву
void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];

    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n];

    int Low = -10;
    int High = 10;

    Create(a, n, Low, High, 0);

    cout << "Array:" << endl;
    Print(a, n, 0);

    cout << "Sum(a, n) = " << Sum(a, n, 0) << endl;

    cout << "Sum<int>(a, n) = " << Sum<int>(a, n, 0) << endl;

    return 0;
}