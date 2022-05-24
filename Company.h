#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include"Cargo.h"
#include"Event.h"
#include"LinkedQueue.h"
#include"LinkedStack.h"
#include"LinkedList.h"
#include"LinkedPriorityQueue.h"
#include"Event.h"
#include"UI.h"
#include"truck.h"


class Event;

using namespace std;


class Company
{
	string InputFileName;

	LinkedQueue<truck*> NormalEmptyTrucks;
	LinkedQueue<truck*> SpecialEmptyTrucks;
	LinkedQueue<truck*> VIPEmptyTrucks;

	//LinkedQueue<truck*> NormalLoadingTrucks;
	//LinkedQueue<truck*> SpecialLoadingTrucks;
	//LinkedQueue<truck*> VIPLoadingTrucks;

	LinkedPriorityQueue<truck*> MovingTrucks;
	LinkedQueue<truck*> LoadingTrucks;

	LinkedList NormalWaitingCargos;
	LinkedQueue<Cargo*> SpecialWaitingCargos;
	LinkedPriorityQueue<Cargo*> VIPWaitingCargos; 

	LinkedPriorityQueue<Cargo*> NormalMovingCargos;
	LinkedPriorityQueue<Cargo*> SpecialMovingCargos;
	LinkedPriorityQueue<Cargo*> VIPMovingCargos;

	LinkedQueue<truck*> InCheckupNormal;
	LinkedQueue<truck*> InCheckupSpecial;
	LinkedQueue<truck*> InCheckupVIP;



	LinkedPriorityQueue<Cargo*> DeliveredCargos;
	
	LinkedPriorityQueue<truck*> OnWayBackTrucks;

	truck* TruckLoadingNormals;
	truck* TruckLoadingSpecials;
	truck* TruckLoadingVIPs;


	int NumberOfJourneysBeforeCheckup;
	int AutoPromotionLimit;                                    // in days
	int maxW;                                                  // in hours
	int NumberOfEvents;
	
	LinkedQueue<Event*> Events;                        

	UserInterface* mainInterface;
	int* IdsOfNormalCargos;
	int* IdsOfSpecialCargos;
	int* IdsOfVIPCargos;

	int NumberOfNormalCargos;
	int NumberOfSpecialCargos;
	int NumberOfVIPCargos;

	int CapNormalTrucks;
	int CapSpecialTrucks;
	int CapVIPTrucks;

	int CurrentlyLoading;

	int NumberOfDeliveredCargos;
	 
	int NumberOfDeliveredNormalCargos;
	int NumberOfDeliveredSpecialCargos;
	int NumberOfDeliveredVIPCargos;

	int NumberOfNormalTrucks;
	int NumberOfSpecialTrucks;
	int NumberOfVIPTrucks;

	int MaintenanceTimeOfNormals;
	int MaintenanceTimeOfSpecials;
	int MaintenanceTimeOfVIPs;

	bool UpdateStartTimeOfLoadingNormals;
	bool UpdateStartTimeOfLoadingSpecials;
	bool UpdateStartTimeOfLoadingVIPs;


public:
	Company(string,UserInterface*);
	int ReadSubFile(int, int);                // reads a text file in specified format 
	void ReadFile();                          // uses ReadSubFile to read entire input file
	
	void PrintNormalEmptyTrucks();
	void PrintSpecialEmptyTrucks();
	void PrintVIPEmptyTrucks();
	void AddToNormalWaitingCargos(Cargo*); //
	void AddToSpecialWaitingCargos(Cargo*);
	void AddToVIPWaitingCargos(Cargo*);
	void PrintmaxW();
	void PrintaAutoPromotionLimit();
	void PrintNormalWaitingCargos();
	void PrintWaitingCargosSim();
	void PrintMovingCargosSim();
	void PrintDeliveredCargosSim();
	void PrintVIPWaitingCargos();
	void PrintDeliveredCargos();
	void PrintEmptyTrucks();
	void PrintEvents();
	void PrintMovingTrucksSim();
	void AddToNormalMovingcargos(Cargo*);
	void AddToSpecialMovingcargos(Cargo*);
	void AddToVIPMovingcargos(Cargo*);
	bool CargoSearch(int);
	Cargo* CargoCancelled(int);
	LinkedList GetNormalWaitingCargos(); //
	LinkedQueue<Event*> GetEvents();
	void SetNormalWaitingCargos(LinkedList); //
	void PrintNumberOfNormalCargos();
	void PrintLoadingTrucks();
	void PrintIncheckups();
	Cargo* GetFirstCargoInNormalWaitingCargos();
	void OutputFile();

	void SimpleSimulator();
	void Simulator();

};

