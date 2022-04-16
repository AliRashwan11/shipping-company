#pragma once
#include"Cargo.h"
#include"UI.h"
#include"Company.h"


class Event                                                    // pure virtual function .. cannot instantiate an object
{
	int HourOfEvent;                            
	int DayOfEvent;

protected:

	Company* mainCompany;

public:

	Event(int,int,Company);
	virtual bool Execute(Cargo*) = 0;

	
};

