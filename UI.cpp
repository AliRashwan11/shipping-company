#include "UI.h"


UserInterface::UserInterface()
{
	Day = 0;
	Hour = 0;
	Mode = 0;
	cout << "Choose Mode .. Interactive (1) - Step-By-Step (2) - Silent (3) " << endl;
	int mode = 0;
	cin >> mode;
	while (mode != 1 && mode != 2 && mode != 3)
	{
		cout << "Invalid Entry !! Please choose from 1-2-3 ...";
		cin >> mode;
	}
	if (mode == 1)
	{
		Mode = 1;                                                          // initializes Mode data member to 1
	}
	else if (mode == 2)
	{
		cout << "Step-By-Step mode activated(still not implemented) .."; // remove line after implementation
		Mode = 2;                                                        // initializes Mode data member to 2

	}
	else
	{
		cout << "Silent mode activated ( still not implemented ) .."; // remove line after implementation
		Mode = 3;                                                     // initializes Mode data member to 3

	}

	system("cls");
}


void UserInterface::PrintHourAdvance(int Day,int Hour)
{
	cout << "Current Time (Day:Hour) : " << Day << ":" << Hour << endl << endl;

}

void UserInterface::PrintStartSim()
{
	cout << "Press ENTER to advance an hour .. Press any other key to stop simulation " << endl;
}


void UserInterface::PrintNormalWaitingCargos(int n,int* arr)
{
	cout << "[";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
		if (i != n - 1)
			cout << ",";
	}
	cout << "]";
}

void UserInterface::PrintSpecialWaitingCargos(int n, int* arr)
{
	cout << "(";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
		if (i != n - 1)
			cout << ",";
	}
	cout << ")";
}

void UserInterface::PrintVIPWaitingCargos(int n, int* arr)
{

	cout << "{";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
		if (i != n - 1)
			cout << ",";
	}
	cout << "}";
}


void UserInterface::PrintWaitingCargos(int normal,int* arr1,int special,int*arr2,int vip,int* arr3)
{
	int sum = normal + special + vip;
	cout << sum << " Waiting Cargos:";

	cout << " ";
	PrintNormalWaitingCargos(normal,arr1);
	cout << " ";
	PrintSpecialWaitingCargos(special,arr2);
	cout << " ";
	PrintVIPWaitingCargos(vip,arr3);

	return;

	
}


void UserInterface::DemoPrintLoadingTrucks()
{
	cout << "0 Loading Trucks: " ;
}

void UserInterface::DemoPrintMovingcargos()
{

}

void UserInterface::DemoPrintDeliveredCargos()
{

}

void UserInterface::DemoPrintInCheckupTrucks()
{
	cout << "0 In-Checkup Trucks:";
}

void UserInterface::PrintWaitingCargosInfo(int n)
{
	cout << n << " Waiting cargos:";
	return;
}

void UserInterface::PrintDeliveredCargosInfo(int n)
{
	cout << n << " Delivered cargos:";
	return;
}

void UserInterface::PrintMovingCargosInfo(int n)
{
	cout << n << " Moving cargos:";
	return;
}

void UserInterface::PrintDeliveredCargosUI(LinkedPriorityQueue<Cargo*> in)
{
	LinkedPriorityQueue<Cargo*> tempq = in;
	Cargo* tempcargo = nullptr;
	int type = -1;

	while (!tempq.isEmpty())
	{
		tempq.Peek(tempcargo);
		tempq.Dequeue();
		
		type = tempcargo->GetCargoType();
		if (type == 0) // normal
		{
			cout << "[" << tempcargo->GetID() << "] ";
		}
		else if (type == 1) // special
		{
			cout << "(" << tempcargo->GetID() << ") ";

		}
		else // VIP
		{
			cout << "{" << tempcargo->GetID() << "} ";

		}
	}
	
}

void UserInterface::PrintEmptyTrucksInfo(int a)
{
	cout << a << " Empty Trucks: ";
}

void UserInterface::PrintEmptyTrucks(LinkedPriorityQueue<truck*> in)
{
	int type = -1;
	LinkedPriorityQueue<truck*> temp = in;
	truck* temptruck = nullptr;

	while (!temp.isEmpty())
	{
		temp.Peek(temptruck);
		temp.Dequeue();

		type = temptruck->GetTruckType();
		if (type == 0) // normal
		{
			cout << "[" << temptruck->GetID() << "] ";
		}
		else if (type == 1) // special
		{
			cout << "(" << temptruck->GetID() << ") ";

		}
		else // vip
		{
			cout << "{" << temptruck->GetID() << "} ";

		}
	}
}


void UserInterface::DrawLines()
{
	cout <<endl<<"------------------------------------------------------------------------"<<endl;
}
void UserInterface::DemoPrintEmptyTrucks(int normal,int special,int vip)
{
	int sum = normal + special + vip;
	cout << sum << " Empty Trucks: ";
	for (int i = 0; i < normal; i++)
	{
		cout << "[" << i+1 << "],";
	}
	for (int i = 0; i < special; i++)
	{
		cout << "(" << i + normal+1 << "),";
	}
	for (int i = 0; i < vip; i++)
	{
		cout << "{" << i + special+vip+2 << "}";
		if (i != vip - 1)
			cout << ",";

	}
}

void UserInterface::OutputInterface()
{
	
	int key = 10000;

	if (Mode == 1)
	{
		system("cls");

		bool entry = 1;
		while (entry == 1)
		{
			cout << "Press ENTER to advance an hour .. Press any other key to stop simulation " << endl;
			cout << "Current Time (Day:Hour) : " << Day << ":" << Hour << endl;

			// output the simulated trcuks,cargos,...

			key = _getch();
			if (key != 13)                                                           // ASCII for Key_Enter
				entry = 0;
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
	else if (Mode == 2)
	{
		system("cls");
		for (;;)
		{
			cout << "Current Time (Day:Hour) : " << Day << ":" << Hour << endl;

			// output the simulated trcuks,cargos,...

			Hour++;
			if (Hour == 24)
			{
				Hour = 0;
				Day++;
			}

			Sleep(1000);
			system("cls");
		}

	}
	else
	{

		// silent mode implementation
	}


}

int UserInterface::GetDay()
{
	return Day;
}

int UserInterface::GetHour()
{
	return Hour;
}

void UserInterface::PrintListSimNormal(LinkedPriorityQueue<Cargo*> in)
{

	cout << "[";

	if (in.isEmpty())
		cout << "]";

	Cargo* tempt = nullptr;


	LinkedPriorityQueue<Cargo*> temp;
	temp = in;




	while (!temp.isEmpty())
	{
		temp.Peek(tempt);
		temp.Dequeue();
		cout << tempt->GetID();

		if (!temp.isEmpty())
			cout << ",";
		else
			cout << "]";
	}
	cout << ",";
	return;
}

void UserInterface::PrintListSimSpecial(LinkedPriorityQueue<Cargo*> in)
{

	cout << "(";

	if (in.isEmpty())
		cout << ")";



	LinkedPriorityQueue<Cargo*> temp;
	temp = in;
	Cargo* tempt;


	while (!temp.isEmpty())
	{
		temp.Peek(tempt);
		temp.Dequeue();
		cout << tempt->GetID();

		if (!temp.isEmpty())
			cout << ",";
		else
			cout << ")";
	}
	cout << ",";

	return;
}


void UserInterface::PrintListSimVIP(LinkedPriorityQueue<Cargo*> in)
{
	cout << "{";

	if (in.isEmpty())
		cout << "}";



	LinkedPriorityQueue<Cargo*> temp = in;
	Cargo* tempt;


	while (!temp.isEmpty())
	{

		temp.Peek(tempt);
		temp.Dequeue();

		cout << tempt->GetID();


		if (!temp.isEmpty())
			cout << ",";
		else
			cout << "}";
	}


	return;
}


void UserInterface::PrintLoadingInfo(int a)
{
	cout << a <<" Loading Trucks: ";
}

void UserInterface::PrintLoadingTrucksInfo(truck* norm,truck* spec,truck* vip)
{


	if (norm)
	{
		PrintNormalLoading(norm);
	}

	 if (spec)
	{
		PrintSpecialLoading(spec);

	}
	
	if (vip)
	{
		PrintVIPLoading(vip);
	}
	
	
}

void UserInterface::PrintNormalLoading(truck* in)
{
	Cargo* tempc = nullptr;
	LinkedPriorityQueue<Cargo*> temp = in->GetCarriedCargos();
	cout <<in->GetID() << "[";
	while (!temp.isEmpty())
	{
		temp.Peek(tempc);
		temp.Dequeue();
		cout << tempc->GetID();
		if (!temp.isEmpty())
			cout << ",";
	}
	cout << "] ";
	
}

void UserInterface::PrintInCheckupsIntro(int a)
{
	cout << a << " In-Checkup Trucks: ";
}


void UserInterface::PrintVIPLoading(truck* in)
{
	Cargo* tempv = nullptr;
	LinkedPriorityQueue<Cargo*> temp = in->GetCarriedCargos();
	cout << in->GetID() << "{";
	while (!temp.isEmpty())
	{
		temp.Peek(tempv);
		temp.Dequeue();
		cout << tempv->GetID();
		if (!temp.isEmpty())
			cout << ",";
	}
	cout << "} ";

}
void UserInterface::PrintSpecialLoading(truck* in)
{
	Cargo* temps = nullptr;
	LinkedPriorityQueue<Cargo*> temp = in->GetCarriedCargos();
	cout << in->GetID() << "(";
	while (!temp.isEmpty())
	{
		temp.Peek(temps);
		temp.Dequeue();
		cout << temps->GetID();
		if (!temp.isEmpty())
			cout << ",";
	}
	cout << ") ";
}

void UserInterface::PrintMovingTrucksSimIntro(int a)
{
	cout << a << " Moving Cargos: ";
}

void UserInterface::PrintDelieverdCargos(int a)
{
	cout << a << " Delivered Cargos: ";
}

void UserInterface::PrintMovingTrucksSim(LinkedPriorityQueue<truck*> q)
{
	LinkedPriorityQueue<truck*> temp = q;
	truck* tr = nullptr;
	Cargo* cr = nullptr;
	int type = -1;
	

	while (!temp.isEmpty())
	{
		temp.Peek(tr);
		temp.Dequeue();
		cout << tr->GetID();
		type = tr->GetTypeOfLoadedCargos();
		LinkedPriorityQueue<Cargo*> tempcr= tr->GetCarriedCargos();
		if (type == 0)   // normal
		{
			cout << "[";
			while (!tempcr.isEmpty())
			{
				tempcr.Peek(cr);
				tempcr.Dequeue();
				cout << cr->GetID();
				if (!tempcr.isEmpty())
					cout << ",";
				else
					cout << "]";
			}
			cout << " ";
		}
		else if (type == 1)   // special
		{
			cout << "(";
			while (!tempcr.isEmpty())
			{
				tempcr.Peek(cr);
				tempcr.Dequeue();
				cout << cr->GetID();
				if (!tempcr.isEmpty())
					cout << ",";
				else
					cout << ")";
			}
			cout << " ";
		}
		else    // vip
		{
			cout << "{";
			while (!tempcr.isEmpty())
			{
				tempcr.Peek(cr);
				tempcr.Dequeue();
				cout << cr->GetID();
				if (!tempcr.isEmpty())
					cout << ",";
				else
					cout << "}";
			}
			cout << " ";
		}
	}
}

UserInterface::~UserInterface()
{
	// destrcutor
}