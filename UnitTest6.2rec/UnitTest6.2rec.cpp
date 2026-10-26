#include "pch.h"
#include "CppUnitTest.h"
#include "../6.2rec/6.2rec.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62rec
{
    TEST_CLASS(UnitTest62rec)
    {
    public:

        TEST_METHOD(TestSumIndexOdd)
        {
            const int n = 8;
            int a[n] = { 75, 34, -5, 0, 13, 2, -7, 1 };
            // непарні елементи на індексах 0, 2, 4, 6, 7 -> сума 19
            Assert::AreEqual(19, SumIndexOdd(a, n, 0));
        }
    };
}