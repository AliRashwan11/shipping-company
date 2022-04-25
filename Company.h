#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include"truck.h"
#include"Cargo.h"
#include"Event.h"
#include"LinkedQueue.h"
#include"LinkedStack.h"
#include"LinkedList.h"
#include"LinkedPriorityQueue.h"
#include"Event.h"
#include"UI.h"

class Event;

using namespace std;


class Company
{
	string InputFileName;

	LinkedQueue<truck*> NormalEmptyTrucks;
	LinkedQueue<truck*> SpecialEmptyTrucks;
	LinkedQueue<truck*> VIPEmptyTrucks;

	LinkedQueue<truck*> NormalLoadingTrucks;
	LinkedQueue<truck*> SpecialLoadingTrucks;
	LinkedQueue<truck*> VIPLoadingTrucks;

	LinkedList NormalWaitingCargos;
	LinkedQueue<Cargo*> SpecialWaitingCargos;
	LinkedQueue<Cargo*> VIPWaitingCargos;

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
	void PrintVIPWaitingCargos();
	void PrintEvents();
	bool CargoSearch(int);
	Cargo* CargoCancelled(int);
	LinkedList GetNormalWaitingCargos(); //
	LinkedQueue<Event*> GetEvents();
	void SetNormalWaitingCargos(LinkedList); //
	void PrintNumberOfNormalCargos();

	void SimpleSimulator();

};

