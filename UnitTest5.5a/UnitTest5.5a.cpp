#include "pch.h"
#include "CppUnitTest.h"
#include "../5.5a/5.5a"   // ЗАМІНИ на ім'я СВОГО проєкту і файлу з кодом

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
    TEST_CLASS(UnitTest2)
    {
    public:

        // Тест 1: остання цифра не нуль (8), рекурсії немає
        TEST_METHOD(TestSingleDigit)
        {
            int depth = 0;                // "папірець" для глибини
            int t = f(8, 1, depth);       // рахуємо f(8), перший рівень = 1
            Assert::AreEqual(8, t);       // очікуємо результат 8
            Assert::AreEqual(1, depth);   // очікуємо глибину 1
        }

        // Тест 2: число закінчується на не нуль (12), рекурсії немає
        TEST_METHOD(TestTwoDigits)
        {
            int depth = 0;
            int t = f(12, 1, depth);
            Assert::AreEqual(2, t);       // остання цифра 2
            Assert::AreEqual(1, depth);   // глибина 1
        }

        // Тест 3: один нуль в кінці (10 -> 1)
        TEST_METHOD(TestOneZero)
        {
            int depth = 0;
            int t = f(10, 1, depth);
            Assert::AreEqual(1, t);       // результат 1
            Assert::AreEqual(2, depth);   // глибина 2
        }

        // Тест 4: два нулі в кінці (1200 -> 120 -> 12)
        TEST_METHOD(TestTwoZeros)
        {
            int depth = 0;
            int t = f(1200, 1, depth);
            Assert::AreEqual(2, t);       // результат 2
            Assert::AreEqual(3, depth);   // глибина 3
        }

        // Тест 5: три нулі в кінці (5000 -> 500 -> 50 -> 5)
        TEST_METHOD(TestThreeZeros)
        {
            int depth = 0;
            int t = f(5000, 1, depth);
            Assert::AreEqual(5, t);       // результат 5
            Assert::AreEqual(4, depth);   // глибина 4
        }

        // Тест 6: число 0 (кінець рекурсії одразу)
        TEST_METHOD(TestZero)
        {
            int depth = 0;
            int t = f(0, 1, depth);
            Assert::AreEqual(0, t);       // результат 0
            Assert::AreEqual(1, depth);   // глибина 1
        }
    };
}