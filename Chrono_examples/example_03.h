#pragma once
#include <iostream>
#include <chrono>
#include <ctime>

//ctime is a C library for some time functions and structures 

void example03_current_time()
{

	//here we'll be using the system clock to get the real world time
	//and storing the captured time into this variable 
	auto time_now = std::chrono::system_clock::now();

	//to_time_t() converts a time_point of system_clock to std::time_t which is a data type
	//std::time_t represents the number of seconds since 00:00 hours, Jan 1, 1970 UTC
	std::time_t current_time = std::chrono::system_clock::to_time_t(time_now);

	//std::ctime() is a C-style function that takes  a pointer to std::time_t 
	//and returns a string that is in a readable format (day, month, date, time, year)


	char time_str[26]; //buffer to hold the time string

	//here we're using the thread safe updated version of ctime, we're converting current time
	//into a string and then populating our time_str bufffer with it
	ctime_s(time_str, sizeof(time_str), &current_time);


	std::cout << "For example 03 we are getting the current time: " << time_str << "\n";
}