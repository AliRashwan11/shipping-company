#include "Company.h"




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

		EmptyTrucks.Enqueue(newtruck);
	}

	// add truck delivery interval after implementing cargos





}


void Company::PrintEmptyTrucks()
{
	LinkedQueue<truck *> temp = EmptyTrucks;
	truck* tempt(0);
	while (!temp.isEmpty())
	{
		temp.Dequeue(tempt);
		cout << tempt->GetTruckCapacity() << endl;
	}
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

		if (entries == 1 || entries == 2)
		{
			int dummy;

			for (int i = 0; i < entries; i++)
			{
				infile >> dummy;

			}

			infile >> str;

			if (str.size() == 2)
				return (str[1] - '0');
			return stoi(str);

		}
		else
		{
			string dummy;
			for (int i = 0; i < (entries - 1); i++)
			{
				infile >> dummy;
			}
			infile >> str;
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

