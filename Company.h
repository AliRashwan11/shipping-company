#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include"truck.h"
#include"Cargo.h"
#include"Event.h"
#include"LinkedQueue.h"
#include"LinkedStack.h"
#include"LinkedPriorityQueue.h"
#include"Event.h"

class Event;

using namespace std;


class Company
{
	string InputFileName;
	LinkedQueue<truck*> NormalEmptyTrucks;
	LinkedQueue<truck*> SpecialEmptyTrucks;
	LinkedQueue<truck*> VIPEmptyTrucks;
	LinkedQueue<Cargo*> SpecialWaitingCargos;
	LinkedQueue<Cargo*> VIPWaitingCargos;
	int NumberOfJourneysBeforeCheckup;
	int AutoPromotionLimit;                                    // in days
	int maxW;                                                  // in hours
	int NumberOfEvents;

	LinkedPriorityQueue<Event*> Events;                        // priQ of events


public:
	LinkedQueue<Cargo*> NormalWaitingCargos;
	Company(string);
	int ReadFile(int, int);                // reads a text file in specified format 
	
	void PrintNormalEmptyTrucks();
	void PrintSpecialEmptyTrucks();
	void PrintVIPEmptyTrucks();
	void AddToNormalWaitingCargos(Cargo*);
	void AddToSpecialWaitingCargos(Cargo*);
	void AddToVIPWaitingCargos(Cargo*);
	void PrintmaxW();
	void PrintaAutoPromotionLimit();
	LinkedQueue<Cargo*> GetNormalWaitingCargos();
	void SetNormalWaitingCargos(LinkedQueue<Cargo*>);

};

