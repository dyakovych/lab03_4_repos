#include "pch.h"
#include "CppUnitTest.h"
#include "../10.1/10.1.cpp"   // шлях до файлу з програмою (змініть, якщо у вас інша назва)

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest10_1
{
	TEST_CLASS(TestStudents)
	{
	public:

		TEST_METHOD(TestCountPhysMath5)
		{
			const int N = 4;
			Student p[N];

			// 1-й студент: фізика 5, математика 5 – враховується
			p[0].fizyka = 5; p[0].matematyka = 5; p[0].informatyka = 4;
			// 2-й студент: фізика 5, математика 4 – не враховується
			p[1].fizyka = 5; p[1].matematyka = 4; p[1].informatyka = 5;
			// 3-й студент: фізика 4, математика 5 – не враховується
			p[2].fizyka = 4; p[2].matematyka = 5; p[2].informatyka = 5;
			// 4-й студент: фізика 5, математика 5 – враховується
			p[3].fizyka = 5; p[3].matematyka = 5; p[3].informatyka = 3;

			int t = CountPhysMath5(p, N);

			Assert::AreEqual(2, t);
		}
	};
}