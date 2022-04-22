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


	Company maincompany("input.txt");
	Company* cmptr = &maincompany;

	maincompany.ReadFile();

	//maincompany.PrintNormalEmptyTrucks();          // prints speed of normal empty trucks 'n' time .. where n=number of empty trucks
	//maincompany.PrintSpecialEmptyTrucks();
	//maincompany.PrintVIPEmptyTrucks();
	maincompany.PrintEvents();                      // prints hour and day of event


	return 0;

	Cargo c0(0);
	c0.SetID(0);
	Cargo* ptr0 = &c0;

	Cargo c100(0);
	c100.SetID(100);
	Cargo* ptr100 = &c100;

	ReadyEvent event1(1,1,cmptr,ptr0);

	ReadyEvent event100(1, 1, cmptr, ptr100);
	event100.Execute();
	event1.Execute();


	CancelEvent cancel(1,1,cmptr,100);
	cancel.Execute();


	PromotionEvent prom(1,1,cmptr,0,50);
	prom.Execute();

	maincompany.PrintNormalWaitingCargos();
	cout << endl << "..." << endl;
	maincompany.PrintVIPWaitingCargos();


	return 0;

}