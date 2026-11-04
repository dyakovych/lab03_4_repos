#include "pch.h"
#include "CppUnitTest.h"
#include "../6.3iterA/6.3iterA.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        // Перевірка звичайної функції
        TEST_METHOD(TestSumOdd)
        {
            int a[5] = { 1, 2, 3, 4, 5 };

            int s = SumOdd(a, 5);

            Assert::AreEqual(9, s);
        }

        // Перевірка шаблону int
        TEST_METHOD(TestSumOddInt)
        {
            int a[5] = { 1, 2, 3, 4, 5 };

            int s = SumOdd<int>(a, 5);

            Assert::AreEqual(9, s);
        }

        // Перевірка шаблону long long
        TEST_METHOD(TestSumOddLongLong)
        {
            long long a[5] = { -3, 2, 7, 4, -5 };

            long long s = SumOdd<long long>(a, 5);

            Assert::AreEqual(-1LL, s);
        }

        // Перевірка шаблону short
        TEST_METHOD(TestSumOddShort)
        {
            short a[5] = { 11, 12, 13, 14, 15 };

            short s = SumOdd<short>(a, 5);

            Assert::AreEqual((short)39, s);
        }
    };
}