//Function that shows the time the function is running
// auto result = CPPTIMESTAMP(sum);
// result(...);

#pragma once
#include <iostream>
#include <chrono>

#define CPPTIMESTAMP(func) TIMESTAMP(func, #func)

template <typename Func>
auto TIMESTAMP(Func&& func, const char* funcName)
{
	return [fOn = std::forward<Func>(func), funcName](auto&&... args) -> void
		{
			auto start = std::chrono::high_resolution_clock::now();
			fOn(std::forward<decltype(args)>(args)...);
			auto end = std::chrono::high_resolution_clock::now();
			std::chrono::duration<double, std::micro> workingTime = end - start;
			std::cout.setf(std::ios::fixed);
			std::cout.precision(8);
			std::cout << __TIME__ << " " << __DATE__ << std::endl << "Working time of function: " << funcName \
				<< " is " << workingTime.count() / 1000000.0 << " sec." << std::endl;
		};
}

