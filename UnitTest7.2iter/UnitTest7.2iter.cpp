#include "pch.h"
#include "CppUnitTest.h"
#include "../7.2iter/7.2iter.cpp" // Підключаємо файл зреалізованої лабораторної

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab721Tests
{
	TEST_CLASS(Lab721Tests)
	{
	public:

		TEST_METHOD(TestSearchMaxMinInOddRows_ValidMatrix)
		{
			// Створюємо матрицю 4х3 (k = 4, n = 3)
			// Непарні рядки: i = 1 та i = 3
			// Рядок 0: { 10,  5,  8 }
			// Рядок 1: {  4,  9,  2 } -> minInRow = 2
			// Рядок 2: { 15, 20, 12 }
			// Рядок 3: {  7,  6,  9 } -> minInRow = 6
			// Очікуваний maxMin серед (2, 6) = 6

			const int k = 4;
			const int n = 3;

			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];

			a[0][0] = 10; a[0][1] = 5;  a[0][2] = 8;
			a[1][0] = 4;  a[1][1] = 9;  a[1][2] = 2;
			a[2][0] = 15; a[2][1] = 20; a[2][2] = 12;
			a[3][0] = 7;  a[3][1] = 6;  a[3][2] = 9;

			int maxMin = 0;
			bool result = SearchMaxMinInOddRows(a, k, n, maxMin);

			Assert::IsTrue(result);
			Assert::AreEqual(6, maxMin);

			for (int i = 0; i < k; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestSearchMaxMinInOddRows_NoOddRows)
		{
			// Матриця 1х3 (k = 1, n = 3) — непарних рядків немає
			const int k = 1;
			const int n = 3;

			int** a = new int* [k];
			a[0] = new int[n] { 1, 2, 3 };

			int maxMin = 0;
			bool result = SearchMaxMinInOddRows(a, k, n, maxMin);

			Assert::IsFalse(result);

			delete[] a[0];
			delete[] a;
		}
	};
}
