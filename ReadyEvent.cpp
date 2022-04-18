#include"ReadyEvent.h"


ReadyEvent::ReadyEvent(int hour,int day,Company* cmp) : Event(hour,day,cmp)
{
	CargoPtr = nullptr;
}


bool ReadyEvent::Execute(Cargo* newCargo)                                          // adds a new cargo to waiting list
{

	CargoPtr = newCargo;
	int type = CargoPtr->GetCargoType();

	if (type == 0)
	{
		mainCompany->AddToNormalWaitingCargos(newCargo);
	}
	else if(type==1)
		mainCompany->AddToSpecialWaitingCargos(newCargo);
	else
		mainCompany->AddToVIPWaitingCargos(newCargo);

	return true;
}