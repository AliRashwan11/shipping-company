#pragma once
#include"Event.h"

class CancelEvent : public Event
{
	int IdOfCancelledCargo;
	bool WasFound;

public:

	CancelEvent(int,int,Company,int);

	bool Execute(Cargo*);

};

