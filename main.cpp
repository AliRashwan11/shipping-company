#include"UI.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"




int main()
{

	//UserInterface mainInterface;
	//mainInterface.OutputInterface();

	LinkedQueue<int> Q;
	Q.Enqueue(1);
	Q.Enqueue(2);
	Q.Enqueue(3);
	Q.Dequeue();
	Q.Enqueue(30);
	Q.Dequeue();
	cout << Q.PeekFront() << endl << Q.PeekRear() << endl;


	return 0;


}