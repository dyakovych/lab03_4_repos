#include "pch.h"
#include "CppUnitTest.h"
#include "../5.2/5.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
    TEST_CLASS(UnitTest2)
    {
    public:

        // Перевірка функції A: a1 = x * (-x^2 * 1 / 3) = 0.5 * (-0.25 / 3)
        TEST_METHOD(TestA)
        {
            double a;
            a = A(0.5, 1, 0.5);
            Assert::AreEqual(-0.5 * 0.25 / 3, a, 1e-9);
        }

        // Перевірка функції S: сума ряду для x = 0.5 має збігатися з atan(x) з точністю eps
        TEST_METHOD(TestS)
        {
            double x = 0.5, eps = 0.001, s = 0;
            int n = 0;
            s = S(x, eps, n, s);
            Assert::AreEqual(atan(x), s, eps);
        }

        // Перевірка кількості доданків (n) для x = 0.5, eps = 0.001
        TEST_METHOD(TestN)
        {
            double x = 0.5, eps = 0.001, s = 0;
            int n = 0;
            s = S(x, eps, n, s);
            Assert::AreEqual(4, n);
        }

        // Для x = 0 усі доданки, окрім першого, нульові: S = 0, n = 1
        TEST_METHOD(TestSZero)
        {
            double x = 0, eps = 0.001, s = 0;
            int n = 0;
            s = S(x, eps, n, s);
            Assert::AreEqual(0.0, s, 1e-9);
            Assert::AreEqual(1, n);
        }
    };
}