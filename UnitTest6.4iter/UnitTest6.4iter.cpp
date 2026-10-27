#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4iter/6.4iter.cpp" 
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64iter
{
    TEST_CLASS(UnitTest64iter)
    {
    public:

        // 1.1: найбільший за модулем елемент
        TEST_METHOD(TestMaxAbs)
        {
            const int n = 7;
            double a[n] = { -8, 2, -3.5, 0, 4.5, 6, 0 };
            Assert::AreEqual(-8.0, MaxAbs(a, n), 0.0001);   // |-8| найбільший
        }

        // пошук першого додатного
        TEST_METHOD(TestFindPositive)
        {
            const int n = 7;
            double a[n] = { -8, 2, -3.5, 0, 4.5, 6, 0 };
            Assert::AreEqual(1, FindPositive(a, n, 0));     // перший додатний - індекс 1
            Assert::AreEqual(4, FindPositive(a, n, 2));     // наступний після нього - індекс 4
        }

        // коли додатних немає - повертає -1
        TEST_METHOD(TestFindPositiveNone)
        {
            const int n = 3;
            double a[n] = { -1, -2, 0 };
            Assert::AreEqual(-1, FindPositive(a, n, 0));
        }

        // 1.2: сума між першим (індекс 1) і другим (індекс 4) додатними
        TEST_METHOD(TestSumBetween)
        {
            const int n = 7;
            double a[n] = { -8, 2, -3.5, 0, 4.5, 6, 0 };
            // між ними: -3.5 + 0 = -3.5
            Assert::AreEqual(-3.5, SumBetween(a, 1, 4), 0.0001);
        }

        // 2: нулі в кінець, порядок інших зберігається
        TEST_METHOD(TestZerosToEnd)
        {
            const int n = 7;
            double a[n] = { -8, 2, -3.5, 0, 4.5, 6, 0 };
            double expected[n] = { -8, 2, -3.5, 4.5, 6, 0, 0 };

            int k = Compact(a, n);
            Assert::AreEqual(5, k);                         // ненульових 5
            FillZeros(a, n, k);

            for (int i = 0; i < n; i++)
                Assert::AreEqual(expected[i], a[i], 0.0001);
        }
    };
}
