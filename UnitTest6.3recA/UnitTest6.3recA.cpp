#include "pch.h"
#include "CppUnitTest.h"
#include "../6.3recA/6.3recA.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // Перевірка звичайної рекурсивної функції
        TEST_METHOD(TestSumOdd)
        {
            int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

            int s = SumOdd(a, 10, 0);

            Assert::AreEqual(25, s);
        }

        // Перевірка шаблону int
        TEST_METHOD(TestSumOddInt)
        {
            int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

            int s = SumOdd<int>(a, 10, 0);

            Assert::AreEqual(25, s);
        }

        // Перевірка шаблону long long
        TEST_METHOD(TestSumOddLongLong)
        {
            long long a[10] = { -3, 2, 7, 4, -5, 6, 9, 8, 1, 10 };

            long long s = SumOdd<long long>(a, 10, 0);

            Assert::AreEqual(9LL, s);
        }

        // Перевірка шаблону short
        TEST_METHOD(TestSumOddShort)
        {
            short a[10] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };

            short s = SumOdd<short>(a, 10, 0);

            Assert::AreEqual((short)75, s);
        }
    };
}