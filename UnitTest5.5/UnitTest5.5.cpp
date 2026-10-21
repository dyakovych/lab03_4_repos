#include "pch.h"
#include "CppUnitTest.h"
#include "../5.5/5.5.cpp"   // підстав ім'я СВОГО проєкту та файлу

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
    TEST_CLASS(UnitTest2)
    {
    public:

        // Остання цифра ненульова: рекурсії немає, глибина 1
        TEST_METHOD(TestSingleDigit)
        {
            int depth = 0;
            int t = f(8, 1, depth);
            Assert::AreEqual(8, t);
            Assert::AreEqual(1, depth);
        }

        // 10 -> 1: один рекурсивний виклик, глибина 2
        TEST_METHOD(TestOneZero)
        {
            int depth = 0;
            int t = f(10, 1, depth);
            Assert::AreEqual(1, t);
            Assert::AreEqual(2, depth);
        }

        // 1200 -> 120 -> 12: результат 2, глибина 3
        TEST_METHOD(TestTwoZeros)
        {
            int depth = 0;
            int t = f(1200, 1, depth);
            Assert::AreEqual(2, t);
            Assert::AreEqual(3, depth);
        }

        // Число без ненульових цифр у кінці: 100 -> 10 -> 1
        TEST_METHOD(TestHundred)
        {
            int depth = 0;
            int t = f(100, 1, depth);
            Assert::AreEqual(1, t);
            Assert::AreEqual(3, depth);
        }

        // Базова задача: f(0) = 0
        TEST_METHOD(TestZero)
        {
            int depth = 0;
            int t = f(0, 1, depth);
            Assert::AreEqual(0, t);
            Assert::AreEqual(1, depth);
        }
    };
}