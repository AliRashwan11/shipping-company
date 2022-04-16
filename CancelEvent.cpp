#include "CancelEvent.h"

CancelEvent::CancelEvent(int hour,int day,Company mcp,int id) : Event(hour,day,mcp)
{
	IdOfCancelledCargo = id;
	WasFound = 0;
}


bool CancelEvent::Execute(Cargo* cancelledCargo)
{
	int idOfcargo = cancelledCargo->GetID();

	LinkedQueue<Cargo*> temp = mainCompany->GetNormalWaitingCargos();
	LinkedQueue<Cargo*> temp2;
	Cargo* tempCargo;

	while (!temp.isEmpty())
	{
		temp.Peek(tempCargo);
		if (tempCargo->GetID() == IdOfCancelledCargo)
		{
			cancelledCargo = tempCargo;
			WasFound = 1;
			break;
		}

		temp2.Enqueue(tempCargo);
		temp.Dequeue(tempCargo);

	}

	if (WasFound == 0)
	{
		mainCompany->SetNormalWaitingCargos(temp2);
		return false;
	}
	else
	{
		while (!temp.isEmpty())
		{
			temp.Dequeue(tempCargo);
			temp2.Enqueue(tempCargo);
		}

		temp.Enqueue(cancelledCargo);

		while (!temp2.isEmpty())
		{
			temp2.Dequeue(tempCargo);
			temp.Enqueue(tempCargo);
		}

		mainCompany->SetNormalWaitingCargos(temp);
	}
	return true;
}
