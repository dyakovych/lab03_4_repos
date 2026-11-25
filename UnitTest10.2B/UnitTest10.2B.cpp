#include "pch.h"
#include "CppUnitTest.h"
#include "../10.2B/10.2B.cpp"     // шлях змініть на свій

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest10_2B
{
    TEST_CLASS(UnitTest10_2B)
    {
    public:
        TEST_METHOD(TestAverage)
        {
            Student s;
            s.spec = KOMP_NAUKY;
            s.fizyka = 90;
            s.matematyka = 80;
            s.prohramuvannia = 70;     // третя оцінка - програмування

            Assert::AreEqual(80.0, Average(s), 0.0001);
        }
    };
}