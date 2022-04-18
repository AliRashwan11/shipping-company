#pragma once
#include"Event.h"

class CancelEvent : public Event
{
	int IdOfCancelledCargo;
	bool WasFound;
	Cargo* cancelledCargo;

public:

	CancelEvent(int,int,Company*,int);

	bool Execute(Cargo*);

};

