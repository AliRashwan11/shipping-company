#include"UI.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "truck.h"
#include"LinkedPriorityQueue.h"




int main()
{

	UserInterface mainInterface("input.txt");
	mainInterface.OutputInterface();


	cout << mainInterface.ReadFile(5, 5, "input.txt") << endl;

	

	return 0;


}