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
		if (isEmpty())
		{
			return false;
		}
		else
		{
			if (Top->GetNext())
			{
				Node<T>* temp = Top;
				Top = Top->GetNext();
			}
			else
				Top = nullptr;

			return true;
			
		}
	}

	void push(T pushedItem)
	{
		
		Node<T> newNode;
		newNode.SetItem(pushedItem);
		Top = &newNode;
		if (isEmpty())
		{
			Top->SetNext(nullptr);
		}
		else
		{
			Top->SetNext(Top);
		}
	}

	T peek()
	{
		if (Top!=nullptr)
		{
			T it = Top->GetItem();
			return it;
		}

	}


	void display()
	{
		if (Top)
			cout << Top->GetItem() << endl;
	}

};

