#pragma once
//#include"LinkedPriorityQueue.h"
#include"LinkedPriorityQueue.h"
#include"Cargo.h"

class truck
{

	int TruckCapacity;
	int TruckSpeed;
	int MaintenanceTime;
	int DeliveryInterval;
	int TruckType;                                                // 0 for normal , 1 for special , 2 for vip       
	int ID;                                                       // 10n for normal , 20n for special , 30n for VIP
	int TypeOfLoadedCargos;                           // 0 for normal , 1 for vip , 2 for special
	int count;                                        // count of cargos in truck


	LinkedPriorityQueue<Cargo*> InTruckCargos;                                           // pointer to last cargo

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
	void AddToCargos(Cargo*);
	void RemoveFromCargos();
	int GetTypeOfLoadedCargos();
	void SetTypeOfLoadedCargos(int);
	int GetCount();
	LinkedPriorityQueue<Cargo*> GetCarriedCargos();

	// virtual int GetDeliveryInterval();             to be implemented later




};
