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

class Event;

using namespace std;


class Company
{
	string InputFileName;
	LinkedList NormalWaitingCargos;
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
	Company(string);
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
	bool CargoSearch(int);
	void CargoCancelled(int);
	LinkedList GetNormalWaitingCargos(); //
	void SetNormalWaitingCargos(LinkedList); //

};

