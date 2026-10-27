#include "pch.h"
#include "CppUnitTest.h"
#include "../6.3rec/6.3rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest63rec
{
    TEST_CLASS(UnitTest63rec)
    {
    public:

        // звичайна функція (0 - починаємо з першого елемента)
        TEST_METHOD(TestSumOdd)
        {
            const int n = 8;
            int a[n] = { 1, 2, 3, 4, 5, -7, 8, 9 };
            // непарні: 1, 3, 5, -7, 9 -> сума 11
            Assert::AreEqual(11, SumOdd(a, n, 0));
        }

        // шаблон для int
        TEST_METHOD(TestSumOddTemplateInt)
        {
            const int n = 8;
            int a[n] = { 1, 2, 3, 4, 5, -7, 8, 9 };
            Assert::AreEqual(11, SumOdd<int>(a, n, 0));
        }

        // шаблон для long
        TEST_METHOD(TestSumOddTemplateLong)
        {
            const int n = 4;
            long b[n] = { 10, 11, 12, 13 };
            // непарні: 11, 13 -> сума 24
            Assert::AreEqual(24L, SumOdd<long>(b, n, 0));
        }
    };
}