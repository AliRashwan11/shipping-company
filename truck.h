#pragma once

class truck 
{

	int TruckCapacity;
	int TruckSpeed;
	int MaintenanceTime;
	int DeliveryInterval;
	int TruckType;                                                // 0 for normal , 1 for special , 2 for vip                                     

public:

	truck(int);

/*
* 	 void LoadTruckInfo()                           
* {
* 
* }
* 
*/

	void SetTruckCapacity(int);
	int GetTruckCapacity();
	void SetTruckSpeed(int);
	int GetTruckSpeed();
	void SetMaintenanceTime(int);
	int GetMaintenanceTime();
	int GetTruckType();

	// virtual int GetDeliveryInterval();             to be implemented later


};

