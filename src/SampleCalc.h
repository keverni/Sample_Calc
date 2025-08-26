#pragma once

#ifdef UNIT_TESTING
#include <gtest/gtest_prod.h> 
#endif

class SampleCalc final
{
public:
	static int Addition(int first, int sec) noexcept;
	static int Subtraction(int first, int sec) noexcept;
	static int Multiplication(int first, int sec) noexcept;
	static int Division(int first, int sec);

private:
	static int GetCorrectNumber() noexcept;


#ifdef UNIT_TESTING
	FRIEND_TEST(TestSampleCalc, Private);
#endif // UNIT_TESTING
};

	