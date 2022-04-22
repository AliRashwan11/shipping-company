#pragma once
#include"Cargo.h"
#include"UI.h"
#include"Company.h"

class Company;


class Event                                                    // pure virtual function .. cannot instantiate an object
{
	int HourOfEvent;                            
	int DayOfEvent;

protected:

	Company* mainCompany;

public:

	Event(int,int,Company*);
	Event(Event&);
	Event();
	virtual bool Execute() = 0;
	int GetDay();
	int GetHour();
	Company* GetCompany();

	
};

