#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include"truck.h"
#include"Cargo.h"
#include"Event.h"
#include"LinkedQueue.h"
#include"LinkedStack.h"


using namespace std;


class Company
{
	string InputFileName;
	LinkedQueue<truck*> EmptyTrucks;

public:

	Company(string);
	int ReadFile(int, int);                // reads a text file in specified format 
	
	void PrintEmptyTrucks();

};

