#pragma once
#include"Queue.h"
#include"Node.h"


template<typename T>
class LinkedQueue : public Queue<T>
{

	Node<T>* Front;
	Node<T>* Rear;

public:

	LinkedQueue()
	{
		Front = nullptr;
		Rear = nullptr;
	}


	bool isEmpty()
	{
		if (Front)
			return false;
		return true;
	}


	void Enqueue(T item)
	{
		Node<T>* newNode = new Node<T>;
		newNode->SetItem(item);
		if (isEmpty())
		{
			Front = newNode;
			Rear = newNode;
		}
		else
		{
			Node<T>* temp = Rear;
			Rear = newNode;
			Rear->SetNext(temp);
		}
	}

	bool Dequeue()
	{
		if (isEmpty())
		{
			return false;                         // empty queue
		}
		else
		{
			if (Front == Rear)
			{
				delete Front;
				Front = nullptr;
				Rear = nullptr;
			}
			else
			{
				Node<T>* temp = Rear;
				Rear = Rear->GetNext();
				delete temp;
			}
			return true;
		}
	}


	T PeekFront()
	{
		if (isEmpty())
		{
			return -1;                                                    // works for int data type
		}
		else
		{
			return (Front->GetItem());
		}
	}

	T PeekRear()
	{
		if (isEmpty())
		{
			return -1;                                                    // works for int data type
		}
		else
		{
			return (Rear->GetItem());
		}
	}


	~LinkedQueue()
	{

	}
};