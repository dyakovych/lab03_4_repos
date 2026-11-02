// Lab6.3iterA.cpp
// Лабораторна робота № 6.3 (ітераційний спосіб), варіант 9
// Функція, яка обчислює суму непарних елементів масиву цілих чисел.
// Звичайна функція та шаблон функції.
#include <iostream>
#include <iomanip>

using namespace std;

// ---- звичайні функції (масив int) ----
int SumOdd(int* a, const int size);          // сума непарних елементів
void Print(int* a, const int size);          // виведення масиву рядком

// ---- шаблони функцій (універсальний алгоритм для цілих типів) ----
template <typename T>
T SumOdd(T* a, const int size);

template <typename T>
void Print(T* a, const int size);

int main()
{
    const int n = 10;

    // 1) звичайні функції
    int a[n] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    Print(a, n);
    int s1 = SumOdd(a, n);
    cout << "SumOdd(a, n) = " << s1 << endl;

    // 2) шаблони функцій
    int s2 = SumOdd<int>(a, n);
    cout << "SumOdd<int>(a, n) = " << s2 << endl;

    long long b[n] = { -3, 2, 7, 4, -5, 6, 9, 8, 1, 10 };
    Print<long long>(b, n);
    long long s3 = SumOdd<long long>(b, n);
    cout << "SumOdd<long long>(b, n) = " << s3 << endl;

    short c[n] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
    Print<short>(c, n);
    short s4 = SumOdd<short>(c, n);
    cout << "SumOdd<short>(c, n) = " << s4 << endl;

    return 0;
}

// сума непарних елементів масиву цілих чисел
int SumOdd(int* a, const int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
        if (a[i] % 2 != 0)          // непарний (враховує й від'ємні числа)
            s += a[i];
    return s;
}

// виведення елементів масиву в один рядок
void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// шаблон: сума непарних елементів (T – цілий тип)
template <typename T>
T SumOdd(T* a, const int size)
{
    T s = T();                      // присвоїли нульове значення
    for (int i = 0; i < size; i++)
        if (a[i] % 2 != 0)
            s += a[i];
    return s;
}

// шаблон: виведення елементів масиву в один рядок
template <typename T>
void Print(T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}