#pragma once
#include<iostream>
#include "Node.h"
#include "stack.h"
using namespace std;





template <typename T>
class LinkedStack : public stack<T>
{
	Node<T>* Top;

public:

	LinkedStack()
	{
		Top = nullptr;
	}

	bool isEmpty()
	{
		if (Top==nullptr)
			return true;
		return false;
	}
	

	bool pop()
	{
		if (isEmpty() == 1)
		{
			return false;
		}
		else
		{
			Node<T>* Temp = NULL;
			if (Top->GetNext() != nullptr)
			{
				Temp = Top;
				Top = Top->GetNext();
				delete Temp;
			}
			else
			{
				Top = nullptr;
			}
			return true;
			
		}
	}



	void push(T pushedItem)
	{
		
		Node<T>* newNode = new Node<T>;
		newNode->SetItem(pushedItem);
		if (isEmpty())
		{
			newNode->SetNext(nullptr);
			Top = newNode;
		}
		else
		{
			newNode->SetNext(Top);
			Top = newNode;
		}
	}

	T peek()
	{
		if (Top!=nullptr)
		{
			T it = Top->GetItem();
			return it;
		}
		return -1;                                           // works for int data type
	}


	void display()                                              // remove after testing
	{
		if (Top)
			cout << Top->GetItem() << endl;
	}

};

