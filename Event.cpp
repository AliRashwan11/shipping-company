#include "Event.h"

Event::Event(int hour,int day, Company cmp)           // non-default constructor for base class Event ...
{
	mainCompany = &cmp;
	HourOfEvent = hour;
	DayOfEvent =day;
}

