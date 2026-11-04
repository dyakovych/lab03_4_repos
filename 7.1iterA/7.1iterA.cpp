// Lab_7_1_iter.cpp
// < прізвище, ім’я автора >
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Ітераційний спосіб.
// Варіант 9

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

// Формування матриці випадковими числами з діапазону [Low; High]
// R – матриця; rowCount, colCount – кількість рядків і стовпчиків;
// Low, High – межі діапазону значень елементів
void Create(int** R, const int rowCount, const int colCount, const int Low,
    const int High);

// Виведення горизонтальної лінії таблиці (colCount комірок)
void PrintLine(const int colCount);

// Виведення матриці у вигляді таблиці
void Print(int** R, const int rowCount, const int colCount);

// Впорядкування стовпчиків матриці за ключами: → → ←
void Sort(int** R, const int rowCount, const int colCount);

// Обмін місцями стовпчиків col1 та col2 матриці
void Change(int** R, const int col1, const int col2, const int rowCount);

// Обчислення кількості k та суми S елементів, що задовольняють критерію,
// та заміна цих елементів нулями
void Calc(int** R, const int rowCount, const int colCount, int& S, int& k);

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

    Create(R, rowCount, colCount, Low, High);
    cout << "Initial matrix:";
    Print(R, rowCount, colCount);

    Sort(R, rowCount, colCount);
    cout << "Sorted matrix:";
    Print(R, rowCount, colCount);

    int S = 0;              // сума елементів, що задовольняють критерію
    int k = 0;              // кількість елементів, що задовольняють критерію
    Calc(R, rowCount, colCount, S, k);
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

void Create(int** R, const int rowCount, const int colCount, const int Low,
    const int High)
{
    for (int i = 0; i < rowCount; i++)          // i – номер рядка
        for (int j = 0; j < colCount; j++)      // j – номер стовпчика
            R[i][j] = Low + rand() % (High - Low + 1);
}

void PrintLine(const int colCount)
{
    cout << "+";
    for (int j = 0; j < colCount; j++)
        cout << "-----+";
    cout << endl;
}

void Print(int** R, const int rowCount, const int colCount)
{
    cout << endl;
    PrintLine(colCount);
    for (int i = 0; i < rowCount; i++)
    {
        cout << "|";
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << R[i][j] << " |";
        cout << endl;
        PrintLine(colCount);
    }
    cout << endl;
}

void Sort(int** R, const int rowCount, const int colCount)
{
    // метод обміну («бульбашки»): порівнюються сусідні стовпчики j1 та j1+1
    for (int j0 = 0; j0 < colCount - 1; j0++)           // j0 – номер проходу
        for (int j1 = 0; j1 < colCount - j0 - 1; j1++)
            if ((R[0][j1] > R[0][j1 + 1])                 // 1-й рядок ↑
                ||
                (R[0][j1] == R[0][j1 + 1] &&
                    R[1][j1] > R[1][j1 + 1])                 // 2-й рядок ↑
                ||
                (R[0][j1] == R[0][j1 + 1] &&
                    R[1][j1] == R[1][j1 + 1] &&
                    R[2][j1] < R[2][j1 + 1]))                // 3-й рядок ↓
                Change(R, j1, j1 + 1, rowCount);
}

void Change(int** R, const int col1, const int col2, const int rowCount)
{
    int tmp;                                    // тимчасова змінна для обміну
    for (int i = 0; i < rowCount; i++)
    {
        tmp = R[i][col1];
        R[i][col1] = R[i][col2];
        R[i][col2] = tmp;
    }
}

void Calc(int** R, const int rowCount, const int colCount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            // додатні, крім тих, хоча б один індекс яких кратний 3
            if (R[i][j] > 0 && !(i % 3 == 0 || j % 3 == 0))
            {
                S += R[i][j];
                k++;
                R[i][j] = 0;
            }
}