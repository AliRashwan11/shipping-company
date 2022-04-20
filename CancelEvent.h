#pragma once
#include"Event.h"

class CancelEvent : public Event
{
	int IdOfCancelledCargo;
	Cargo* cancelledCargo;
	bool WasFound;

public:

	CancelEvent(int,int,Company*,int);

	bool Execute(Cargo*);

};

