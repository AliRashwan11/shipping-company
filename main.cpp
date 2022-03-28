#include"UI.h"
#include "LinkedStack.h"




int main()
{

	//UserInterface mainInterface;
	//mainInterface.OutputInterface();


	LinkedStack<int> S;

	S.push(1);
	S.push(2);
	S.push(3);
	S.pop();
	for (int i = 0; i < 3; i++)
	{
		S.display();
	}

	return 0;

}