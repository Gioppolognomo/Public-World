#include <chrono> // for std::chrono functions
#include "timer.h"

constexpr double WaitingTime {8.0};

	// Type aliases to make accessing nested type easier
	using Clock = std::chrono::steady_clock;
	using DeciSecond = std::chrono::duration<double, std::ratio<1,10> >;

	Timer::Timer ():m_beg(Clock::now()) {}


	void Timer::reset()
	{
		m_beg = Clock::now();
	}

	double Timer::elapsed() const
	{
		return std::chrono::duration_cast<DeciSecond>(Clock::now() - m_beg).count();
	}
