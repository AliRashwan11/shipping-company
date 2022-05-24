#include "Cargo.h"



Cargo::Cargo(int a)
{
	if (a != 0 && a != 1 && a != 2)
		a = 0;
	CargoType = a;
	DeliveryTime = 0;
	AV = -1;

	PreparationTime = -1;
	//intruck = nullptr;
}

Cargo::Cargo()
{
	CargoType = 0;
	DeliveryTime = 0;
	AV = -1;
	PreparationTime = -1;


}

Cargo::Cargo(Cargo& copy)
{
	PreparationTime = copy.GetPreparationTime();
	LoadUnloadTime = copy.GetLoadUnloadTime();
	DeliveryDistance = copy.GetDeliveryDistance();
	Cost = copy.GetCost();
	CargoType = copy.GetCargoType();
	ID = copy.GetID();
	DeliveryTime = 0;
	AV = -1;
	PreparationTime = -1;


}
void Cargo::SetPreparationTime(int time)
{
	PreparationTime = time;
}

void Cargo::SetLoadUnloadTime(int time)
{
	LoadUnloadTime = time;
}

void Cargo::SetDeliveryDistance(int dist)
{
	DeliveryDistance = dist;
}

void Cargo::SetCost(int cost)
{
	Cost = cost;
}

void Cargo::SetType(int a)
{
	CargoType = a;
}

void Cargo::SetID(int a)
{
	ID = a;
}

int Cargo::GetCargoType()
{
	return CargoType;
}

int Cargo::GetCost()
{
	return Cost;
}

int Cargo::GetDeliveryDistance()
{
	return DeliveryDistance;
}

int Cargo::GetLoadUnloadTime()
{
	return LoadUnloadTime;
}

int Cargo::GetPreparationTime()
{
	return PreparationTime;
}

int Cargo::GetID()
{
	return ID;
}

void Cargo::SetDeliveryTime(int a)
{
	DeliveryTime = a;
}

int Cargo::GetDeliveryTime()
{
	return DeliveryTime;
}

int Cargo::GetAV()
{
	return AV;
}

void Cargo::SetAV(int a)
{
	AV = a;
}

void Cargo::SetFT(int a)
{
	FT = a;
}

int Cargo::GetFT()
{
	return FT;
}



void Cargo::operator= (Cargo car)
{
	PreparationTime = car.GetPreparationTime();
	LoadUnloadTime = car.GetLoadUnloadTime();
	DeliveryDistance = car.GetDeliveryDistance();
	Cost = car.GetCost();
	CargoType = car.GetCargoType();
	ID = car.GetID();

}