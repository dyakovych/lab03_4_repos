#include "pch.h"
#include "CppUnitTest.h"
#include "../5.3ddd/5.3ddd.cpp"   

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
    TEST_CLASS(UnitTest2)
    {
    public:

        // гілка |x| >= 1, додатне x
        TEST_METHOD(TestP_AbsGE1_Positive)
        {
            double t = p(2);
            Assert::AreEqual(0.060024089, t, 1e-6);
        }

        // гілка |x| >= 1, від'ємне x
        TEST_METHOD(TestP_AbsGE1_Negative)
        {
            double t = p(-2);
            Assert::AreEqual(-1.377575733, t, 1e-6);
        }

        // межа гілки: x = 1 (|x| >= 1)
        TEST_METHOD(TestP_Boundary_One)
        {
            double t = p(1);
            Assert::AreEqual(0.403277883, t, 1e-6);
        }

        // межа гілки: x = -1 (|x| >= 1)
        TEST_METHOD(TestP_Boundary_MinusOne)
        {
            double t = p(-1);
            Assert::AreEqual(-0.279908805, t, 1e-6);
        }

        // гілка |x| < 1 (ряд), x = 0
        TEST_METHOD(TestP_Series_Zero)
        {
            double t = p(0);
            Assert::AreEqual(1.0, t, 1e-9);
        }

        // гілка |x| < 1 (ряд), x = 0.5
        TEST_METHOD(TestP_Series_Half)
        {
            double t = p(0.5);
            Assert::AreEqual(1.000000000, t, 1e-6);
        }

        // повний вираз z(q) = p(2q+1) + p^2(q^2-1) + sqrt(p(1)), q = -2
        TEST_METHOD(TestZ_MinusTwo)
        {
            double q = -2;
            double z = p(2 * q + 1) + pow(p(q * q - 1), 2) + sqrt(p(1));
            Assert::AreEqual(-15.591027475, z, 1e-6);
        }

        // q = 0
        TEST_METHOD(TestZ_Zero)
        {
            double q = 0;
            double z = p(2 * q + 1) + pow(p(q * q - 1), 2) + sqrt(p(1));
            Assert::AreEqual(1.116668461, z, 1e-6);
        }

        // q = 2
        TEST_METHOD(TestZ_Two)
        {
            double q = 2;
            double z = p(2 * q + 1) + pow(p(q * q - 1), 2) + sqrt(p(1));
            Assert::AreEqual(0.632302389, z, 1e-6);
        }
    };
}