#include "truck.h"

truck::truck(int typenum)
{
	if (typenum != 0 && typenum != 1 && typenum != 2)               // 0 for normal , 1 for special , 2 for VIP
		typenum = 0;
	TruckType = typenum;
	TruckCapacity = 0;
	TruckSpeed = 0;
	MaintenanceTime = 0;
	DeliveryInterval = 0;
	count = 0;
	StartedMoving = 0;
	NumberOfTripsDone = 0;
	TimeToGetOutOfCheckup = -1;
	WaitTime = 0;

}

truck::truck()
{
	TruckType = 0;
	TruckCapacity = 0;
	TruckSpeed = 0;
	MaintenanceTime = 0;
	DeliveryInterval = 0;
	count = 0;
	StartedMoving = 0;
	NumberOfTripsDone = 0;
	TimeToGetOutOfCheckup = -1;
	WaitTime = 0;


}

truck::truck(truck& copy)
{
	TruckType = copy.GetTruckType();
	TruckCapacity = copy.GetTruckCapacity();
	TruckSpeed = copy.GetTruckSpeed();
	MaintenanceTime = copy.GetMaintenanceTime();
	DeliveryInterval = copy.GetDeliveryInterval();
	count = 0;
	StartedMoving = 0;
	NumberOfTripsDone = 0;
	TimeToGetOutOfCheckup = -1;
	WaitTime = 0;


}

void truck::SetNumberOfTripsDone(int a)
{
	NumberOfTripsDone = a;
}

int truck::GetNumberOfTripsDone()
{
	return NumberOfTripsDone;
}

void truck::SetTruckCapacity(int a)
{
	TruckCapacity = a;
}

void truck::SetMaintenanceTime(int a)
{
	MaintenanceTime = a;
}

void truck::SetTruckSpeed(int a)
{
	TruckSpeed = a;
}

void truck::SetDeliveryInterval(int a)
{
	DeliveryInterval = a;
}

int truck::GetMaintenanceTime()
{
	return MaintenanceTime;
}

int truck::GetTruckCapacity()
{
	return TruckCapacity;
}

int truck::GetTruckType()
{
	return TruckType;
}

int truck::GetTruckSpeed()
{
	return TruckSpeed;
}

int truck::GetDeliveryInterval()
{
	return DeliveryInterval;
}

int truck::GetTypeOfLoadedCargos()
{
	return TypeOfLoadedCargos;
}

void truck::SetTypeOfLoadedCargos(int a)
{
	TypeOfLoadedCargos = a;
}

void truck::SetStartedMovingBool(bool a)
{
	StartedMoving = a;
}

bool truck::GetStartedMovingBool()
{
	return StartedMoving;
}

void truck::RemoveCargos()
{
	LinkedPriorityQueue<Cargo*> empty;
	InTruckCargos = empty;
}

int truck::GetTimeToGetOutOfCheckup()
{
	return TimeToGetOutOfCheckup;
}

void truck::SetTimeToGetOutOfCheckup(int a)
{
	TimeToGetOutOfCheckup = a;
}

void truck::SetCarriedCargos(LinkedPriorityQueue<Cargo*> a)
{
	Cargo* temp = nullptr;
	while (!InTruckCargos.isEmpty())
		InTruckCargos.Dequeue();

	while (!a.isEmpty())
	{
		a.Peek(temp);
		a.Dequeue();
		InTruckCargos.Enqueue(temp,0);
	}
}

void truck::SetBackTripTime(int a)
{
	BackTripTime = a;
}

int truck::GetBackTripTime()
{
	return BackTripTime;
}

/*
* int truck::GetDeliveryInterval()
{
	int a;
	return (a);                                   // ( delivery distance of furthest cargo / truck speed ) + sum of unload times of all cargos + time to come back
}
*/

void truck::SetID(int id)
{
	ID = id;
}


int truck::GetID()
{
	return ID;
}

void truck::AddToCargos(Cargo* ToAdd)
{
	int pri = 1000000 - (ToAdd->GetDeliveryDistance());
	InTruckCargos.Enqueue(ToAdd,pri);                              // priority from high to lower
	count++;
}

void truck::RemoveFromCargos()
{
	InTruckCargos.Dequeue();           
	count--;
}

int truck::GetCount()
{
	return count;
}

void truck::SetCount(int a)
{
	count = a;
}

int truck::GetWaitTime()
{
	return WaitTime;
}

void truck::SetWaitTime(int a)
{
	WaitTime = a;
}

LinkedPriorityQueue<Cargo*> truck::GetCarriedCargos()
{
	return InTruckCargos;
}

int truck::GetDeliveryTime()
{
	int max = -1;
	int currdist = -1;
	int currspeed = -1;
	int unloadtime = -1;
	Cargo* tempcargo = nullptr;
	LinkedPriorityQueue<Cargo*> temp = InTruckCargos;
	while (!temp.isEmpty())
	{
		temp.Peek(tempcargo);
		currdist = tempcargo->GetDeliveryDistance();
		if (currdist > max)
			max = currdist;
		unloadtime = tempcargo->GetLoadUnloadTime();
		temp.Dequeue();
	}

	currspeed = this->GetTruckCapacity();
	int TimeOfJourney = max / currspeed;

	int TotalTimeTaken = TimeOfJourney + unloadtime;

	return TotalTimeTaken;

}

void truck::SetStartTimeOfLoading(int a)
{
	StartTimeOfLoading = a;
}

int truck::GetStartTimeOfLoading()
{
	return StartTimeOfLoading;
}

void truck::SetStartTimeOfMoving(int a)
{
	StartTimeOfMoving = a;
}
int truck::GetStartTimeOfMoving()
{
	return StartTimeOfMoving;
}

Cargo* truck::DequeueCargo()
{
	Cargo* ret = nullptr;
	InTruckCargos.Peek(ret);
	InTruckCargos.Dequeue();
	return ret;
}

/*
void truck::SetLoaded(Cargo* inCargo)
{
	Loaded = inCargo;
}
*/