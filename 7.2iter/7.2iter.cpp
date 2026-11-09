
// Lab_7_2_1.cpp
// Ітераційний спосіб
// Варіант 9: найбільший з мінімальних елементів по непарних рядках

#include <iostream>  // Введення та виведення даних
#include <iomanip>   // Форматування таблиці
#include <cstdlib>   // Генерація випадкових чисел
#include <ctime>     // Робота з часом

using namespace std;

// Функція заповнення матриці випадковими числами
void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)       // Перебір рядків
        for (int j = 0; j < n; j++)   // Перебір стовпців
            a[i][j] = Low + rand() % (High - Low + 1);
}

// Функція створення горизонтальної лінії таблиці
void PrintLine(const int n, const int cellWidth = 7)
{
    for (int j = 0; j < n; j++)
    {
        cout << "+";
        for (int w = 0; w < cellWidth; w++)
            cout << "-";
    }
    cout << "+" << endl;
}

// Функція виведення матриці у вигляді таблиці
void Print(int** a, const int k, const int n)
{
    cout << endl;
    PrintLine(n);  // Верхня лінія таблиці

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "| " << setw(5) << a[i][j] << " ";

        cout << "|" << endl;
        PrintLine(n);  // Лінія після кожного рядка
    }
    cout << endl;
}

// Функція пошуку найбільшого серед мінімальних елементів непарних рядків
bool SearchMaxMinInOddRows(int** a, const int k, const int n, int& maxMin)
{
    bool first = true;  // Перевірка першого знайденого мінімуму

    // Перебір непарних рядків: 1, 3, 5...
    for (int i = 0; i < k; i += 2)
    {
        int minInRow = a[i][0];  // Перший елемент рядка приймаємо за мінімальний

        for (int j = 1; j < n; j++)
        {
            // Якщо поточний елемент менший за мінімальний
            if (a[i][j] < minInRow)
                minInRow = a[i][j];
        }

        // Пошук найбільшого серед знайдених мінімумів
        if (first || minInRow > maxMin)
        {
            maxMin = minInRow;
            first = false;
        }
    }

    return !first;  // Повернення результату пошуку
}

int main()
{
    srand((unsigned)time(NULL));  // Ініціалізація генератора випадкових чисел

    int k, n;  // Кількість рядків і стовпців
    cout << "k = ";
    cin >> k;
    cout << "n = ";
    cin >> n;

    int Low = -10, High = 20;  // Межі випадкових чисел

    // Створення динамічної матриці
    int** a = new int* [k];

    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);  // Заповнення матриці

    cout << "\nGenerated Matrix:";
    Print(a, k, n);  // Виведення матриці

    int maxMin;  // Змінна для збереження результату

    // Виклик функції пошуку та виведення результату
    if (SearchMaxMinInOddRows(a, k, n, maxMin))
        cout << "Max of min elements in odd rows = " << maxMin << endl;
    else
        cout << "There are no odd rows in the matrix!" << endl;

    // Звільнення пам'яті
    for (int i = 0; i < k; i++)
        delete[] a[i];

    delete[] a;

    return 0;  // Завершення програми
}
