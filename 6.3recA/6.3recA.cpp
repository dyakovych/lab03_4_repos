// 6.3recA.cpp
// Лабораторна робота № 6.3 (рекурсивний спосіб), варіант 9
// Функція, яка обчислює суму непарних елементів масиву цілих чисел.
// Звичайна рекурсивна функція та шаблон рекурсивної функції.
#include <iostream>
#include <iomanip>

using namespace std;

// ---- звичайні рекурсивні функції (масив int) ----
int SumOdd(int* a, const int size, int i);   // сума непарних елементів
void Print(int* a, const int size, int i);   // виведення масиву рядком

// ---- шаблони рекурсивних функцій (цілі типи) ----
template <typename T>
T SumOdd(T* a, const int size, int i);

template <typename T>
void Print(T* a, const int size, int i);

int main()
{
    const int n = 10;

    // 1) звичайні функції
    int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Print(a, n, 0);
    int s1 = SumOdd(a, n, 0);
    cout << "SumOdd(a, n, 0) = " << s1 << endl;

    // 2) шаблони функцій
    int s2 = SumOdd<int>(a, n, 0);
    cout << "SumOdd<int>(a, n, 0) = " << s2 << endl;

    long long b[n] = { -3, 2, 7, 4, -5, 6, 9, 8, 1, 10 };
    Print<long long>(b, n, 0);
    long long s3 = SumOdd<long long>(b, n, 0);
    cout << "SumOdd<long long>(b, n, 0) = " << s3 << endl;

    short c[n] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    Print<short>(c, n, 0);
    short s4 = SumOdd<short>(c, n, 0);
    cout << "SumOdd<short>(c, n, 0) = " << s4 << endl;

    return 0;
}

// рекурсивна сума непарних елементів, i – індекс поточного елемента
int SumOdd(int* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] % 2 != 0)
            return a[i] + SumOdd(a, size, i + 1);
        else
            return SumOdd(a, size, i + 1);
    }
    else
        return 0;
}

// рекурсивне виведення елементів масиву в один рядок
void Print(int* a, const int size, int i)
{
    if (i < size)
    {
        cout << setw(4) << a[i];
        Print(a, size, i + 1);
    }
    else
        cout << endl;
}

// шаблон: рекурсивна сума непарних елементів (T – цілий тип)
template <typename T>
T SumOdd(T* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] % 2 != 0)
            return a[i] + SumOdd<T>(a, size, i + 1);
        else
            return SumOdd<T>(a, size, i + 1);
    }
    else
        return T();
}

// шаблон: рекурсивне виведення елементів масиву в один рядок
template <typename T>
void Print(T* a, const int size, int i)
{
    if (i < size)
    {
        cout << setw(4) << a[i];
        Print<T>(a, size, i + 1);
    }
    else
        cout << endl;
}