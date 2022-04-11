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


using namespace std;


class Company
{
	string InputFileName;
	LinkedQueue<truck*> NormalEmptyTrucks;
	LinkedQueue<truck*> SpecialEmptyTrucks;
	LinkedQueue<truck*> VIPEmptyTrucks;
	int NumberOfJourneysBeforeCheckup;
	int AutoPromotionLimit;                                    // in days
	int maxW;                                                  // in hours

	LinkedPriorityQueue<Event*> Events;                        // priQ of events


public:

	Company(string);
	int ReadFile(int, int);                // reads a text file in specified format 
	
	void PrintNormalEmptyTrucks();
	void PrintSpecialEmptyTrucks();
	void PrintVIPEmptyTrucks();
	void PrintmaxW();
	void PrintaAutoPromotionLimit();

};

