#include "Company.h"
#include"math.h"
#include"ReadyEvent.h"
#include"CancelEvent.h"
#include"PromotionEvent.h"



Company::Company(string infile,UserInterface* uiptr)
{
	InputFileName = infile;
	mainInterface = uiptr;
	IdsOfNormalCargos = new int[100];
	IdsOfSpecialCargos = new int[100];
	IdsOfVIPCargos = new int[100];
	NumberOfNormalCargos = 0;
	NumberOfSpecialCargos = 0;
	NumberOfVIPCargos = 0;
}

void Company::PrintNormalEmptyTrucks()                                                     // Function for testing
{
	LinkedQueue<truck *> temp = NormalEmptyTrucks;
	truck* tempt=nullptr;
	while (!temp.isEmpty())
	{
		temp.Peek(tempt);
		temp.Dequeue();
		cout << tempt->GetTruckSpeed() << endl;
	}
}

void Company::PrintVIPWaitingCargos()
{
	Cargo* temp = nullptr;
	while (!VIPWaitingCargos.isEmpty())
	{
		VIPWaitingCargos.Peek(temp);
		VIPWaitingCargos.Dequeue();
		cout << temp->GetID();
	}
}

void Company::PrintSpecialEmptyTrucks()                                                     // Function for testing
{
	LinkedQueue<truck*> temp = SpecialEmptyTrucks;
	truck* tempt=nullptr;
	while (!temp.isEmpty())
	{
		temp.Peek(tempt);
		temp.Dequeue();
		cout << tempt->GetTruckSpeed() << endl;
	}
}


void Company::PrintVIPEmptyTrucks()                                                     // Function for testing
{
	LinkedQueue<truck*> temp = VIPEmptyTrucks;
	truck* tempt=nullptr;
	while (!temp.isEmpty())
	{
		temp.Peek(tempt);
		temp.Dequeue();
		cout << tempt->GetTruckSpeed() << endl;
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
	NormalWaitingCargos.InsertEnd(newCargo);
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

LinkedList Company::GetNormalWaitingCargos()        // slow execution 
{
	return NormalWaitingCargos;
}

void Company::SetNormalWaitingCargos(LinkedList newlist)
{
	NormalWaitingCargos = newlist;
	return;
}

bool Company::CargoSearch(int id)
{
	return NormalWaitingCargos.Find(id);
}

Cargo* Company::CargoCancelled(int id)
{
	Cargo* ret = NormalWaitingCargos.FindCargo(id);
	NormalWaitingCargos.DeleteNode(id);
	return ret;
}


int Company::ReadSubFile(int lines, int entries)
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



void Company::ReadFile()
{

	int NumberOfNormalTrucks = ReadSubFile(0, 0);
	int SpeedOfNormalTrucks = ReadSubFile(1, 0);
	int NormalTruckCapacity = ReadSubFile(2, 0);
	int CheckUpDurationOfNormalTrucks = ReadSubFile(3, 1);

	for (int i = 0; i < NumberOfNormalTrucks; i++)
	{
		truck* newtruck = new truck(0);
		newtruck->SetID(i);
		newtruck->SetTruckSpeed(SpeedOfNormalTrucks);
		newtruck->SetTruckCapacity(NormalTruckCapacity);
		newtruck->SetMaintenanceTime(CheckUpDurationOfNormalTrucks);

		NormalEmptyTrucks.Enqueue(newtruck);
	}

	// add truck delivery interval after implementing cargos


	int NumberOfSpecialTrucks = ReadSubFile(0, 1);
	int SpeedOfSpecialTrucks = ReadSubFile(1, 1);
	int SpecialTruckCapacity = ReadSubFile(2, 1);
	int CheckUpDurationOfSpecialTrucks = ReadSubFile(3, 2);

	for (int i = 0; i < NumberOfSpecialTrucks; i++)
	{
		truck* newstruck = new truck(1);
		newstruck->SetID(NumberOfNormalTrucks +i);
		newstruck->SetTruckSpeed(SpeedOfSpecialTrucks);
		newstruck->SetTruckCapacity(SpecialTruckCapacity);
		newstruck->SetMaintenanceTime(CheckUpDurationOfSpecialTrucks);

		SpecialEmptyTrucks.Enqueue(newstruck);
	}

	int NumberOfVIPTrucks = ReadSubFile(0, 2);
	int SpeedOfVIPTrucks = ReadSubFile(1, 2);
	int VIPTruckCapacity = ReadSubFile(2, 2);
	int CheckUpDurationOfVIPTrucks = ReadSubFile(3, 3);

	for (int i = 0; i < NumberOfVIPTrucks; i++)
	{
		truck* newvtruck = new truck(2);
		newvtruck->SetID(NumberOfSpecialTrucks +i);
		newvtruck->SetTruckSpeed(SpeedOfVIPTrucks);
		newvtruck->SetTruckCapacity(VIPTruckCapacity);
		newvtruck->SetMaintenanceTime(CheckUpDurationOfVIPTrucks);

		VIPEmptyTrucks.Enqueue(newvtruck);
	}


	NumberOfJourneysBeforeCheckup = ReadSubFile(3, 0);
	AutoPromotionLimit = ReadSubFile(4, 0);
	maxW = ReadSubFile(4, 1);
	NumberOfEvents = ReadSubFile(5, 0);

	int EventType = -1;
	int CargoTypeIndicator = -1;
	int CargoType = -1;
	int Day = -1;
	int Hour = -1;
	int CargoID = -1;
	int CargoDist = -1;
	int LT = -1;
	int CargoCost = -1;
	int ExtraMoney = -1;

	Cargo* newCargoAdded = nullptr;
	ReadyEvent* ready = nullptr;
	CancelEvent* cancel = nullptr;
	PromotionEvent* promote = nullptr;
	int k1 = 0;
	int k2 = 0;
	int k3 = 0;

	for (int i=0 ; i<NumberOfEvents ; i++)
	{
		EventType = ReadSubFile(6+i,0);

		if (EventType == 82) // ready event
		{
			
			CargoTypeIndicator = ReadSubFile(6+i,1);
			
			if (CargoTypeIndicator == 78) // normal cargo
			{
				CargoType = 0;
				k1++;
			}
			else if (CargoTypeIndicator == 83) // special cargo
			{
				CargoType = 1;
				k2++;

			}
			else
			{
				CargoType = 2;
				k3++;
			}


			Day = ReadSubFile(6+i,2);
			Hour = ReadSubFile(6+i,3);
			CargoID = ReadSubFile(6+i,4);
			CargoDist = ReadSubFile(6+i,5);
			LT = ReadSubFile(6+i,6);
			CargoCost = ReadSubFile(6+i,7);


			newCargoAdded = new Cargo(CargoType);
			newCargoAdded->SetCost(CargoCost);
			newCargoAdded->SetDeliveryDistance(CargoDist);
			newCargoAdded->SetID(CargoID);
			newCargoAdded->SetLoadUnloadTime(LT);
			// newCargoAdded->SetPreparationTime();                            // preparation time calculation -- phase-2



			ready = new ReadyEvent(Hour, Day, this, newCargoAdded);
			Events.Enqueue(ready);
			// cout << k1 << " >>>>>>> <<<<<<<<" << endl;
			NumberOfNormalCargos = k1;
			NumberOfSpecialCargos = k2;
			NumberOfVIPCargos = k3;

		}
		else if (EventType== 88) // cancellation event
		{
			Day = ReadSubFile(6 + i, 1);
			Hour = ReadSubFile(6 + i, 2);
			CargoID = ReadSubFile(6+i,3);

			cancel = new CancelEvent(Hour, Day, this, CargoID);
			Events.Enqueue(cancel);
		}
		else // promotion event
		{
			Day = ReadSubFile(6 + i, 1);
			Hour = ReadSubFile(6 + i, 2);
			CargoID = ReadSubFile(6 + i, 3);
			ExtraMoney = ReadSubFile(6+i,4);

			promote = new PromotionEvent(Hour, Day, this, CargoID, ExtraMoney);
			Events.Enqueue(promote);
		}

	}

}

void Company::PrintNumberOfNormalCargos()      // test fn .. removed later
{
	cout << NumberOfNormalCargos << endl;
}

LinkedQueue<Event*> Company::GetEvents()
{
	return Events;
}

void Company::PrintNormalWaitingCargos()
{
	NormalWaitingCargos.PrintList();
}

void Company::PrintWaitingCargosSim()
{
	int n1=NormalWaitingCargos.GetNumberOfCargos();
	int n2=SpecialWaitingCargos.GetNumberOfEntries();
	int n3=VIPWaitingCargos.GetNumberOfEntries();
	int sum = n1+n2+n3;

	mainInterface->PrintWaitingCargosInfo(sum);
	NormalWaitingCargos.PrintListSimNormal();
	SpecialWaitingCargos.PrintListSimSpecial();
	VIPWaitingCargos.PrintListSimVIP();
}

void Company::PrintMovingCargosSim()
{
	int n1 = NormalMovingCargos.GetNumberOfEntries();
	int n2 = SpecialMovingCargos.GetNumberOfEntries();
	int n3 = VIPMovingCargos.GetNumberOfEntries();
	int sum = n1 + n2 + n3;

	mainInterface->PrintMovingCargosInfo(sum);
	NormalMovingCargos.PrintListSimNormal();
	SpecialMovingCargos.PrintListSimSpecial();
	VIPMovingCargos.PrintListSimVIP();
}

void Company::PrintDeliveredCargosSim()
{
	int n1 = NormalDeliveredCargos.GetNumberOfEntries();
	int n2 = SpecialDeliveredCargos.GetNumberOfEntries();
	int n3 = VIPDeliveredCargos.GetNumberOfEntries();
	int sum = n1 + n2 + n3;

	mainInterface->PrintDeliveredCargosInfo(sum);
	NormalDeliveredCargos.PrintListSimNormal();
	SpecialDeliveredCargos.PrintListSimSpecial();
	VIPDeliveredCargos.PrintListSimVIP();
}

void Company::PrintEvents()
{
	Event* tempe = nullptr;
	while (!Events.isEmpty())
	{
		Events.Peek(tempe);
		Events.Dequeue();
		cout << tempe->GetDay() << " . " << tempe->GetHour() << endl;
		
	}
}

void Company::AddToNormalMovingcargos(Cargo* cgr)
{
	NormalMovingCargos.Enqueue(cgr);
}

void Company::AddToSpecialMovingcargos(Cargo* cgr)
{
	SpecialMovingCargos.Enqueue(cgr);
}

void Company::AddToVIPMovingcargos(Cargo* cgr)
{
	VIPMovingCargos.Enqueue(cgr);
}

Cargo* Company::GetFirstCargoInNormalWaitingCargos()
{
	NormalWaitingCargos.PrintIdList();
	return nullptr;
}



void Company::SimpleSimulator()
{

	this->ReadFile();

	int numberofnormaltrucks = ReadSubFile(0,0);
	int numberofspecialtrucks = ReadSubFile(0,1);
	int numberofviptrucks = ReadSubFile(0,2);

	int numberofspecialcargos = SpecialWaitingCargos.GetNumberOfEntries();
	int numberofvipcargos = VIPWaitingCargos.GetNumberOfEntries();
	int numberofnormalcargos = NormalWaitingCargos.GetNumberOfCargos();


	

	int TotalNumberOfCargos = numberofspecialcargos + numberofvipcargos + numberofnormalcargos;

	int TotalNumberOfTrucks = numberofnormalcargos + numberofspecialcargos + numberofvipcargos;



	int Hour = 0;
	int Day = 0;

	int key = 1000;
	Cargo* cargo1 = nullptr;
	Cargo* cargo2 = nullptr;
	Cargo* cargo3 = nullptr;
	Event* nextevent = nullptr;
	Events.Peek(nextevent);

	int counterto5n = 0;
	int counterto5s = 0;
	int counterto5v = 0;

	while (true)
	{
		
	
		
	
		
		/*
		if (!NormalWaitingCargos.isEmpty())
		{
			Cargo* tempCargo = NormalWaitingCargos.DeleteFirst();
			//cout << tempCargo->GetID() << endl;
			AddToNormalMovingcargos(tempCargo);
		}
		*/
		
	
		


		if (!SpecialWaitingCargos.isEmpty())
		{
			Cargo* tempCargo = nullptr;
			SpecialWaitingCargos.Peek(tempCargo);
			SpecialWaitingCargos.Dequeue();
			//cout << tempCargo->GetID() << endl;
			AddToSpecialMovingcargos(tempCargo);
		}


		if (!VIPWaitingCargos.isEmpty())
		{
			Cargo* tempCargo = nullptr;
			VIPWaitingCargos.Peek(tempCargo);
			VIPWaitingCargos.Dequeue();
			//cout << tempCargo->GetID() << endl;
			AddToVIPMovingcargos(tempCargo);
		}

	

		if (!NormalMovingCargos.isEmpty())
		{
			if (counterto5n == 5)
			{
				Cargo* crg = nullptr;
				counterto5n = 0;
				NormalMovingCargos.Peek(crg);
				NormalMovingCargos.Dequeue();
				NormalDeliveredCargos.Enqueue(crg);
			}
			else
				counterto5n++;

			
		}

		if (!SpecialMovingCargos.isEmpty())
		{
			if (counterto5s == 5)
			{
				Cargo* crg = nullptr;
				counterto5s = 0;
				SpecialMovingCargos.Peek(crg);
				SpecialMovingCargos.Dequeue();
				SpecialDeliveredCargos.Enqueue(crg);
			}
			else
				counterto5s++;


		}

		if (!VIPMovingCargos.isEmpty())
		{
			if (counterto5v == 5)
			{
				Cargo* crg = nullptr;
				counterto5v = 0;
				VIPMovingCargos.Peek(crg);
				VIPMovingCargos.Dequeue();
				VIPDeliveredCargos.Enqueue(crg);
			}
			else
				counterto5v++;


		}

		if (nextevent->GetDay() == Day && nextevent->GetHour() == Hour)
		{
			nextevent->Execute();
			Events.Dequeue();
			if (!Events.isEmpty())
			{
				Events.Peek(nextevent);
				while (nextevent->GetHour() == Hour && nextevent->GetDay() == Day)
				{
					nextevent->Execute();
					Events.Dequeue();
					Events.Peek(nextevent);
				}
			}
		}

		mainInterface->PrintStartSim();
		mainInterface->PrintHourAdvance(Day, Hour);
		PrintWaitingCargosSim();
		mainInterface->DrawLines();
		mainInterface->DemoPrintLoadingTrucks();
		mainInterface->DrawLines();
		mainInterface->DemoPrintEmptyTrucks(numberofnormaltrucks, numberofspecialtrucks, numberofviptrucks);
		mainInterface->DrawLines();
		PrintMovingCargosSim();
		mainInterface->DrawLines();
		mainInterface->DemoPrintMovingcargos();
		mainInterface->DemoPrintInCheckupTrucks();
		mainInterface->DrawLines();
		PrintDeliveredCargosSim();
		mainInterface->DrawLines();





		//PrintNormalWaitingCargos();
		//PrintSpecialWaitingcargos();

		// mainInterface->PrintLoadingTrucks(numberofnormalcargos, numberofspecialcargos, numberofvipcargos);
		//mainInterface->PrintEmptytrucks(numberofnormalcargos, numberofspecialcargos, numberofvipcargos);

		// output the simulated trcuks,cargos,...

		key = _getch();
		if (key != 13)                                                           // ASCII for Key_Enter
			break;
		else
		{
			Hour++;
			if (Hour == 24)
			{
				Hour = 0;
				Day++;
			}
			system("cls");                                                       // clears console
		}

	


	}

}