#pragma once

#define UNIT_TESTING
#include <SampleCalc.h>	
#undef UNIT_TESTING

#include <gtest/gtest.h>

TEST(TestSampleCalc, Addition)
{
	// Arrange
	auto a{ 2 };
	auto b{ 2 };

	// Act
	auto res{ SampleCalc::Addition(a, b) };

	// Assert
	ASSERT_EQ(res, a + b);
}

TEST(TestSampleCalc, Subtraction)
{
	// Arrange
	auto a{ 4 };
	auto b{ 2 };

	// Act
	auto res{ SampleCalc::Subtraction(a, b) };

	// Assert
	ASSERT_EQ(res, a - b);
}

TEST(TestSampleCalc, Multiplication)
{
	// Arrange
	auto a{ 3 };
	auto b{ 4 };

	// Act
	auto res{ SampleCalc::Multiplication(a, b) };

	// Assert
	ASSERT_EQ(res, a * b);
}

TEST(TestSampleCalc, Division)
{
	// Arrange
	auto a{ 4 };
	auto b{ 2 };
	auto c{ 0 };

	// Act
	auto res{ SampleCalc::Division(a, b) };

	// Assert
	ASSERT_THROW(SampleCalc::Division(a, c), std::exception);

	ASSERT_EQ(res, a / b);
}

TEST(TestSampleCalc, Private)
{
	ASSERT_EQ(SampleCalc::GetCorrectNumber(), 42);
}