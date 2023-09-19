#pragma once

#include <iostream>
#include <chrono>

void example02_converting_time_units()
{
	//here we're using hours to make one day
	std::chrono::hours one_day(24);

	//and we can convert hours to minutes using duration_cast 
	auto as_minutes = std::chrono::duration_cast<std::chrono::minutes>(one_day);


	std::cout << "For example 02 we're converting one day into " << as_minutes.count() << " minutes.\n\n";
}