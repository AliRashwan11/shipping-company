#pragma once
#include <iostream>
#include<conio.h>
#include<windows.h>
#include<string>
#include<fstream>


using namespace std;


class UserInterface
{
	int Mode;                       // indicates mode of interface < choosen by the user >

public:

	UserInterface();                           // enables user to choose mode of interface ( Sets Mode data member )

	void OutputInterface();         // outputs chosen mode of interface

	int ReadFile(int,int,string);                // reads a text file in specified format 

	// void Input();                   // allows to take input from user

	// void Output();                  // allows to output to user


	~UserInterface();
};

