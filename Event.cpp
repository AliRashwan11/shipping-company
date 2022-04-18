#include "Event.h"

Event::Event(int hour,int day, Company* cmp)           // non-default constructor for base class Event ...
{
	mainCompany = cmp;
	HourOfEvent = hour;
	DayOfEvent =day;
}


Event::Event(Event& copy)
{
	mainCompany = copy.GetCompany();
	HourOfEvent = copy.GetHour();
	DayOfEvent = copy.GetDay();
}

int Event::GetDay()
{
	return DayOfEvent;
}

int Event::GetHour()
{
	return HourOfEvent;
}

Company* Event::GetCompany()
{
	return mainCompany;
}