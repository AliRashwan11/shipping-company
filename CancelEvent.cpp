#include "CancelEvent.h"

CancelEvent::CancelEvent(int hour,int day,Company* mcp,int id) : Event(hour,day,mcp)
{
	IdOfCancelledCargo = id;
	WasFound = 0;
	cancelledCargo = nullptr;
}


bool CancelEvent::Execute(Cargo* cancelledcargo)
{

	cancelledCargo = nullptr;




	LinkedQueue<Cargo*> temp = mainCompany->GetNormalWaitingCargos();   // implemented

	Cargo* tempCargo=nullptr;


	LinkedQueue<Cargo*> temp2;

	while (!temp2.isEmpty())
	{
		temp2.Peek(tempCargo);
		temp2.Dequeue();
		cout << tempCargo->GetID() << endl;
		cout << "." << endl;
	}

	while (!temp.isEmpty())
	{
		temp.Peek(tempCargo);
		if (tempCargo->GetID() == IdOfCancelledCargo)
		{
			cancelledCargo = tempCargo;
			cancelledcargo = tempCargo;
			WasFound = 1;
			break;
		}

		temp.Dequeue();
		temp2.Enqueue(tempCargo);

	}


	// return true;

	if (WasFound == 0)
	{
		mainCompany->SetNormalWaitingCargos(temp2);
		return false;

	}
	else
	{
		

		//return true;
		temp.Peek(cancelledCargo);
		temp.Dequeue();
		//return true;

		while (!temp.isEmpty())
		{
			temp.Peek(tempCargo);
			temp.Dequeue();
			temp2.Enqueue(tempCargo);
		}
		//return true;
	

		// temp.Enqueue(cancelledCargo);
		while (!temp2.isEmpty())
		{
			temp2.Peek(tempCargo);
			temp2.Dequeue();
			temp.Enqueue(tempCargo);
		}
		//return true;

																// implemented

	
		mainCompany->SetNormalWaitingCargos(temp);

		return true;

	}
}
