#include"ReadyEvent.h"


ReadyEvent::ReadyEvent(int hour,int day,Company cmp) : Event(hour,day,cmp)
{
	
}


bool ReadyEvent::Execute(Cargo* newCargo)                                          // adds a new cargo to waiting list
{
	int type = newCargo->GetCargoType();


	if (type == 0)
		mainCompany->AddToNormalWaitingCargos(newCargo);
	else if(type==1)
		mainCompany->AddToSpecialWaitingCargos(newCargo);
	else
		mainCompany->AddToVIPWaitingCargos(newCargo);

	return true;
}