#pragma once
#include <iostream>
#include <chrono>
#include <thread>

void example00_print_delay()
{

	//literals will let us use some terms like (1s) for one second 
	using namespace std::literals::chrono_literals;


	/*there are three clock types:
	--system_clock = current time according to system clock
	--steady_clock = unadjusted clock that goes at uniform rate
	--high_resolution_clock = provides smallest possible tick*/


	//now() is used to get the current time
	const auto my_start = std::chrono::high_resolution_clock::now();


	//we can use sleep_for delaying threads 
	std::this_thread::sleep_for(1s);


	//then we'll mark when end is after the delay
	const auto my_end = std::chrono::high_resolution_clock::now();


	//a duration object expresses a time span of a count, could be anything like 42 hours, or ten milliseconds.
	//you can use different unit types based on how precise you want things
	//in this example our duration is just the time difference of when start and end trigger 
	const std::chrono::duration<float> my_duration = my_end - my_start;


	//by default seconds are used
	std::cout << "for example 00 we delayed a thread by " << my_duration.count() << 's' << "\n\n" << std::endl;
}