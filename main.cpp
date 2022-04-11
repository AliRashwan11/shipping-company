#include"UI.h"
#include"Company.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "truck.h"
#include"LinkedPriorityQueue.h"




int main()
{

	//UserInterface mainInterface;
	//mainInterface.OutputInterface();


	Company mainCompany("input.txt");

	mainCompany.PrintEmptyTrucks();

	return 0;


}