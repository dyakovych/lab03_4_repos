// Варіант 9: сума непарних елементів масиву цілих чисел
#include <iostream>
#include <iomanip>
using namespace std;

void Print(int* a, const int size);
template <typename T>
void Print(T* a, const int size);

int SumOdd(int* a, const int size);        // звичайна функція (тільки int)
template <typename T>
T SumOdd(T* a, const int size);            // шаблон (будь-який цілий тип)

int main()
{
    const int n = 10;

    int a[n] = { 1, 2, 3, 4, 5, -7, 8, 9, 10, 11 };
    Print(a, n);
    int s1 = SumOdd(a, n);                 // викликається звичайна функція
    cout << "SumOdd(a, n) = " << s1 << endl;

    int s2 = SumOdd<int>(a, n);            // викликається шаблон для int
    cout << "SumOdd<int>(a, n) = " << s2 << endl;

    long b[n] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19 };
    Print<long>(b, n);
    long s3 = SumOdd<long>(b, n);          // той самий шаблон, але для long
    cout << "SumOdd<long>(b, n) = " << s3 << endl;

    return 0;
}

void Print(int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

template <typename T>
void Print(T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

int SumOdd(int* a, const int size)
{
    int s = 0;                             // сума, спочатку 0
    for (int i = 0; i < size; i++)
        if (a[i] % 2 != 0)                 // непарне число
            s += a[i];                     // додаємо саме число
    return s;
}

template <typename T>
T SumOdd(T* a, const int size)
{
    T s = T();                             // нульове значення типу T
    for (int i = 0; i < size; i++)
        if (a[i] % 2 != 0)
            s += a[i];
    return s;
}