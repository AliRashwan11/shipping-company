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
	CapNormalTrucks = 0;
	CapSpecialTrucks = 0;
	CapVIPTrucks = 0;
	TruckLoadingNormals = nullptr;
	TruckLoadingSpecials = nullptr;
	TruckLoadingVIPs = nullptr;
	NumberOfDeliveredCargos = 0;
	
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
	VIPWaitingCargos.Enqueue(newCargo,0);

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
	CapNormalTrucks = NormalTruckCapacity;
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
	CapSpecialTrucks = SpecialTruckCapacity;
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
	CapVIPTrucks = VIPTruckCapacity;
	int CheckUpDurationOfVIPTrucks = ReadSubFile(3, 3);

	for (int i = 0; i < NumberOfVIPTrucks; i++)
	{
		truck* newvtruck = new truck(2);
		newvtruck->SetID(NumberOfSpecialTrucks +i+ NumberOfNormalTrucks);
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
			newCargoAdded->SetPreparationTime((Day*24)+Hour);
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
	mainInterface->PrintListSimVIP(VIPWaitingCargos);
}

void Company::PrintMovingTrucksSim()
{
	int sum = 0;
	LinkedPriorityQueue<truck*> temp = MovingTrucks;
	truck* temptruck = nullptr;

	while (!temp.isEmpty())
	{
		temp.Peek(temptruck);
		temp.Dequeue();
		sum += temptruck->GetCarriedCargos().GetNumberOfEntries();
	}

	mainInterface->PrintMovingTrucksSimIntro(sum);
	mainInterface->PrintMovingTrucksSim(MovingTrucks);
}

void Company::PrintMovingCargosSim()
{
	int n1 = NormalMovingCargos.GetNumberOfEntries();
	int n2 = SpecialMovingCargos.GetNumberOfEntries();
	int n3 = VIPMovingCargos.GetNumberOfEntries();
	int sum = n1 + n2 + n3;


	mainInterface->PrintMovingCargosInfo(sum);
	mainInterface->PrintListSimNormal(NormalMovingCargos);
	mainInterface->PrintListSimSpecial(SpecialMovingCargos);
	mainInterface->PrintListSimVIP(VIPMovingCargos);
	
}

void Company::PrintDeliveredCargosSim()
{
	/*
		int n1 = NormalDeliveredCargos.GetNumberOfEntries();
	int n2 = SpecialDeliveredCargos.GetNumberOfEntries();
	int n3 = VIPDeliveredCargos.GetNumberOfEntries();
	int sum = n1 + n2 + n3;

	mainInterface->PrintDeliveredCargosInfo(sum);
	NormalDeliveredCargos.PrintListSimNormal();
	SpecialDeliveredCargos.PrintListSimSpecial();
	VIPDeliveredCargos.PrintListSimVIP();
	*/
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
	NormalMovingCargos.Enqueue(cgr,0);
}

void Company::AddToSpecialMovingcargos(Cargo* cgr)
{
	SpecialMovingCargos.Enqueue(cgr,0);
}

void Company::AddToVIPMovingcargos(Cargo* cgr)
{
	VIPMovingCargos.Enqueue(cgr,0);
}

Cargo* Company::GetFirstCargoInNormalWaitingCargos()
{
	NormalWaitingCargos.PrintIdList();
	return nullptr;
}


void Company::PrintLoadingTrucks()
{
	mainInterface->PrintLoadingInfo(CurrentlyLoading);
	mainInterface->PrintLoadingTrucksInfo(TruckLoadingNormals,TruckLoadingSpecials,TruckLoadingVIPs);
}


void Company::PrintDeliveredCargos()
{
	mainInterface->PrintDelieverdCargos(NumberOfDeliveredCargos);
	mainInterface->PrintDeliveredCargosUI(DeliveredCargos);
}

void Company::PrintEmptyTrucks()
{
	int NumberOfNormalEmptyTrucks = NormalEmptyTrucks.GetNumberOfEntries();
	int NumberOfSpecialEmptyTrucks = SpecialEmptyTrucks.GetNumberOfEntries();
	int NumberOfVIPEmptyTrucks = VIPEmptyTrucks.GetNumberOfEntries();
	int NumberOfAllEmptyTrucks = NumberOfNormalEmptyTrucks + NumberOfSpecialEmptyTrucks + NumberOfVIPEmptyTrucks;

	LinkedPriorityQueue<truck*> NormalEmptyTruckspriq;
	LinkedPriorityQueue<truck*> SpecialEmptyTruckspriq;
	LinkedPriorityQueue<truck*> VIPEmptyTruckspriq;

	LinkedQueue<truck*> tempnormal = NormalEmptyTrucks;
	LinkedQueue<truck*> tempspecial = SpecialEmptyTrucks;
	LinkedQueue<truck*> tempvip = VIPEmptyTrucks;

	truck* temptruckptr = nullptr;

	while (!tempnormal.isEmpty())
	{
		tempnormal.Peek(temptruckptr);
		tempnormal.Dequeue();
		NormalEmptyTruckspriq.Enqueue(temptruckptr,0);
	}
	while (!tempspecial.isEmpty())
	{
		tempspecial.Peek(temptruckptr);
		tempspecial.Dequeue();
		SpecialEmptyTruckspriq.Enqueue(temptruckptr,0);
	}
	while (!tempvip.isEmpty())
	{
		tempvip.Peek(temptruckptr);
		tempvip.Dequeue();
		VIPEmptyTruckspriq.Enqueue(temptruckptr,0);
	}

	mainInterface->PrintEmptyTrucksInfo(NumberOfAllEmptyTrucks);
	mainInterface->PrintEmptyTrucks(NormalEmptyTruckspriq);
	mainInterface->PrintEmptyTrucks(SpecialEmptyTruckspriq);
	mainInterface->PrintEmptyTrucks(VIPEmptyTruckspriq);

}

void Company::OutputFile()
{
	ofstream OutFile("OutPut.txt");
	int WaitingTime = 0;
	int EV = 0; // EV=Tf-Ti(Start of delivry untill shipping the cargo)
	OutFile << "CDT" << '\t' << "ID" << '\t' << "PT" << '\t' << "WT" << '\t' << "TID" << endl;
	Cargo* TempCargo = nullptr;
	LinkedPriorityQueue<Cargo*> TempDelivery=DeliveredCargos;

	while (!TempDelivery.isEmpty())
	{

		TempDelivery.Peek(TempCargo);
		TempDelivery.Dequeue();

		OutFile << to_string(TempCargo->GetDeliveryTime()) << '\t' << to_string(TempCargo->GetID()) << '\t' << to_string(TempCargo->GetPreparationTime()) << '\t';
		int TempFT = TempCargo->GetFT();
		int Days = 0;
		int Hours=0;
		
		

		int tTemp = TempFT;
		while (TempFT >= 24)
		{
			TempFT -= 24;
			Days++;
		}

		Hours = tTemp - (Days * 24);
		OutFile << to_string(Days) << ":" << to_string(Hours) << '\t' << endl;
		

	}
	OutFile.close();
}


void Company::Simulator()
{
	this->ReadFile();

	

	Cargo* Next_Normal_Cargo = nullptr;
	Cargo* Next_Special_Cargo = nullptr;
	Cargo* Next_VIP_Cargo = nullptr;

	truck* Next_Normal_Truck = nullptr;
	truck* Next_Special_Truck = nullptr;
	truck* Next_VIP_Truck = nullptr;


	//TruckLoadingNormals->SetTypeOfLoadedCargos(0);
	//TruckLoadingVIPs->SetTypeOfLoadedCargos(1);
	//TruckLoadingSpecials->SetTypeOfLoadedCargos(2);


	int Hour = 0;
	int Day = 0;
	int key = 1000;

	int WaitTimeNormal = 0;
	int WaitTimeSpecial = 0;
	int WaitTimeVIP = 0;

	bool ToNextNormalTruck = 1;
	bool ToNextVIPTruck = 1;
	bool ToNextSpecialTruck = 1;

	bool ToChangeTruckLoadingNormals = 1;
	bool ToChangeTruckLoadingSpecials = 1;
	bool ToChangeTruckLoadingVIPs = 1;

	int JourneyTimeNormal = -1;
	int JourneyTimeSpecial = -1;
	int JourneyTimeVIP = -1;

	int MTNormal = -1;
	int MTSpecial = -1;
	int MTVIP = -1;


	int maxd1 = 0;
	int maxd2 = 0;
	int maxd3 = 0;

	Event* nextevent = nullptr;
	Events.Peek(nextevent);

	int CurrTimeInt = -1;
	
	bool juststartednormal = 0;
	bool juststartedvip = 0;
	bool juststartedspecial = 0;

	int GapUntilDequeue = -1;


	while (true)
	{
		CurrTimeInt = (24 * Day) + Hour;


		cout << "Current time as int = " << CurrTimeInt << endl;
		cout << "MAXW = " << maxW << endl;
		cout << "MAXW remaining = " << maxW -WaitTimeNormal << endl << endl;

		

		truck* temptruck = nullptr;

		// set each truck to carry which cargo ..

		if (ToChangeTruckLoadingNormals == 1 && !NormalWaitingCargos.isEmpty())
		{
			
			if (!NormalEmptyTrucks.isEmpty())
			{
				NormalEmptyTrucks.Peek(temptruck);
				NormalEmptyTrucks.Dequeue();
				TruckLoadingNormals = temptruck;
				//cout << "NEW TRUCK LOADING NORMAL  ..  ID = " << TruckLoadingNormals->GetID() << endl << endl;
			}
			else if (!VIPEmptyTrucks.isEmpty())
			{
				VIPEmptyTrucks.Peek(temptruck);
				VIPEmptyTrucks.Dequeue();
				TruckLoadingNormals = temptruck;
				//cout << "NEW TRUCK LOADING NORMAL  ..  ID = " << TruckLoadingNormals->GetID() << endl << endl;

			}
			else
				TruckLoadingNormals = nullptr;

			ToChangeTruckLoadingNormals = 0;
		}
		
		
		if (ToChangeTruckLoadingVIPs == 1 && !VIPWaitingCargos.isEmpty())
		{

			if (!VIPEmptyTrucks.isEmpty())
			{

				VIPEmptyTrucks.Peek(temptruck);
				VIPEmptyTrucks.Dequeue();
				TruckLoadingVIPs = temptruck;
			}
			else if (!NormalEmptyTrucks.isEmpty())
			{
				NormalEmptyTrucks.Peek(temptruck);
				NormalEmptyTrucks.Dequeue();
				TruckLoadingVIPs = temptruck;
			}
			else if (!SpecialEmptyTrucks.isEmpty())
			{

				SpecialEmptyTrucks.Peek(temptruck);
				SpecialEmptyTrucks.Dequeue();
				TruckLoadingVIPs = temptruck;
			}
			else
				TruckLoadingVIPs = nullptr;


			ToChangeTruckLoadingVIPs = 0;

		}
		if (ToChangeTruckLoadingSpecials == 1 && !SpecialWaitingCargos.isEmpty())
		{



			if (!SpecialEmptyTrucks.isEmpty())
			{
				SpecialEmptyTrucks.Peek(temptruck);
				SpecialEmptyTrucks.Dequeue();
				TruckLoadingSpecials = temptruck;
			}
			else
				TruckLoadingSpecials = nullptr;




			ToChangeTruckLoadingSpecials = 0;
		}

		bool NormalIsLoading = 0;
		bool SpecialIsLoading = 0;
		bool VIPIsLoading = 0;

		// enquing moving cargos with the on priority of being closest to deliver a cargo

		if (TruckLoadingNormals)
		{
			NormalIsLoading = 1;
			if (!NormalWaitingCargos.isEmpty())
			{
				while (!NormalWaitingCargos.isEmpty() && TruckLoadingNormals->GetCount()!=CapNormalTrucks)
				{
					Cargo* tempcargo = nullptr;
					tempcargo=NormalWaitingCargos.DeleteFirst();
					tempcargo->SetAV(tempcargo->GetLoadUnloadTime() + (tempcargo->GetDeliveryDistance() / TruckLoadingNormals->GetTruckSpeed()));           // new lineeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
					TruckLoadingNormals->AddToCargos(tempcargo);
					if (tempcargo->GetDeliveryDistance() > maxd1)
						maxd1 = tempcargo->GetDeliveryDistance();
				}
			}
			if (TruckLoadingNormals->GetCount() == CapNormalTrucks && TruckLoadingNormals->GetStartedMovingBool()==0)
			{
				TruckLoadingNormals->SetStartedMovingBool(1);
				TruckLoadingNormals->SetStartTimeOfMoving(CurrTimeInt);
				maxd1 = 0;
				ToChangeTruckLoadingNormals = 1;
				JourneyTimeNormal = TruckLoadingNormals->GetDeliveryTime();
				TruckLoadingNormals->SetDeliveryInterval(JourneyTimeNormal);


				LinkedPriorityQueue<Cargo*> midd = TruckLoadingNormals->GetCarriedCargos();
				LinkedPriorityQueue<Cargo*> midd2;
				int mintime = 1000000;
				int maxtime = -1000000;


				while (!midd.isEmpty())
				{
					Cargo* midcrg = nullptr;
					midd.Peek(midcrg);
					midd.Dequeue();
					int priofarrival = CurrTimeInt + midcrg->GetAV();
					midcrg->SetFT(priofarrival);
					midd2.Enqueue(midcrg, 1000000 - priofarrival);

					if (priofarrival < mintime)
						mintime = priofarrival;
					if (priofarrival-midcrg->GetLoadUnloadTime() > maxtime)
						maxtime = priofarrival-midcrg->GetLoadUnloadTime();
				}

				TruckLoadingNormals->SetBackTripTime(maxtime - CurrTimeInt + 1);
				MovingTrucks.Enqueue(TruckLoadingNormals, 1000000 - mintime);
				TruckLoadingNormals = nullptr;
			}
		}
		if (TruckLoadingSpecials)
		{
			SpecialIsLoading = 1;
			if (!SpecialWaitingCargos.isEmpty())
			{
				while (!SpecialWaitingCargos.isEmpty() && TruckLoadingSpecials->GetCount() != CapSpecialTrucks)
				{
					Cargo* tempcargo = nullptr;
					SpecialWaitingCargos.Peek(tempcargo);
					SpecialWaitingCargos.Dequeue();
					tempcargo->SetAV(tempcargo->GetLoadUnloadTime() + (tempcargo->GetDeliveryDistance() / TruckLoadingSpecials->GetTruckSpeed()));           // new lineeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
					TruckLoadingSpecials->AddToCargos(tempcargo);
					if (tempcargo->GetDeliveryDistance() > maxd2)
						maxd2 = tempcargo->GetDeliveryDistance();
				}
			}
			if (TruckLoadingSpecials->GetCount() == CapSpecialTrucks && TruckLoadingSpecials->GetStartedMovingBool()==0)
			{
				TruckLoadingSpecials->SetStartedMovingBool(1);
				TruckLoadingSpecials->SetStartTimeOfMoving(CurrTimeInt);
				maxd2 = 0;
				ToChangeTruckLoadingSpecials = 1;
				JourneyTimeSpecial = TruckLoadingSpecials->GetDeliveryTime();
				TruckLoadingSpecials->SetDeliveryInterval(JourneyTimeSpecial);

				LinkedPriorityQueue<Cargo*> midd = TruckLoadingSpecials->GetCarriedCargos();
				LinkedPriorityQueue<Cargo*> midd2;
				int mintime = 1000000;
				int maxtime = -1000000;


				while (!midd.isEmpty())
				{
					Cargo* midcrg = nullptr;
					midd.Peek(midcrg);
					midd.Dequeue();
					int priofarrival = CurrTimeInt + midcrg->GetAV();
					midcrg->SetFT(priofarrival);
					midd2.Enqueue(midcrg, 1000000 - priofarrival);

					if (priofarrival < mintime)
						mintime = priofarrival;
					if (priofarrival - midcrg->GetLoadUnloadTime() > maxtime)
						maxtime = priofarrival - midcrg->GetLoadUnloadTime();
				}

				TruckLoadingSpecials->SetBackTripTime(maxtime - CurrTimeInt+1);
				MovingTrucks.Enqueue(TruckLoadingSpecials, 1000000 - mintime);
				TruckLoadingSpecials = nullptr;

			}
		}
		if (TruckLoadingVIPs)
		{
			if (!VIPWaitingCargos.isEmpty())
			{
				while (!VIPWaitingCargos.isEmpty() && TruckLoadingVIPs->GetCount() != CapVIPTrucks)
				{
					Cargo* tempcargo = nullptr;
					VIPWaitingCargos.Peek(tempcargo);
					VIPWaitingCargos.Dequeue();
					tempcargo->SetAV(tempcargo->GetLoadUnloadTime() + (tempcargo->GetDeliveryDistance() / TruckLoadingVIPs->GetTruckSpeed()));           // new lineeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
					TruckLoadingVIPs->AddToCargos(tempcargo);
					if (tempcargo->GetDeliveryDistance() > maxd3)
						maxd3 = tempcargo->GetDeliveryDistance();
				}
			}
			if (TruckLoadingVIPs->GetCount() == CapVIPTrucks && TruckLoadingVIPs->GetStartedMovingBool() == 0)
			{
				TruckLoadingVIPs->SetStartedMovingBool(1);
				TruckLoadingVIPs->SetStartTimeOfMoving(CurrTimeInt);
				maxd3 = 0;
				ToChangeTruckLoadingVIPs = 1;
				JourneyTimeVIP = TruckLoadingVIPs->GetDeliveryTime();
				TruckLoadingVIPs->SetDeliveryInterval(JourneyTimeVIP);           // delivery interval is cargo unloading time + trip time
				

				// enqueue cargos with priority of arriving first

				LinkedPriorityQueue<Cargo*> midd = TruckLoadingVIPs->GetCarriedCargos();
				LinkedPriorityQueue<Cargo*> midd2;
				int mintime = 1000000;
				int maxtime = -1000000;

				while (!midd.isEmpty())
				{
					Cargo* midcrg = nullptr;
					midd.Peek(midcrg);
					midd.Dequeue();
					int priofarrival = CurrTimeInt + midcrg->GetAV();
					midcrg->SetFT(priofarrival);
					midd2.Enqueue(midcrg,1000000-priofarrival);

					if (priofarrival < mintime)
						mintime = priofarrival;
					if (priofarrival - midcrg->GetLoadUnloadTime() > maxtime)
						maxtime = priofarrival - midcrg->GetLoadUnloadTime();
				}

				TruckLoadingVIPs->SetCarriedCargos(midd2);
				TruckLoadingVIPs->SetBackTripTime(maxtime-CurrTimeInt+1);
				MovingTrucks.Enqueue(TruckLoadingVIPs, 1000000 - mintime);
				TruckLoadingVIPs = nullptr;

			}
		}



	                                                                     	// for testing
		/*
		while (!MovingTrucks.isEmpty())
		{
			truck* toprint = nullptr;
			MovingTrucks.Peek(toprint);
			MovingTrucks.Dequeue();
			cout << "ID OF MOVING TRUCK : " << toprint->GetID() << endl;

			LinkedPriorityQueue<Cargo*> tp = toprint->GetCarriedCargos();

			while (!tp.isEmpty())
			{
				Cargo* tpp = nullptr;
				tp.Peek(tpp);
				tp.Dequeue();
				cout << "CARGOS IN IT : " << tpp->GetDeliveryDistance() << endl;
			}
		}
		*/



		

		LinkedPriorityQueue<truck*> temptruckptr = MovingTrucks;

		truck* temptruckk = nullptr;

		LinkedPriorityQueue<Cargo*> tempcargoptr;
		Cargo* tempcargoo = nullptr;





		if (!MovingTrucks.isEmpty())
		{  



			// first check if the closest cargo is yet to be delivered ..

			MovingTrucks.Peek(temptruckk); // first truck in moving trucks

			//cout << temptruckk->GetID() << endl;

			tempcargoptr = temptruckk->GetCarriedCargos(); 
			tempcargoptr.Peek(tempcargoo);                // first cargo in first moving truck
			

			// tempcargoo is first in queue of carried cargos

			int startoftrip = temptruckk->GetStartTimeOfMoving();
			int tripdistance = tempcargoo->GetDeliveryDistance();

			int speedoftruckk = temptruckk->GetTruckSpeed();

			float triptimee = (float)tripdistance / (float)speedoftruckk;
			int triptime = ceil(triptimee);
			int unloadtimeofcargo = tempcargoo->GetLoadUnloadTime();
			int timeoftriparrival = unloadtimeofcargo + triptime + startoftrip;

			//cout <<"UNLOAD TIME OF CARGO : " << unloadtimeofcargo << endl;
			//cout <<"TRIPTIME :" << triptime << endl;
			//cout << "START OF TRIP " << startoftrip << endl;



			 //cout << timeoftriparrival  << "   " << CurrTimeInt << endl << endl;
			 
			
			//cout << "TIME OF ARRIVAL : " << timeoftriparrival << endl;
			//cout << "AV : " << tempcargoo->GetAV() << endl;


			while (timeoftriparrival == CurrTimeInt)                                                         // the cargo should be moved to delivered cargos
			{
				NumberOfDeliveredCargos++;

				int mintime = 1000000;

				// dequeue cargo from truck .. then re enqueue truck with new priority

				MovingTrucks.Dequeue();
				Cargo* deliveredc=temptruckk->DequeueCargo();
				tempcargoptr.Dequeue();
				tempcargoptr.Peek(tempcargoo);
				DeliveredCargos.Enqueue(deliveredc,0);



				LinkedPriorityQueue<Cargo*> newcrgptrpriq=temptruckk->GetCarriedCargos();
				Cargo* newcrgptr = nullptr;
				newcrgptrpriq.Peek(newcrgptr);



				// then re-order trucks in MovingTrucks where first truck contains next dequeue and etc
				if (newcrgptr==nullptr)
				{
					// TO DO .. MOVE TO TRUCKS THAT ARE DELIVERED
					// DONT RE ENQUEUE 


					LinkedPriorityQueue<Cargo*> empty;
					temptruckk->SetCarriedCargos(empty);
					temptruckk->SetBackTripTime(temptruckk->GetBackTripTime()+CurrTimeInt);
					temptruckk->SetNumberOfTripsDone(temptruckk->GetNumberOfTripsDone()+1);
					OnWayBackTrucks.Enqueue(temptruckk, 1000000 - temptruckk->GetBackTripTime());       // enqueue to trucks that are making their way back to company


					cout << "BACK AT : " << temptruckk->GetBackTripTime() << endl;
				}
				else
				{
					// re enqueue to MovingTrucks at the end

					int pri2=newcrgptr->GetFT();
					MovingTrucks.Enqueue(temptruckk,1000000-pri2);
					
				}

				////////////

		
				if (!MovingTrucks.isEmpty())
				{

					MovingTrucks.Peek(temptruckk); // first truck in moving trucks

					//cout << temptruckk->GetID() << endl;

					tempcargoptr = temptruckk->GetCarriedCargos();
					tempcargoptr.Peek(tempcargoo);                // first cargo in first moving truck


					// tempcargoo is first in queue of carried cargos
					if (tempcargoo == nullptr || temptruckk == nullptr)
						break;

					startoftrip = temptruckk->GetStartTimeOfMoving();
					tripdistance = tempcargoo->GetDeliveryDistance();

					speedoftruckk = temptruckk->GetTruckSpeed();

					triptimee = (float)tripdistance / (float)speedoftruckk;
					triptime = ceil(triptimee);
					unloadtimeofcargo = tempcargoo->GetLoadUnloadTime();
					timeoftriparrival = unloadtimeofcargo + triptime + startoftrip;

				}
				else
					break;

			}
		}


		if (!OnWayBackTrucks.isEmpty())            // if there are trucks that are on their way back to company
		{
			truck* temptruck = nullptr;
			OnWayBackTrucks.Peek(temptruck);
			int temptime = temptruck->GetBackTripTime();

			while (temptime == CurrTimeInt)
			{
				OnWayBackTrucks.Dequeue();

				if (temptruck->GetTruckType() == 0)
				{
					if (temptruck->GetNumberOfTripsDone() == NumberOfJourneysBeforeCheckup)       // enqueue to incheckup trucks instead of normal waiting
					{

					}
					else
						NormalEmptyTrucks.Enqueue(temptruck);
				}
				else if(temptruck->GetTruckType() ==1)
					SpecialEmptyTrucks.Enqueue(temptruck);
				else
					VIPEmptyTrucks.Enqueue(temptruck);

				if (!OnWayBackTrucks.isEmpty())
				{
					OnWayBackTrucks.Peek(temptruck);
					temptime = temptruck->GetBackTripTime();
				}
				else
					break;
				
			}
		}




		/*

		
		while (!temptruckptr.isEmpty())                                          // as long as there is atleast a truck moving .. check if this truck has done all deliveries
		{

			temptruckptr.Peek(temptruckk);
			temptruckptr.Dequeue();
			int startofmoving = temptruckk->GetStartTimeOfMoving();

			int JT = temptruckk->GetDeliveryInterval();                  // journey time

			if (temptruckk->GetTypeOfLoadedCargos() == 0) // normal cargos
			{
				if (CurrTimeInt == JT + startofmoving)            // a normal truck has delivered all its cargos
				{
					ToChangeTruckLoadingNormals = 1;
					MovingTrucks.Dequeue();
				}
			}

			if (temptruckk->GetTypeOfLoadedCargos() == 1) // Special cargos
			{
				if (CurrTimeInt == JT + startofmoving)            // a special truck has delivered all its cargos
				{
					ToChangeTruckLoadingSpecials = 1;

					MovingTrucks.Dequeue();

				}
			}

			if (temptruckk->GetTypeOfLoadedCargos() == 2) // VIP cargos
			{
				if (CurrTimeInt == JT + startofmoving)            // a vip truck has delivered all its cargos
				{
					ToChangeTruckLoadingVIPs = 1;

					MovingTrucks.Dequeue();

				}
			}


		}

		
		*/


			//hdisdhsdjgsiydgsigdiygdidyia

	

		/*
		
		if (!NormalEmptyTrucks.isEmpty() && ToNextNormalTruck==1)
		{
			NormalEmptyTrucks.Peek(Next_Normal_Truck);
			NormalEmptyTrucks.Dequeue();
			ToNextNormalTruck = 0;
		}
		if (!SpecialEmptyTrucks.isEmpty() && ToNextSpecialTruck == 1)
		{
			SpecialEmptyTrucks.Peek(Next_Special_Truck);
			SpecialEmptyTrucks.Dequeue();
			ToNextSpecialTruck = 0;
		}
		if (!VIPEmptyTrucks.isEmpty() && ToNextVIPTruck == 1)
		{
			VIPEmptyTrucks.Peek(Next_VIP_Truck);
			VIPEmptyTrucks.Dequeue();
			ToNextVIPTruck = 0;
		}


		* 
		* if (Next_Normal_Truck)
		{
			Cargo* tempC = nullptr;
			if (NormalWaitingCargos.GetNumberOfCargos() == CapNormalTrucks)
			{
				// assign cargos to truck and make truck moving
				for (int i = 0; i < CapNormalTrucks; i++)
				{
					tempC = NormalWaitingCargos.DeleteFirst();
					Next_Normal_Truck->AddToCargos(tempC);
				}
				WaitTimeNormal = 0;
				ToNextNormalTruck = 1;

			}
			else if (!NormalWaitingCargos.isEmpty() && WaitTimeNormal == maxW)
			{
				// assign cargos to truck and make truck moving
				int reps = NormalWaitingCargos.GetNumberOfCargos(); 
				for (int i = 0; i < reps ; i++)
				{
					tempC = NormalWaitingCargos.DeleteFirst();
					Next_Normal_Truck->AddToCargos(tempC);
				}
				WaitTimeNormal = 0;
				ToNextNormalTruck = 0;

			}
			else if (!VIPWaitingCargos.isEmpty() && WaitTimeVIP == maxW && !Next_VIP_Truck)
			{
				int reps = VIPWaitingCargos.GetNumberOfEntries();
				for (int i = 0; i < reps ; i++)
				{
					VIPWaitingCargos.Peek(tempC);
					VIPWaitingCargos.Dequeue();
					Next_Normal_Truck->AddToCargos(tempC);
				}
				WaitTimeVIP = 0;
				ToNextNormalTruck = 0;

			}
			else if (!NormalWaitingCargos.isEmpty())
			{
				WaitTimeNormal++;

			}
		}

		if (Next_Special_Truck)
		{
			Cargo* tempC = nullptr;
			if (SpecialWaitingCargos.GetNumberOfEntries() == CapSpecialTrucks)
			{
				// assign cargos to truck and make truck moving
				for (int i = 0; i < CapSpecialTrucks; i++)
				{
					SpecialWaitingCargos.Peek(tempC);
					SpecialWaitingCargos.Dequeue();
					Next_Special_Truck->AddToCargos(tempC);
				}
				WaitTimeSpecial = 0;
				ToNextSpecialTruck = 1;
			}
			else if (!SpecialWaitingCargos.isEmpty() && WaitTimeSpecial == maxW)
			{
				// assign cargos to truck and make truck moving
				int reps = SpecialWaitingCargos.GetNumberOfEntries();
				for (int i = 0; i < reps ; i++)
				{
					SpecialWaitingCargos.Peek(tempC);
					SpecialWaitingCargos.Dequeue();
					Next_Special_Truck->AddToCargos(tempC);
				}
				WaitTimeSpecial = 0;
				ToNextSpecialTruck = 1;

			}
			else if (!VIPWaitingCargos.isEmpty() && WaitTimeVIP == maxW && !Next_VIP_Truck)
			{
				int reps = VIPWaitingCargos.GetNumberOfEntries();

				for (int i = 0; i < reps ; i++)
				{
					VIPWaitingCargos.Peek(tempC);
					VIPWaitingCargos.Dequeue();
					Next_Normal_Truck->AddToCargos(tempC);
				}
				WaitTimeVIP = 0;
				ToNextSpecialTruck = 1;

			}
			else if(!SpecialWaitingCargos.isEmpty())
				WaitTimeSpecial++;
		}

		if (Next_VIP_Truck)
		{
			Cargo* tempC = nullptr;
			if (VIPWaitingCargos.GetNumberOfEntries() == CapVIPTrucks)
			{
				// assign cargos to truck and make truck moving
				for (int i = 0; i < CapVIPTrucks; i++)
				{
					VIPWaitingCargos.Peek(tempC);
					VIPWaitingCargos.Dequeue();
					Next_VIP_Truck->AddToCargos(tempC);
				}
				WaitTimeVIP = 0;
				ToNextVIPTruck = 1;
			}
			else if (!VIPWaitingCargos.isEmpty() && WaitTimeVIP == maxW)
			{
				// assign cargos to truck and make truck moving
				int reps = VIPWaitingCargos.GetNumberOfEntries();
				for (int i = 0; i < reps ; i++)
				{
					VIPWaitingCargos.Peek(tempC);
					VIPWaitingCargos.Dequeue();
					Next_VIP_Truck->AddToCargos(tempC);
				}
				WaitTimeVIP = 0;
				ToNextVIPTruck = 1;

			}
			else if (!NormalWaitingCargos.isEmpty() && WaitTimeNormal== maxW && !Next_Normal_Truck)
			{
				int reps = NormalWaitingCargos.GetNumberOfCargos();
				for (int i = 0; i < reps ; i++)
				{
					tempC = NormalWaitingCargos.DeleteFirst();
					Next_Normal_Truck->AddToCargos(tempC);
				}
				WaitTimeNormal = 0;
				ToNextVIPTruck = 1;

			}
			else if (!VIPWaitingCargos.isEmpty())
				WaitTimeVIP++;
		}


		*/



		if (nextevent->GetDay() == Day && nextevent->GetHour() == Hour)
		{


			nextevent->Execute();

			Events.Dequeue();
			if (!Events.isEmpty())
			{
				Events.Peek(nextevent);
				while (nextevent->GetHour() == Hour && nextevent->GetDay() == Day)  // to execute multiple events at same time
				{
					
					nextevent->Execute();
					Events.Dequeue();
					Events.Peek(nextevent);
				}
			}
		}


		mainInterface->PrintStartSim();
		mainInterface->PrintHourAdvance(Day, Hour);
		PrintWaitingCargosSim();                                       // 1st line
		mainInterface->DrawLines();
		//PrintMovingTrucksSim();

		// now for drawing loading trucks ..

		int numLoadingTrucks = (int)NormalIsLoading + (int)SpecialIsLoading + (int)VIPIsLoading;
		CurrentlyLoading = numLoadingTrucks;
		PrintLoadingTrucks();                                       // 2nd line
		mainInterface->DrawLines();
		PrintEmptyTrucks();                                        // 3rd line
		mainInterface->DrawLines();
		PrintMovingTrucksSim();
		mainInterface->DrawLines();
		PrintDeliveredCargos();
		mainInterface->DrawLines();


		 OutputFile();

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
		
		if (!NormalWaitingCargos.isEmpty())
		{
			Cargo* tempCargo = NormalWaitingCargos.DeleteFirst();
			//cout << tempCargo->GetID() << endl;
			AddToNormalMovingcargos(tempCargo);
		}
		

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
				//NormalDeliveredCargos.Enqueue(crg);
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
				//SpecialDeliveredCargos.Enqueue(crg);
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
				//VIPDeliveredCargos.Enqueue(crg);
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
				while (nextevent->GetHour() == Hour && nextevent->GetDay() == Day)  // to execute multiple events at same time
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