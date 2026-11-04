#include "pch.h"
#include "CppUnitTest.h"
#include "../7.2rec/7.2rec.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab722Tests
{
	TEST_CLASS(Lab722Tests)
	{
	public:

		// Тест 1: Перевірка рекурсивної функції знаходження мінімального елемента в одному рядку
		TEST_METHOD(TestMinInRow_Recursive)
		{
			const int n = 4;
			int** a = new int* [1];
			a[0] = new int[n] { 8, -3, 12, 0 };

			// Починаємо шукати мінімум з 0-го елемента
			int minVal = MinInRow(a, 0, n, 0, a[0][0]);

			Assert::AreEqual(-3, minVal);

			delete[] a[0];
			delete[] a;
		}

		// Тест 2: Перевірка рекурсивного пошуку найбільшого з мінімальних елементів непарних рядків
		TEST_METHOD(TestSearchMaxMinInOddRows_Recursive)
		{
			// Створюємо матрицю 4х3 (k = 4, n = 3)
			// Індекси непарних рядків: i = 1 та i = 3
			// Рядок 0 (парний):   { 10,  5,  8 }
			// Рядок 1 (непарний): {  4,  9,  2 } -> minInRow = 2
			// Рядок 2 (парний):   { 15, 20, 12 }
			// Рядок 3 (непарний): {  7,  6,  9 } -> minInRow = 6
			// Очікуване значення maxMin серед (2, 6) = 6

			const int k = 4;
			const int n = 3;

			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];

			a[0][0] = 10; a[0][1] = 5;  a[0][2] = 8;
			a[1][0] = 4;  a[1][1] = 9;  a[1][2] = 2;
			a[2][0] = 15; a[2][1] = 20; a[2][2] = 12;
			a[3][0] = 7;  a[3][1] = 6;  a[3][2] = 9;

			bool first = true;
			int maxMin = 0;

			// Запускаємо пошук з непарного рядка (rowNo = 1)
			SearchMaxMinInOddRows(a, k, n, 1, first, maxMin);

			Assert::IsFalse(first); // Прапорець має змінити стан, якщо непарні рядки знайдено
			Assert::AreEqual(6, maxMin);

			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}

		// Тест 3: Перевірка випадку, коли матриця не має непарних рядків (наприклад, k = 1)
		TEST_METHOD(TestSearchMaxMinInOddRows_NoOddRows)
		{
			const int k = 1;
			const int n = 3;

			int** a = new int* [k];
			a[0] = new int[n] { 1, 2, 3 };

			bool first = true;
			int maxMin = 0;

			SearchMaxMinInOddRows(a, k, n, 1, first, maxMin);

			Assert::IsTrue(first); // Прапорець має залишитися true, бо рядків з індексом 1 немає

			delete[] a[0];
			delete[] a;
		}
	};
}