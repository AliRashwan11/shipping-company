#pragma once
#include"Event.h"



class ReadyEvent : public Event
{
	Cargo* CargoPtr; 
public:

	ReadyEvent(int,int,Company*,Cargo*);

	bool Execute();

};

