#include "../8.1iter/8.1iter.cpp"          // посилання на основний файл з програмою
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestIterative
{
	TEST_CLASS(UnitTestIterative)
	{
	public:
		TEST_METHOD(TestHasQuad)
		{
			char s1[] = "abbbbc";
			char s2[] = "aaabbb";

			Assert::IsTrue(HasQuad(s1));
			Assert::IsFalse(HasQuad(s2));
		}

		TEST_METHOD(TestChange)
		{
			char str[101] = "abbbbc";
			char* res = Change(str);

			Assert::AreEqual("a**c", str);   // результат у параметрі
			Assert::AreEqual("a**c", res);   // результат як значення функції
		}
	};
}