#include "CancelEvent.h"

CancelEvent::CancelEvent(int hour,int day,Company* mcp,int id) : Event(hour,day,mcp)
{
	IdOfCancelledCargo = id;
	WasFound = 0;
	cancelledCargo = nullptr;
}


bool CancelEvent::Execute()
{
	WasFound = mainCompany->CargoSearch(IdOfCancelledCargo);    // searches in NormalWaitingCargos only ...

	if (WasFound)
	{
		mainCompany->CargoCancelled(IdOfCancelledCargo);
		return true;
	}

	return false;
}
