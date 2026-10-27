// Лабораторна робота № 6.4 (ітераційний спосіб, через цикли)
// Варіант 9.
// У динамічному масиві з n дійсних елементів:
//   1.1. знайти максимальний за модулем елемент;
//   1.2. обчислити суму елементів між першим і другим додатними елементами.
//   2.   переставити елементи так, щоб нулі були в кінці
//        (відносний порядок інших елементів не змінюється).
// Розмір n вводиться з клавіатури.

#include <iostream>
#include <iomanip>
#include <cmath>      // fabs - модуль дійсного числа
#include <time.h>

using namespace std;

// Заповнює масив дійсними числами від Low до High з кроком 0.5
void Create(double* a, const int size, const double Low, const double High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + (rand() % (int)((High - Low) * 2 + 1)) / 2.0;
}

// Виводить масив в один рядок (кожне число займає 6 позицій)
void Print(double* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(6) << a[i];
    cout << endl;
}

// 1.1. ПОВЕРТАЄ елемент, у якого найбільший модуль
double MaxAbs(double* a, const int size)
{
    double max = a[0];                    // спочатку вважаємо найбільшим перший елемент
    for (int i = 1; i < size; i++)
        if (fabs(a[i]) > fabs(max))       // порівнюємо МОДУЛІ, а зберігаємо саме число
            max = a[i];
    return max;
}

// ПОВЕРТАЄ індекс першого додатного елемента, починаючи з номера start.
// Якщо такого немає - повертає -1.
int FindPositive(double* a, const int size, int start)
{
    for (int i = start; i < size; i++)
        if (a[i] > 0)
            return i;
    return -1;
}

// 1.2. ПОВЕРТАЄ суму елементів між індексами first і second
// (самі елементи first і second не входять)
double SumBetween(double* a, const int first, const int second)
{
    double s = 0;
    for (int i = first + 1; i < second; i++)
        s += a[i];
    return s;
}

// 2. Зсуває всі ненульові елементи на початок масиву, зберігаючи порядок.
// ПОВЕРТАЄ кількість ненульових елементів.
int Compact(double* a, const int size)
{
    int k = 0;                            // куди записати наступний ненульовий елемент
    for (int i = 0; i < size; i++)
        if (a[i] != 0)
        {
            a[k] = a[i];
            k++;
        }
    return k;
}

// Записує нулі в усі елементи, починаючи з номера from
void FillZeros(double* a, const int size, const int from)
{
    for (int i = from; i < size; i++)
        a[i] = 0;
}

int main()
{
    srand((unsigned)time(NULL));

    int n;
    cout << "n = ";
    cin >> n;

    double* a = new double[n];            // динамічний масив із n елементів

    double Low = -5;
    double High = 5;

    Create(a, n, Low, High);
    cout << fixed << setprecision(1);     // одна цифра після коми
    Print(a, n);

    // 1.1
    cout << "Max abs element = " << MaxAbs(a, n) << endl;

    // 1.2
    int first = FindPositive(a, n, 0);                 // перший додатний
    int second = -1;
    if (first != -1)
        second = FindPositive(a, n, first + 1);        // другий додатний - шукаємо після першого

    if (first != -1 && second != -1)
        cout << "Sum between 1st and 2nd positive = " << SumBetween(a, first, second) << endl;
    else
        cout << "There are less than two positive elements" << endl;

    // 2
    int k = Compact(a, n);                // ненульові - на початок
    FillZeros(a, n, k);                   // решту заповнюємо нулями
    Print(a, n);

    delete[] a;                           // звільняємо пам'ять
    return 0;
}