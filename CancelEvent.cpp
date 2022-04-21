#include "CancelEvent.h"

CancelEvent::CancelEvent(int hour,int day,Company* mcp,int id) : Event(hour,day,mcp)
{
	IdOfCancelledCargo = id;
	WasFound = 0;
	cancelledCargo = nullptr;
}


bool CancelEvent::Execute(Cargo* cancelledcargo)
{
	WasFound = mainCompany->CargoSearch(IdOfCancelledCargo);

	if (WasFound)
	{
		mainCompany->CargoCancelled(IdOfCancelledCargo);
		return true;
	}

	return false;
}
