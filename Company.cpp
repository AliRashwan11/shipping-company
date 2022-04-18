#include "Company.h"
#include"math.h"




Company::Company(string infile)
{
	InputFileName = infile;

	int NumberOfNormalTrucks = ReadFile(0,0);
	int SpeedOfNormalTrucks = ReadFile(1,0);
	int NormalTruckCapacity = ReadFile(2, 0);
	int CheckUpDurationOfNormalTrucks = ReadFile(3, 1);

	for (int i = 0; i < NumberOfNormalTrucks; i++)
	{
		truck* newtruck = new truck(0);
		newtruck->SetTruckSpeed(SpeedOfNormalTrucks);
		newtruck->SetTruckCapacity(NormalTruckCapacity);
		newtruck->SetMaintenanceTime(CheckUpDurationOfNormalTrucks);

		NormalEmptyTrucks.Enqueue(newtruck);
	}

	// add truck delivery interval after implementing cargos


	int NumberOfSpecialTrucks = ReadFile(0,1);
	int SpeedOfSpecialTrucks = ReadFile(1,1);
	int SpecialTruckCapacity = ReadFile(2,1);
	int CheckUpDurationOfSpecialTrucks = ReadFile(3,2);

	for (int i = 0; i < NumberOfSpecialTrucks; i++)
	{
		truck* newstruck = new truck(1);
		newstruck->SetTruckSpeed(SpeedOfSpecialTrucks);
		newstruck->SetTruckCapacity(SpecialTruckCapacity);
		newstruck->SetMaintenanceTime(CheckUpDurationOfSpecialTrucks);

		SpecialEmptyTrucks.Enqueue(newstruck);
	}

	int NumberOfVIPTrucks = ReadFile(0, 2);
	int SpeedOfVIPTrucks = ReadFile(1, 2);
	int VIPTruckCapacity = ReadFile(2, 2);
	int CheckUpDurationOfVIPTrucks = ReadFile(3, 3);

	for (int i = 0; i < NumberOfVIPTrucks; i++)
	{
		truck* newvtruck = new truck(2);
		newvtruck->SetTruckSpeed(SpeedOfVIPTrucks);
		newvtruck->SetTruckCapacity(VIPTruckCapacity);
		newvtruck->SetMaintenanceTime(CheckUpDurationOfVIPTrucks);

		VIPEmptyTrucks.Enqueue(newvtruck);
	}


	NumberOfJourneysBeforeCheckup = ReadFile(3,0);
	AutoPromotionLimit = ReadFile(4,0);
	maxW = ReadFile(4,1);
	NumberOfEvents = ReadFile(5,0);

	string EventType;


	


}

void Company::PrintNormalEmptyTrucks()                                                     // Function for testing
{
	LinkedQueue<truck *> temp = NormalEmptyTrucks;
	truck* tempt(0);
	while (!temp.isEmpty())
	{
		temp.Dequeue();
		cout << tempt->GetTruckSpeed() << endl;
	}
}

void Company::PrintSpecialEmptyTrucks()                                                     // Function for testing
{
	LinkedQueue<truck*> temp = SpecialEmptyTrucks;
	truck* tempt(0);
	while (!temp.isEmpty())
	{
		temp.Dequeue();
		cout << tempt->GetTruckSpeed() << endl;
	}
}


void Company::PrintVIPEmptyTrucks()                                                     // Function for testing
{
	LinkedQueue<truck*> temp = VIPEmptyTrucks;
	truck* tempt(0);
	while (!temp.isEmpty())
	{
		temp.Dequeue();
		cout << tempt->GetTruckCapacity() << endl;
	}
}

void Company::PrintmaxW()
{
	cout << maxW << endl;
}

void Company::PrintaAutoPromotionLimit()
{
	cout << AutoPromotionLimit << endl;
}

void Company::AddToNormalWaitingCargos(Cargo* newCargo)
{
	NormalWaitingCargos.Enqueue(newCargo);
	return;
}

void Company::AddToSpecialWaitingCargos(Cargo* newCargo)
{
	SpecialWaitingCargos.Enqueue(newCargo);
}

void Company::AddToVIPWaitingCargos(Cargo* newCargo)
{
	VIPWaitingCargos.Enqueue(newCargo);
}

LinkedQueue<Cargo*> Company::GetNormalWaitingCargos()
{
	return NormalWaitingCargos;
}

void Company::SetNormalWaitingCargos(LinkedQueue<Cargo*> newQueue)
{
	NormalWaitingCargos = newQueue;
	return;
}



int Company::ReadFile(int lines, int entries)
{


	ifstream infile(InputFileName);
	string ignored;
	char dummychar;
	for (int i = 0; i < lines; i++)
	{
		getline(infile, ignored);
	}
	string str;
	if (lines >= 6)
	{
		char type;
		infile >> type;
		int c = 0;

		if ((entries == 3 || entries == 2) && (type == 'R'))
		{

			infile >> str;
			char dc;
			infile >> dc;
			int* day = new int[2];
			int* hour = new int[2];
			while (dc != ':')
			{
				day[c] = dc - '0';
				c++;
				infile >> dc;
			}

			if (entries == 2)
			{
				int ret = 0;
				for (int i = 0; i < c; i++)
				{
					ret = ret + (day[c - 1 - i] * pow(10, i));
				}
				return ret;
			}

			infile >> str;
			return stoi(str);

		}
		else if ((entries == 1 || entries == 2) && (type != 'R'))
		{
			char dc;
			infile >> dc;
			int* day = new int[2];
			int* hour = new int[2];
			while (dc != ':')
			{
				day[c] = dc - '0';
				c++;
				infile >> dc;
			}

			if (entries == 1)
			{
				int ret = 0;
				for (int i = 0; i < c; i++)
				{
					ret = ret + (day[c - 1 - i] * pow(10, i));
				}
				return ret;
			}

			infile >> str;
			return stoi(str);
		}
		else if ((type == 'R' && entries > 3) || ((type != 'R') && entries > 2))
		{
			int count = 0;
			if (type == 'R')
			{
				for (int i = 0; i < 3; i++)
					infile >> str;
				count = 4;
			}
			else
			{
				for (int i = 0; i < 2; i++)
					infile >> str;
				count = 3;
			}
			if (count == entries)
			{
				return stoi(str);
			}
			for (int i = 0; i < entries - count - 1; i++)
			{
				infile >> str;
			}
			infile >> str;

			return stoi(str);
		}
		else
		{
			if (entries == 0)
				return type;
			char dummy;
			for (int i = 0; i < entries - 1; i++)
			{
				infile >> dummy;
			}
			infile >> str;
			if (str == "R" || str == "N" || str == "S" || str == "V" || str == "X" || str == "P")
			{
				char ret = str[0];
				return ret;
			}
			return stoi(str);
		}

	}
	else
	{
		string dummy;
		for (int i = 0; i < entries; i++)
		{
			infile >> dummy;
		}
		infile >> str;
		return stoi(str);
	}


}

