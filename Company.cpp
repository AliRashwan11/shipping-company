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



}

 
void Company::PrintNormalEmptyTrucks()                                                     // Function for testing
{
	LinkedQueue<truck *> temp = NormalEmptyTrucks;
	truck* tempt(0);
	while (!temp.isEmpty())
	{
		temp.Dequeue(tempt);
		cout << tempt->GetTruckSpeed() << endl;
	}
}

void Company::PrintSpecialEmptyTrucks()                                                     // Function for testing
{
	LinkedQueue<truck*> temp = SpecialEmptyTrucks;
	truck* tempt(0);
	while (!temp.isEmpty())
	{
		temp.Dequeue(tempt);
		cout << tempt->GetTruckSpeed() << endl;
	}
}


void Company::PrintVIPEmptyTrucks()                                                     // Function for testing
{
	LinkedQueue<truck*> temp = VIPEmptyTrucks;
	truck* tempt(0);
	while (!temp.isEmpty())
	{
		temp.Dequeue(tempt);
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

