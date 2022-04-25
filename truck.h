#pragma once

class truck 
{

	int TruckCapacity;
	int TruckSpeed;
	int MaintenanceTime;
	int DeliveryInterval;
	int TruckType;                                                // 0 for normal , 1 for special , 2 for vip       
	int ID;                                                       // 10n for normal , 20n for special , 30n for VIP

public:

	truck(int);
	truck();
	truck(truck&);
	void SetTruckCapacity(int);
	int GetTruckCapacity();
	void SetTruckSpeed(int);
	void SetDeliveryInterval(int);
	void SetID(int);
	int GetTruckSpeed();
	void SetMaintenanceTime(int);
	int GetMaintenanceTime();
	int GetTruckType();
	int GetDeliveryInterval();
	int GetID();

	// virtual int GetDeliveryInterval();             to be implemented later




};

