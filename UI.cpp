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




UserInterface::~UserInterface()
{
	// destrcutor
}