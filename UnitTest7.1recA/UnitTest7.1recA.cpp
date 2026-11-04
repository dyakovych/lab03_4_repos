// UnitTest_7_1_rec.cpp
// Unit-тест до лабораторної роботи № 7.1 (рекурсивний спосіб), варіант 9.
// Visual Studio: Native Unit Test Project. Шлях у #include – до файлу проєкту.

#include "pch.h"
#include "CppUnitTest.h"
#include "../7.1recA/7.1recA.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest71rec
{
    const int ROWS = 7;
    const int COLS = 5;

    // створює динамічну матрицю 7 x 5 із даних масиву data
    int** MakeMatrix(const int data[ROWS][COLS])
    {
        int** m = new int* [ROWS];
        for (int i = 0; i < ROWS; i++)
        {
            m[i] = new int[COLS];
            for (int j = 0; j < COLS; j++)
                m[i][j] = data[i][j];
        }
        return m;
    }

    void FreeMatrix(int** m)
    {
        for (int i = 0; i < ROWS; i++)
            delete[] m[i];
        delete[] m;
    }

    TEST_CLASS(UnitTest71rec)
    {
    public:

        // CalcRows: сума, кількість та заміна нулями елементів,
        // які є додатними і в яких жоден індекс не кратний 3
        TEST_METHOD(TestCalc)
        {
            const int data[ROWS][COLS] = {
                {  5,  8, 12,  3,  9 },
                {  7,  4, -2, 10,  6 },
                {  1, 15, 20, -4,  2 },
                { 11,  9,  3, 14,  8 },
                { 30,  6,  7, -1,  5 },
                {  2, 13,  0, 21, 17 },
                { 31, 25, 18,  3, 12 } };
            const int expected[ROWS][COLS] = {
                {  5,  8, 12,  3,  9 },
                {  7,  0, -2, 10,  0 },
                {  1,  0,  0, -4,  0 },
                { 11,  9,  3, 14,  8 },
                { 30,  0,  0, -1,  0 },
                {  2,  0,  0, 21,  0 },
                { 31, 25, 18,  3, 12 } };

            int** m = MakeMatrix(data);
            int S = 0, k = 0;

            CalcRows(m, ROWS, COLS, S, k, 0);

            Assert::AreEqual(95, S);
            Assert::AreEqual(10, k);
            for (int i = 0; i < ROWS; i++)
                for (int j = 0; j < COLS; j++)
                    Assert::AreEqual(expected[i][j], m[i][j]);

            FreeMatrix(m);
        }

        // CalcRows: у матриці немає елементів, що задовольняють критерію
        // (усі елементи з обома індексами, не кратними 3, не є додатними)
        TEST_METHOD(TestCalcNoElements)
        {
            const int data[ROWS][COLS] = {
                { 5,  5,  5, 5,  5 },
                { 5, -1,  0, 5, -3 },
                { 5, -2, -4, 5,  0 },
                { 5,  5,  5, 5,  5 },
                { 5,  0, -7, 5, -1 },
                { 5, -5, -6, 5, -2 },
                { 5,  5,  5, 5,  5 } };
            int** m = MakeMatrix(data);
            int S = 0, k = 0;

            CalcRows(m, ROWS, COLS, S, k, 0);

            Assert::AreEqual(0, S);
            Assert::AreEqual(0, k);
            for (int i = 0; i < ROWS; i++)
                for (int j = 0; j < COLS; j++)
                    Assert::AreEqual(data[i][j], m[i][j]);

            FreeMatrix(m);
        }

        // Sort: ключі → → ← (перевіряються всі три ключі)
        TEST_METHOD(TestSort)
        {
            const int data[ROWS][COLS] = {
                {  5,  3,  5,  3,  5 },
                {  4,  7,  4,  2,  4 },
                {  1,  8,  9,  5,  3 },
                { 10, 11, 12, 13, 14 },
                { 20, 21, 22, 23, 24 },
                { 30, 31, 32, 33, 34 },
                { 40, 41, 42, 43, 44 } };
            const int expected[ROWS][COLS] = {
                {  3,  3,  5,  5,  5 },
                {  2,  7,  4,  4,  4 },
                {  5,  8,  9,  3,  1 },
                { 13, 11, 12, 14, 10 },
                { 23, 21, 22, 24, 20 },
                { 33, 31, 32, 34, 30 },
                { 43, 41, 42, 44, 40 } };

            int** m = MakeMatrix(data);

            Sort(m, ROWS, COLS, 0);

            for (int i = 0; i < ROWS; i++)
                for (int j = 0; j < COLS; j++)
                    Assert::AreEqual(expected[i][j], m[i][j]);

            FreeMatrix(m);
        }

        // Change: обмін двох стовпчиків
        TEST_METHOD(TestChange)
        {
            const int data[ROWS][COLS] = {
                { 1, 2, 3, 4, 5 },
                { 6, 7, 8, 9, 10 },
                { 11, 12, 13, 14, 15 },
                { 16, 17, 18, 19, 20 },
                { 21, 22, 23, 24, 25 },
                { 26, 27, 28, 29, 30 },
                { 31, 32, 33, 34, 35 } };
            int** m = MakeMatrix(data);

            Change(m, 1, 3, ROWS, 0);

            for (int i = 0; i < ROWS; i++)
            {
                Assert::AreEqual(data[i][3], m[i][1]);
                Assert::AreEqual(data[i][1], m[i][3]);
                Assert::AreEqual(data[i][0], m[i][0]);
                Assert::AreEqual(data[i][2], m[i][2]);
                Assert::AreEqual(data[i][4], m[i][4]);
            }

            FreeMatrix(m);
        }

        // CreateRows: усі елементи належать діапазону [-6; 31]
        TEST_METHOD(TestCreateRange)
        {
            int** m = new int* [ROWS];
            for (int i = 0; i < ROWS; i++)
                m[i] = new int[COLS];

            CreateRows(m, ROWS, COLS, -6, 31, 0);

            for (int i = 0; i < ROWS; i++)
                for (int j = 0; j < COLS; j++)
                {
                    Assert::IsTrue(m[i][j] >= -6);
                    Assert::IsTrue(m[i][j] <= 31);
                }

            FreeMatrix(m);
        }
    };
}