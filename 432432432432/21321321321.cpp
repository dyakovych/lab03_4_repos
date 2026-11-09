// Lab_7_2_2.cpp
// Рекурсивний спосіб
// Варіант 9: найбільший з мінімальних елементів по непарних рядках
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void CreateRow(int** a, const int rowNo, const int n, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < n - 1)
        CreateRow(a, rowNo, n, Low, High, colNo + 1);
}

void CreateRows(int** a, const int k, const int n, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, n, Low, High, 0);
    if (rowNo < k - 1)
        CreateRows(a, k, n, Low, High, rowNo + 1);
}

// Рекурсивне малювання горизонтальних ліній рамки
void PrintLine(const int n, int colNo = 0, const int cellWidth = 7)
{
    cout << "+";
    for (int w = 0; w < cellWidth; w++)
        cout << "-";
    if (colNo < n - 1)
        PrintLine(n, colNo + 1, cellWidth);
    else
        cout << "+" << endl;
}

// Рекурсивне виведення елементів рядка всередині рамок
void PrintRow(int** a, const int rowNo, const int n, int colNo)
{
    cout << "| " << setw(5) << a[rowNo][colNo] << " ";
    if (colNo < n - 1)
        PrintRow(a, rowNo, n, colNo + 1);
    else
        cout << "|" << endl;
}

// Рекурсивне виведення всієї таблиці з рамками
void PrintRows(int** a, const int k, const int n, int rowNo)
{
    if (rowNo == 0)
        PrintLine(n);

    PrintRow(a, rowNo, n, 0);
    PrintLine(n);

    if (rowNo < k - 1)
        PrintRows(a, k, n, rowNo + 1);
    else
        cout << endl;
}

int MinInRow(int** a, const int rowNo, const int n, int colNo, int minVal)
{
    if (a[rowNo][colNo] < minVal)
        minVal = a[rowNo][colNo];
    if (colNo < n - 1)
        return MinInRow(a, rowNo, n, colNo + 1, minVal);
    else
        return minVal;
}

void SearchMaxMinInOddRows(int** a, const int k, const int n, int rowNo, bool& first, int& maxMin)
{
    if (rowNo < k)
    {
        int minInRow = MinInRow(a, rowNo, n, 0, a[rowNo][0]);
        if (first || minInRow > maxMin)
        {
            maxMin = minInRow;
            first = false;
        }
        if (rowNo + 2 < k)
            SearchMaxMinInOddRows(a, k, n, rowNo + 2, first, maxMin);
    }
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

    CreateRows(a, k, n, Low, High, 0);

    cout << "\nGenerated Matrix:";
    cout << endl;
    PrintRows(a, k, n, 0);

    bool first = true;
    int maxMin = 0;

    SearchMaxMinInOddRows(a, k, n, 1, first, maxMin);

    if (!first)
        cout << "Max of min elements in odd rows = " << maxMin << endl;
    else
        cout << "There are no odd rows in the matrix!" << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}