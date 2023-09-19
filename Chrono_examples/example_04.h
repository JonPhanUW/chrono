#pragma once

#include <iostream>
#include <chrono>
#include <thread>

void example04_clock_differences() {

	//we'll capture two start times one right after the other
	auto system_start = std::chrono::system_clock::now();
	auto steady_start = std::chrono::steady_clock::now();

	//then delay them for two seconds
	std::this_thread::sleep_for(std::chrono::seconds(2));


	//then capture the end times, since they're staggered at the same order,
	//it should still be pretty accurate even though one goes before the other
	auto system_end = std::chrono::system_clock::now();
	auto steady_end = std::chrono::steady_clock::now();


	//using duration cast, we can use milliseconds for our units to see the difference 
	auto system_duration = std::chrono::duration_cast<std::chrono::milliseconds>(system_end - system_start);
	auto steady_duration = std::chrono::duration_cast<std::chrono::milliseconds>(steady_end - steady_start);

	std::cout << "for example 04 we found that two seconds using different clocks resulted in:" << std::endl; 
	std::cout << "system_clock: " << system_duration.count() << " milliseconds elapsed.\n";
	std::cout << "steady_clock: " << steady_duration.count() << " milliseconds elapsed.\n";
}
