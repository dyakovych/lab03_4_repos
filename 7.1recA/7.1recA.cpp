// Lab_7_1_rec.cpp
// < прізвище, ім’я автора >
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Рекурсивний спосіб.
// Варіант 9

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

// Формування матриці випадковими числами з діапазону [Low; High]
// R – матриця; rowCount, colCount – кількість рядків і стовпчиків;
// Low, High – межі діапазону; i – номер поточного рядка;
// rowNo – номер рядка, j – номер поточного стовпчика
void CreateRows(int** R, const int rowCount, const int colCount, const int Low,
    const int High, int i);
void CreateRow(int** R, const int rowNo, const int colCount, const int Low,
    const int High, int j);

// Виведення горизонтальної лінії таблиці (colCount комірок),
// j – номер поточної комірки
void PrintLine(const int colCount, int j);

// Виведення матриці у вигляді таблиці
void Print(int** R, const int rowCount, const int colCount);
void PrintRows(int** R, const int rowCount, const int colCount, int rowNo);
void PrintRow(int** R, const int rowNo, const int colCount, int colNo);

// Впорядкування стовпчиків матриці за ключами: → → ←
// j0 – номер проходу, j1 – номер поточного стовпчика у проході
void Sort(int** R, const int rowCount, const int colCount, int j0);
void SortPass(int** R, const int rowCount, const int colCount, const int j0,
    int j1);

// Чи стоять сусідні стовпчики j та j+1 у неправильному порядку
bool IsWrongOrder(int** R, const int j);

// Обмін місцями стовпчиків col1 та col2 матриці; i – номер поточного рядка
void Change(int** R, const int col1, const int col2, const int rowCount, int i);

// Обчислення кількості k та суми S елементів, що задовольняють критерію,
// та заміна цих елементів нулями (S та k перед викликом мають дорівнювати 0)
void CalcRows(int** R, const int rowCount, const int colCount, int& S, int& k,
    int i);
void CalcRow(int** R, const int rowNo, const int colCount, int& S, int& k,
    int j);

int main()
{
    srand((unsigned)time(NULL));

    int Low = -6;           // нижня межа діапазону значень елементів
    int High = 31;          // верхня межа діапазону значень елементів

    int rowCount = 7;       // кількість рядків матриці
    int colCount = 5;       // кількість стовпчиків матриці

    // виділення пам’яті під матрицю R
    int** R = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        R[i] = new int[colCount];

    CreateRows(R, rowCount, colCount, Low, High, 0);
    cout << "Initial matrix:";
    Print(R, rowCount, colCount);

    Sort(R, rowCount, colCount, 0);
    cout << "Sorted matrix:";
    Print(R, rowCount, colCount);

    int S = 0;              // сума елементів, що задовольняють критерію
    int k = 0;              // кількість елементів, що задовольняють критерію
    CalcRows(R, rowCount, colCount, S, k, 0);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    cout << "Modified matrix:";
    Print(R, rowCount, colCount);

    // звільнення пам’яті
    for (int i = 0; i < rowCount; i++)
        delete[] R[i];
    delete[] R;

    return 0;
}

void CreateRows(int** R, const int rowCount, const int colCount, const int Low,
    const int High, int i)
{
    CreateRow(R, i, colCount, Low, High, 0);
    if (i < rowCount - 1)
        CreateRows(R, rowCount, colCount, Low, High, i + 1);
}

void CreateRow(int** R, const int rowNo, const int colCount, const int Low,
    const int High, int j)
{
    R[rowNo][j] = Low + rand() % (High - Low + 1);
    if (j < colCount - 1)
        CreateRow(R, rowNo, colCount, Low, High, j + 1);
}

void PrintLine(const int colCount, int j)
{
    if (j == 0)
        cout << "+";
    cout << "-----+";
    if (j < colCount - 1)
        PrintLine(colCount, j + 1);
    else
        cout << endl;
}

void Print(int** R, const int rowCount, const int colCount)
{
    cout << endl;
    PrintLine(colCount, 0);
    PrintRows(R, rowCount, colCount, 0);
    cout << endl;
}

void PrintRows(int** R, const int rowCount, const int colCount, int rowNo)
{
    PrintRow(R, rowNo, colCount, 0);
    PrintLine(colCount, 0);
    if (rowNo < rowCount - 1)
        PrintRows(R, rowCount, colCount, rowNo + 1);
}

void PrintRow(int** R, const int rowNo, const int colCount, int colNo)
{
    if (colNo == 0)
        cout << "|";
    cout << setw(4) << R[rowNo][colNo] << " |";
    if (colNo < colCount - 1)
        PrintRow(R, rowNo, colCount, colNo + 1);
    else
        cout << endl;
}

bool IsWrongOrder(int** R, const int j)
{
    return (R[0][j] > R[0][j + 1])                        // 1-й рядок ↑
        ||
        (R[0][j] == R[0][j + 1] &&
            R[1][j] > R[1][j + 1])                        // 2-й рядок ↑
        ||
        (R[0][j] == R[0][j + 1] &&
            R[1][j] == R[1][j + 1] &&
            R[2][j] < R[2][j + 1]);                       // 3-й рядок ↓
}

// зовнішній «цикл» методу обміну («бульбашки»)
void Sort(int** R, const int rowCount, const int colCount, int j0)
{
    if (j0 < colCount - 1)
    {
        SortPass(R, rowCount, colCount, j0, 0);
        Sort(R, rowCount, colCount, j0 + 1);
    }
}

// внутрішній «цикл» методу обміну: один прохід по сусідніх стовпчиках
void SortPass(int** R, const int rowCount, const int colCount, const int j0,
    int j1)
{
    if (j1 < colCount - j0 - 1)
    {
        if (IsWrongOrder(R, j1))
            Change(R, j1, j1 + 1, rowCount, 0);
        SortPass(R, rowCount, colCount, j0, j1 + 1);
    }
}

void Change(int** R, const int col1, const int col2, const int rowCount, int i)
{
    int tmp = R[i][col1];                       // тимчасова змінна для обміну
    R[i][col1] = R[i][col2];
    R[i][col2] = tmp;
    if (i < rowCount - 1)
        Change(R, col1, col2, rowCount, i + 1);
}

void CalcRows(int** R, const int rowCount, const int colCount, int& S, int& k,
    int i)
{
    CalcRow(R, i, colCount, S, k, 0);
    if (i < rowCount - 1)
        CalcRows(R, rowCount, colCount, S, k, i + 1);
}

void CalcRow(int** R, const int rowNo, const int colCount, int& S, int& k,
    int j)
{
    // додатні, крім тих, хоча б один індекс яких кратний 3
    if (R[rowNo][j] > 0 && !(rowNo % 3 == 0 || j % 3 == 0))
    {
        S += R[rowNo][j];
        k++;
        R[rowNo][j] = 0;
    }
    if (j < colCount - 1)
        CalcRow(R, rowNo, colCount, S, k, j + 1);
}