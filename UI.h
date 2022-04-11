#pragma once
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


	~UserInterface();
};

