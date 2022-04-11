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
		if (Front !=nullptr)
			return false;
		return true;
	}


	void Enqueue(T item)
	{
		Node<T>* newNode = new Node<T>;
		newNode->SetItem(item);
		newNode->SetNext(nullptr);
		if (isEmpty())
		{
			Front = newNode;
			Rear = newNode;
		}
		else
		{
			if (Front == Rear)
			{
				Rear = newNode;
				Front->SetNext(Rear);
			}
			else
			{
				Rear->SetNext(newNode);
				Rear = newNode;
			
			}
			
		}
	}

	bool Dequeue(T& dequeued)
	{
		if (isEmpty())
		{
			// dequeued = -1;
			return false;                         // empty queue
		}
		else
		{
			dequeued = Front->GetItem();
			if (Front == Rear)
			{
				delete Front;
				Front = nullptr;
				Rear = nullptr;
			}
			else
			{
				Node<T>* temp = Front;
				Front = Front->GetNext();
				delete temp;
			}
			return true;
		}
	}


	bool Peek(T& peeked)
	{
		if (isEmpty())
		{
			return false;                                                    // works for int data type
		}
		else
		{
			peeked = Front->GetItem();
			return true ;
		}
	}




	~LinkedQueue()
	{

	}
};