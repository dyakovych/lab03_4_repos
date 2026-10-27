#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4rec/6.4iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64rec
{
    TEST_CLASS(UnitTest64rec)
    {
    public:

        // 1.1: найбільший за модулем елемент (починаємо з i = 1, max = a[0])
        TEST_METHOD(TestMaxAbs)
        {
            const int n = 7;
            double a[n] = { -8, 2, -3.5, 0, 4.5, 6, 0 };
            Assert::AreEqual(-8.0, MaxAbs(a, n, 1, a[0]), 0.0001);
        }

        // пошук першого додатного
        TEST_METHOD(TestFindPositive)
        {
            const int n = 7;
            double a[n] = { -8, 2, -3.5, 0, 4.5, 6, 0 };
            Assert::AreEqual(1, FindPositive(a, n, 0));
            Assert::AreEqual(4, FindPositive(a, n, 2));
        }

        // коли додатних немає - повертає -1
        TEST_METHOD(TestFindPositiveNone)
        {
            const int n = 3;
            double a[n] = { -1, -2, 0 };
            Assert::AreEqual(-1, FindPositive(a, n, 0));
        }

        // 1.2: сума між першим (індекс 1) і другим (індекс 4) додатними:
        // рахуємо від індексу 2 до індексу 3 включно
        TEST_METHOD(TestSumBetween)
        {
            const int n = 7;
            double a[n] = { -8, 2, -3.5, 0, 4.5, 6, 0 };
            Assert::AreEqual(-3.5, SumBetween(a, 4, 2), 0.0001);
        }

        // 2: нулі в кінець, порядок інших зберігається
        TEST_METHOD(TestZerosToEnd)
        {
            const int n = 7;
            double a[n] = { -8, 2, -3.5, 0, 4.5, 6, 0 };
            double expected[n] = { -8, 2, -3.5, 4.5, 6, 0, 0 };

            int k = Compact(a, n, 0, 0);
            Assert::AreEqual(5, k);
            FillZeros(a, n, k);

            for (int i = 0; i < n; i++)
                Assert::AreEqual(expected[i], a[i], 0.0001);
        }
    };
}
