#pragma once
#include"Cargo.h"
#include"UI.h"


class Event                                                    // pure virtual function .. cannot instantiate an object
{
	int HourOfEvent;                            
	int DayOfEvent;


public:


	virtual void Execute() = 0;

	
};

