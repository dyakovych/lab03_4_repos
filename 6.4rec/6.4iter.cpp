// Лабораторна робота № 6.4 (рекурсивний спосіб, функції викликають самі себе)
// Варіант 9.
// У динамічному масиві з n дійсних елементів:
//   1.1. знайти максимальний за модулем елемент;
//   1.2. обчислити суму елементів між першим і другим додатними елементами.
//   2.   переставити елементи так, щоб нулі були в кінці
//        (відносний порядок інших елементів не змінюється).
// Розмір n вводиться з клавіатури.
// Параметр i - номер елемента, який обробляється зараз.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <time.h>

using namespace std;

// Заповнює a[i], потім викликає себе для наступного елемента
void Create(double* a, const int size, const double Low, const double High, int i)
{
    a[i] = Low + (rand() % (int)((High - Low) * 2 + 1)) / 2.0;
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// Виводить a[i], потім викликає себе для наступного елемента
void Print(double* a, const int size, int i)
{
    cout << setw(6) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// 1.1. ПОВЕРТАЄ елемент з найбільшим модулем.
// max - найкращий елемент, знайдений серед попередніх (спочатку a[0]).
double MaxAbs(double* a, const int size, int i, double max)
{
    if (i < size)
    {
        if (fabs(a[i]) > fabs(max))
            max = a[i];
        return MaxAbs(a, size, i + 1, max);
    }
    else
        return max;                       // елементи закінчились - повертаємо результат
}

// ПОВЕРТАЄ індекс першого додатного елемента, починаючи з номера i (або -1)
int FindPositive(double* a, const int size, int i)
{
    if (i < size)
    {
        if (a[i] > 0)
            return i;
        else
            return FindPositive(a, size, i + 1);
    }
    else
        return -1;                        // додатного не знайшли
}

// 1.2. ПОВЕРТАЄ суму елементів з номерами від i до to - 1
double SumBetween(double* a, const int to, int i)
{
    if (i < to)
        return a[i] + SumBetween(a, to, i + 1);
    else
        return 0;
}

// 2. Зсуває ненульові елементи на початок, зберігаючи порядок.
// k - куди записати наступний ненульовий елемент. ПОВЕРТАЄ кількість ненульових.
int Compact(double* a, const int size, int i, int k)
{
    if (i < size)
    {
        if (a[i] != 0)
        {
            a[k] = a[i];
            return Compact(a, size, i + 1, k + 1);
        }
        else
            return Compact(a, size, i + 1, k);
    }
    else
        return k;
}

// Записує нулі в елементи, починаючи з номера i
void FillZeros(double* a, const int size, int i)
{
    if (i < size)
    {
        a[i] = 0;
        FillZeros(a, size, i + 1);
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int n;
    cout << "n = ";
    cin >> n;

    double* a = new double[n];

    double Low = -5;
    double High = 5;

    Create(a, n, Low, High, 0);
    cout << fixed << setprecision(1);
    Print(a, n, 0);

    // 1.1 (починаємо з a[1], найбільшим вважаємо a[0])
    cout << "Max abs element = " << MaxAbs(a, n, 1, a[0]) << endl;

    // 1.2
    int first = FindPositive(a, n, 0);
    int second = -1;
    if (first != -1)
        second = FindPositive(a, n, first + 1);

    if (first != -1 && second != -1)
        cout << "Sum between 1st and 2nd positive = " << SumBetween(a, second, first + 1) << endl;
    else
        cout << "There are less than two positive elements" << endl;

    // 2
    int k = Compact(a, n, 0, 0);
    FillZeros(a, n, k);
    Print(a, n, 0);

    delete[] a;
    return 0;
}