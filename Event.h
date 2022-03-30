#pragma once
#include"Cargo.h"

class Event
{
	int Hour;
	int Day;
	Cargo* cargo;

public:

	Event(int day, int hour);                           

	virtual void Execute() = 0;

	
};

