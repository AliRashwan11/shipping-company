#pragma once
#include"LinkedPriorityQueue.h"
#include"Cargo.h"
#include"truck.h"
#include <iostream>
#include<conio.h>
#include<windows.h>
#include<string>
#include<fstream>


using namespace std;


class UserInterface
{
	int Hour;
	int Day;
	int Mode;                       // indicates mode of interface < choosen by the user >
	string inputFileName;

public:

	UserInterface();                           // enables user to choose mode of interface ( Sets Mode data member )

	void OutputInterface();         // outputs chosen mode of interface

	int GetHour();
	int GetDay();

	// void OutputFile();                  // allows to output to user

	void PrintStartSim();
	void PrintHourAdvance(int,int);
	void PrintWaitingCargos(int,int*,int,int*,int,int*);
	void PrintWaitingCargosInfo(int);
	void PrintDeliveredCargosInfo(int);
	void PrintMovingCargosInfo(int);
	void DemoPrintLoadingTrucks();
	void DemoPrintEmptyTrucks(int,int,int);
	void DemoPrintMovingcargos();
	void DemoPrintDeliveredCargos();
	void DemoPrintInCheckupTrucks();
	void DrawLines();
	void PrintNormalWaitingCargos(int, int*);
	void PrintSpecialWaitingCargos(int, int*);
	void PrintVIPWaitingCargos(int, int*);
	void PrintListSimSpecial(LinkedPriorityQueue<Cargo*>);
	void PrintListSimNormal(LinkedPriorityQueue<Cargo*>);
	void PrintListSimVIP(LinkedPriorityQueue<Cargo*>);
	void PrintLoadingInfo(int);
	void PrintLoadingTrucksInfo(truck*,truck*,truck*);
	void PrintNormalLoading(truck*);
	void PrintVIPLoading(truck*);
	void PrintSpecialLoading(truck*);


	~UserInterface();
};

