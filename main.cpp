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

	ReadyEvent Ready1(1,1, cmptr);

	Cargo inputc(0);
	inputc.SetID(1);

	Cargo inputc2(0);
	inputc2.SetID(0);

	Cargo* p = &inputc;               // id = 1
	Cargo* p2 = &inputc2;             // id = 0


	//Ready1.Execute(p);
	//Ready1.Execute(p2);
	//Ready1.Execute(p2);
	//Ready1.Execute(p2);
	Ready1.Execute(p);
	Ready1.Execute(p);;
	Ready1.Execute(p2);
	Ready1.Execute(p);

	//LinkedList NormalWaitingCargos;

	//return 0;



	CancelEvent cancellation(2,2,cmptr,1);

	cancellation.Execute(p2);
	//cancellation.Execute(p);

	maincompany.PrintNormalWaitingCargos();

	return 0;



	LinkedList maincargos;

	Cargo cargo1;
	Cargo cargo2;
	Cargo cargo3;
	Cargo cargo4;
	Cargo cargo5;
	cargo1.SetID(1);
	cargo2.SetID(2);
	cargo3.SetID(3);
	cargo4.SetID(4);
	cargo5.SetID(5);

	Cargo* pt1 = &cargo1;
	Cargo* pt2 = &cargo2;
	Cargo* pt3 = &cargo3;
	Cargo* pt4 = &cargo4;
	Cargo* pt5 = &cargo5;

	maincargos.InsertEnd(pt1);
	maincargos.InsertEnd(pt2);
	maincargos.InsertEnd(pt3);
	maincargos.InsertEnd(pt4);
	maincargos.InsertEnd(pt5);

	bool found=maincargos.Find(3);

	maincargos.PrintList();

	cout << endl;

	cout << endl << found << endl << endl;

	//maincargos.DeleteNode(pt3);
	//maincargos.DeleteNode(pt5);
	//maincargos.DeleteNode(pt1);

	maincargos.PrintList();


	return 0;


}