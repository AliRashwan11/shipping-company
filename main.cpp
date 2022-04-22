#include"UI.h"
#include"Company.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include"LinkedList.h"
#include "truck.h"
#include"LinkedPriorityQueue.h"
#include"ReadyEvent.h"
#include"CancelEvent.h"




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

	// ReadyEvent Ready1(1,1, cmptr);

	Cargo inputc0(0);
	inputc0.SetID(0);

	Cargo inputc1(0);
	inputc1.SetID(1);
	
	Cargo inputc2(0);
	inputc2.SetID(2);

	Cargo* p0 = &inputc0;              
	Cargo* p1 = &inputc1;            
	Cargo* p2 = &inputc2;


	//Ready1.Execute(p);
	//Ready1.Execute(p2);
	//Ready1.Execute(p2);
	//Ready1.Execute(p2);

	//Ready1.Execute(p0);
	//Ready1.Execute(p1);;
	//Ready1.Execute(p2);

	//LinkedList NormalWaitingCargos;

	//return 0;



	CancelEvent cancellation(2,2,cmptr,2);

	cancellation.Execute(p2);
	cancellation.Execute(p2);

	//Ready1.Execute(p2);

	maincompany.PrintNormalWaitingCargos();

	return 0;

}