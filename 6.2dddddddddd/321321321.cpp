// Лабораторна робота № 6.3. Варіант 9. Ітераційний спосіб
// Завдання: функція, яка обчислює суму непарних елементів масиву цілих чисел.
// Реалізовано: 1) звичайні функції; 2) шаблони функцій.

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

// ---------- звичайні функції ----------
void Create(int* a, const int size, const int Low, const int High);
void Print(int* a, const int size);
int  SumOdd(int* a, const int size);

// ---------- шаблони функцій ----------
template <typename T>
void Create(T* a, const int size, const int Low, const int High);

template <typename T>
void Print(T* a, const int size);

template <typename T>
T SumOdd(T* a, const int size);

int main()
{
    srand((unsigned)time(NULL));          // ініціалізація генератора випадкових чисел

    const int n = 10;                     // кількість елементів
    const int Low = -20;                  // нижня межа діапазону
    const int High = 50;                  // верхня межа діапазону

    // --- 1) звичайні функції ---
    cout << "=== Звичайні функції ===" << endl;
    int a[n];
    Create(a, n, Low, High);
    cout << "a = ";
    Print(a, n);
    cout << "Сума непарних елементів = " << SumOdd(a, n) << endl << endl;

    // --- 2) шаблони функцій ---
    cout << "=== Шаблони функцій ===" << endl;

    int b[n];
    Create<int>(b, n, Low, High);
    cout << "b (int) = ";
    Print<int>(b, n);
    cout << "Сума непарних елементів = " << SumOdd<int>(b, n) << endl;

    long long c[n];
    Create<long long>(c, n, Low, High);
    cout << "c (long long) = ";
    Print<long long>(c, n);
    cout << "Сума непарних елементів = " << SumOdd<long long>(c, n) << endl;

    return 0;
}

// ---------- звичайні функції ----------

// формування масиву випадковими числами з діапазону [Low; High]
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// виведення масиву в рядок
void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// сума непарних елементів
int SumOdd(int* a, const int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
        if (a[i] % 2 != 0)        // != 0, а не == 1, щоб коректно працювало для від'ємних
            s += a[i];
    return s;
}

// ---------- шаблони функцій ----------

template <typename T>
void Create(T* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

template <typename T>
void Print(T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

template <typename T>
T SumOdd(T* a, const int size)
{
    T s = T();                    // нульове значення
    for (int i = 0; i < size; i++)
        if (a[i] % 2 != 0)
            s += a[i];
    return s;
}