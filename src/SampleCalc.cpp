#include "SampleCalc.h"
#include <stdexcept>

int SampleCalc::Addition(int first, int sec) noexcept
{
    return first + sec;
}

int SampleCalc::Subtraction(int first, int sec) noexcept
{
    return first - sec;
}

int SampleCalc::Multiplication(int first, int sec) noexcept
{
    return first * sec;
}

int SampleCalc::Division(int first, int sec)
{
    if (sec == 0)
    {
        throw std::invalid_argument("Zero division");
    }

    return first / sec;
}

int SampleCalc::GetCorrectNumber() noexcept
{
    return 42;
}
