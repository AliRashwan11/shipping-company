#pragma once
#include "LinkedQueue.h"

class truck 
{

	int TruckCapacity;
	int TruckSpeed;
	int MaintenanceTime;
	int DeliveryInterval;
	int type;                                                // 0 for normal , 1 for special , 2 for vip                                     

public:

	truck(int);

/*
* 	 void LoadTruckInfo()                           
* {
* 
* }
* 
*/

	virtual void SetTruckCapacity(int);
	virtual int GetTruckCapacity();
	virtual void SetTruckSpeed(int);
	virtual int GetTruckSpeed();
	virtual void SetMaintenanceTime(int);
	virtual int GetMaintenanceTime();
	// virtual int GetDeliveryInterval();             to be implemented later


};

