#pragma once

class Cargo                                                   // class to instantiate a cargo object
{
	int PreparationTime;
	int LoadUnloadTime;                                       // Load Time is = Unload Time
	int DeliveryDistance;                                     // in KMs
	int Cost;
	int CargoType;                                            // 0 for normal , 1 for special , 2 for VIP
	int ID;

public:

	Cargo(int);
	void SetPreparationTime(int);
	void SetLoadUnloadTime(int);
	void SetDeliveryDistance(int);
	void SetCost(int);
	void SetID(int);
	int GetPreparationTime();
	int GetLoadUnloadTime();
	int GetDeliveryDistance();
	int GetCost();
	int GetCargoType();
	int GetID();

};

