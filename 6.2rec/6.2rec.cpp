// Лабораторна робота № 6.2 (рекурсивний спосіб, тобто функція викликає сама себе)
// Варіант 9
//
// Ідея рекурсії: замість циклу функція перевіряє ОДИН елемент a[i]
// і викликає саму себе для наступного елемента a[i+1].
// Параметр i - це номер елемента, який перевіряється зараз.
// Починаємо завжди з i = 0.

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Заповнення масиву випадковими числами від Low до High.
// Обробляємо елемент a[i], потім викликаємо себе для i+1.
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)                       // якщо це ще не останній елемент
        Create(a, size, Low, High, i + 1);  // переходимо до наступного
}

// Виведення масиву в один рядок.
void Print(int* a, const int size, int i)
{
    cout << setw(4) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);   // виводимо наступний елемент
    else
        cout << endl;            // останній елемент - переходимо на новий рядок
}

// Функція ПОВЕРТАЄ суму індексів непарних елементів, починаючи з номера i.
int SumIndexOdd(int* a, const int size, int i)
{
    if (i < size)   // поки ми не вийшли за межі масиву
    {
        if (a[i] % 2 != 0)
            // елемент непарний: беремо його індекс i
            // і додаємо суму для решти масиву (від i+1)
            return i + SumIndexOdd(a, size, i + 1);
        else
            // елемент парний: нічого не додаємо, просто йдемо далі
            return SumIndexOdd(a, size, i + 1);
    }
    else
        return 0;   // ЗУПИНКА рекурсії: елементів більше немає, сума порожньої частини = 0
}

int main()
{
    srand((unsigned)time(NULL));

    const int n = 15;
    int a[n];

    int Low = -10;
    int High = 10;

    Create(a, n, Low, High, 0);   // 0 - починаємо з першого елемента
    Print(a, n, 0);

    cout << "Sum of indices = " << SumIndexOdd(a, n, 0) << endl;

    return 0;
}