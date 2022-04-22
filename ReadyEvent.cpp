#include"ReadyEvent.h"


ReadyEvent::ReadyEvent(int hour,int day,Company* cmp,Cargo* ToBeAdded) : Event(hour,day,cmp)
{
	CargoPtr = ToBeAdded;
}


bool ReadyEvent::Execute()                                          // adds a new cargo to waiting list
{

	int type = CargoPtr->GetCargoType();

	if (type == 0)
	{
		mainCompany->AddToNormalWaitingCargos(CargoPtr);
	}
	else if(type==1)
		mainCompany->AddToSpecialWaitingCargos(CargoPtr);
	else
		mainCompany->AddToVIPWaitingCargos(CargoPtr);

	return true;
}