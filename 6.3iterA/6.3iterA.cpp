// 6.3iter.cpp
// Лабораторна робота № 6.3
// Ітераційний спосіб, варіант 9

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Звичайна функція
int Sum(int* a, const int size)
{
    int S = 0;

    for (int i = 0; i < size; i++)
        if (a[i] % 2 != 0)
            S += a[i];

    return S;
}

// Шаблон функції
template <typename T>
T Sum(T* a, const int size)
{
    T S = T();

    for (int i = 0; i < size; i++)
        if (a[i] % 2 != 0)
            S += a[i];

    return S;
}

// Формування масиву
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// Виведення масиву
void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];

    cout << endl;
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 10;
    int a[n];

    int Low = -10;
    int High = 10;

    Create(a, n, Low, High);

    cout << "Array:" << endl;
    Print(a, n);

    cout << "Sum(a, n) = " << Sum(a, n) << endl;

    cout << "Sum<int>(a, n) = " << Sum<int>(a, n) << endl;

    return 0;
}
