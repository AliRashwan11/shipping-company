#include"UI.h"
#include"Company.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include"LinkedList.h"
#include "truck.h"
#include"LinkedPriorityQueue.h"
#include"ReadyEvent.h"
#include"CancelEvent.h"
#include"PromotionEvent.h"




int main()
{

	// UserInterface mainInterface;
	 // mainInterface.OutputInterface();

/*

	LinkedQueue<Cargo*> cargos;
	Cargo cargo1(0);
	Cargo cargo2(0);
	Cargo cargo3(2);

	Cargo* pc1 = &cargo1;
	Cargo* pc2 = &cargo2;
	Cargo* pc3 = &cargo3;

	cargos.Enqueue(pc1);
	cargos.Enqueue(pc2);
	cargos.Enqueue(pc3);

	int outted = -1;
	Cargo* outtedCargo;

	while (!cargos.isEmpty())
	{
		cargos.Dequeue(outtedCargo);
		outted = outtedCargo->GetCargoType();
		cout << outted << endl;
	}

	return 0;

*/
	// ***********************************************************************************************
	
	// main test //
	UserInterface mainUI;
	UserInterface* ptrToMainUI = &mainUI;
	Company maincompany("input.txt", ptrToMainUI);
	Company* cmptr = &maincompany;

	Cargo car(0);
	Cargo car2(1);
	Cargo car3(2);
	Cargo* cptr = &car;
	Cargo* cptr2 = &car2;
	Cargo* cptr3 = &car3;

	ReadyEvent event(1,1,cmptr,cptr);
	ReadyEvent event2(1,1,cmptr,cptr2);
	ReadyEvent event3(1,1,cmptr,cptr3);
	event.Execute();
	event.Execute();
	event2.Execute();
	event3.Execute();
	event.Execute();
	event3.Execute();

	//maincompany.ReadFile();

	//maincompany.PrintNormalEmptyTrucks();          // prints speed of normal empty trucks 'n' time .. where n=number of empty trucks
	//maincompany.PrintSpecialEmptyTrucks();
	//maincompany.PrintVIPEmptyTrucks();
	// maincompany.PrintEvents();                      // prints hour and day of event


	maincompany.SimpleSimulator();


	return 0;

}