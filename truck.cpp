#include "truck.h"

truck::truck(int typenum)
{
	if (typenum != 0 && typenum != 1 && typenum != 2)               // 0 for normal , 1 for special , 2 for VIP
		typenum = 0;
	type = typenum;
	TruckCapacity = 0;
	TruckSpeed = 0;
	MaintenanceTime = 0;
	DeliveryInterval = 0;
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

int truck::GetMaintenanceTime()
{
	return MaintenanceTime;
}

int truck::GetTruckCapacity()
{
	return TruckCapacity;
}

int truck::GetTruckSpeed()
{
	return TruckSpeed;
}

/*
* int truck::GetDeliveryInterval()
{
	int a;
	return (a);                                   // ( delivery distance of furthest cargo / truck speed ) + sum of unload times of all cargos + time to come back
}
*/


