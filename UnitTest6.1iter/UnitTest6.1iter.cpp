#include "pch.h"
#include "CppUnitTest.h"
#include "../6.1iter/6.1iter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest61iter
{
    TEST_CLASS(UnitTest61iter)
    {
    public:

        TEST_METHOD(TestCount)
        {
            const int n = 8;
            int b[n] = { 75, 34, -5, 0, 13, 2, -7, 1 };
            // додатні і непарні: 75, 13, 1
            Assert::AreEqual(3, Count(b, n));
        }

        TEST_METHOD(TestSum)
        {
            const int n = 8;
            int b[n] = { 75, 34, -5, 0, 13, 2, -7, 1 };
            // 75 + 13 + 1 = 89
            Assert::AreEqual(89, Sum(b, n));
        }

        TEST_METHOD(TestZero)
        {
            const int n = 8;
            int b[n] = { 75, 34, -5, 0, 13, 2, -7, 1 };
            int expected[n] = { 0, 34, -5, 0, 0, 2, -7, 0 };
            Zero(b, n);
            for (int i = 0; i < n; i++)
                Assert::AreEqual(expected[i], b[i]);
        }
    };
}