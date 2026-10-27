// Лабораторна робота № 6.3 (рекурсивний спосіб)
// Варіант 9: функція, яка обчислює суму непарних елементів масиву цілих чисел.
// Робимо двома способами: звичайна функція і шаблон функції.
//
// Параметр i - номер елемента, який обробляється зараз. Починаємо з i = 0.

#include <iostream>
#include <iomanip>

using namespace std;

void Print(int* a, const int size, int i);

template <typename T>
void Print(T* a, const int size, int i);

int SumOdd(int* a, const int size, int i);

template <typename T>
T SumOdd(T* a, const int size, int i);

int main()
{
    const int n = 10;

    int a[n] = { 1, 2, 3, 4, 5, -7, 8, 9, 10, 11 };
    Print(a, n, 0);
    int s1 = SumOdd(a, n, 0);
    cout << "SumOdd(a, n) = " << s1 << endl;

    int s2 = SumOdd<int>(a, n, 0);
    cout << "SumOdd<int>(a, n) = " << s2 << endl;

    long b[n] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    Print<long>(b, n, 0);
    long s3 = SumOdd<long>(b, n, 0);
    cout << "SumOdd<long>(b, n) = " << s3 << endl;

    return 0;
}

// Виводить a[i], потім викликає себе для наступного елемента
void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;                // після останнього - новий рядок
}

template <typename T>
void Print(T* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print<T>(a, size, i + 1);
    else
        cout << endl;
}

// Звичайна функція: сума непарних елементів, починаючи з номера i
int SumOdd(int* a, const int size, int i)
{
    if (i < size)                    // поки елементи ще є
    {
        if (a[i] % 2 != 0)           // непарний: додаємо його + сума решти
            return a[i] + SumOdd(a, size, i + 1);
        else                         // парний: просто йдемо далі
            return SumOdd(a, size, i + 1);
    }
    else
        return 0;                    // елементи закінчились - зупинка рекурсії
}

// Шаблон: та сама логіка для будь-якого цілого типу T
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
        return T();                  // нульове значення типу T
}