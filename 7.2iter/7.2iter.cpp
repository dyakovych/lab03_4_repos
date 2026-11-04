// Lab_7_2_1.cpp
// Ітераційний спосіб
// Варіант 9: найбільший з мінімальних елементів по непарних рядках
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

// Функція для виведення горизонтальної лінії рамки (+-------+-------+)
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

// Виведення матриці у вигляді таблиці з рамками
void Print(int** a, const int k, const int n)
{
    cout << endl;
    PrintLine(n); // Верхня лінія
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "| " << setw(5) << a[i][j] << " "; // Елемент усередині вертикальних рамок
        cout << "|" << endl;
        PrintLine(n); // Лінія-розділювач між рядками
    }
    cout << endl;
}

bool SearchMaxMinInOddRows(int** a, const int k, const int n, int& maxMin)
{
    bool first = true;

    // Непарні рядки за індексами: i = 1, 3, 5...
    for (int i = 1; i < k; i += 2)
    {
        int minInRow = a[i][0];
        for (int j = 1; j < n; j++)
        {
            if (a[i][j] < minInRow)
                minInRow = a[i][j];
        }

        if (first || minInRow > maxMin)
        {
            maxMin = minInRow;
            first = false;
        }
    }

    return !first;
}

int main()
{
    srand((unsigned)time(NULL));

    int k, n;
    cout << "k = "; cin >> k;
    cout << "n = "; cin >> n;

    int Low = -10, High = 20;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);

    cout << "\nGenerated Matrix:";
    Print(a, k, n);

    int maxMin;
    if (SearchMaxMinInOddRows(a, k, n, maxMin))
        cout << "Max of min elements in odd rows = " << maxMin << endl;
    else
        cout << "There are no odd rows in the matrix!" << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}