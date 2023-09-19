#pragma once
#include <iostream>
#include <chrono>

struct my_timer
{

	//a time_point object expresses a point in time
	std::chrono::time_point<std::chrono::steady_clock> my_start, my_end; 

	std::chrono::duration<float> my_duration; 


	my_timer()
	{
		my_start = std::chrono::high_resolution_clock::now();
	}


	~my_timer()
	{
		my_end = std::chrono::high_resolution_clock::now();
		my_duration = my_end - my_start;


		//we'll take the default seconds and convert it into milliseconds by multiplying by 1000 float literal 
		float my_milliseconds = my_duration.count() * 1000.0f;
		std::cout << "for example 01, we tracked that this function took " << my_milliseconds << "ms to execute" << "\n" << std::endl;
	}

};


void example01_timed_function() //we'll use this function as something to time for the example
{
	my_timer timer; //when this goes out of scope, the destructor will trigger and print out the duration! 

	for (int i = 0; i < 100; i++)
		std::cout << "Hello World!" << std::endl;
}

