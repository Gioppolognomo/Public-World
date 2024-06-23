#ifndef TIMER_H
#define TIMER_H
#include <chrono> // for std::chrono functions
class Timer
{
private:
	// Type aliases to make accessing nested type easier
	using Clock = std::chrono::steady_clock;
//	using DeciSecond = std::chrono::duration<double, std::ratio<1,10> >;

	
	 std::chrono::time_point<Clock> m_beg;

public:
	Timer ();
	void reset();
	double elapsed() const;
};
extern const double WaitingTime;
#endif