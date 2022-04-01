#pragma once
#include"Event.h"



class ReadyEvent : public Event
{
	int Day;
	int Hour;
	Cargo* CargoPtr;                                       

public:

	ReadyEvent(int day , int hour , Cargo cargop)
	{
		Day = day;
		Hour = hour;
		CargoPtr = &cargop;
	}

	void Execute()
	{

	}


};

