#include "pch.h"
#include "CppUnitTest.h"
#include "../6.3iter/6.3iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63iter
{
    TEST_CLASS(UnitTest63iter)
    {
    public:
        TEST_METHOD(TestSumOdd)
        {
            const int n = 8;
            int a[n] = { 1, 2, 3, 4, 5, -7, 8, 9 };
            // непарні: 1, 3, 5, -7, 9 -> сума 11
            Assert::AreEqual(11, SumOdd(a, n));
        }

        TEST_METHOD(TestSumOddTemplateInt)
        {
            const int n = 8;
            int a[n] = { 1, 2, 3, 4, 5, -7, 8, 9 };
            Assert::AreEqual(11, SumOdd<int>(a, n));
        }

        TEST_METHOD(TestSumOddTemplateLong)
        {
            const int n = 4;
            long b[n] = { 10, 11, 12, 13 };
            // непарні: 11, 13 -> сума 24
            Assert::AreEqual(24L, SumOdd<long>(b, n));
        }
    };
}
