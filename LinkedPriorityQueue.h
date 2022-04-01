#pragma once
#include "PriorityQueue.h"


template<typename T>
class LinkedPriorityQueue : public PriorityQueue<T>
{
	Node<T>* Front;
	Node<T>* Rear;

public:

	LinkedPriorityQueue()
	{
		Front = nullptr;
		Rear = nullptr;
	}


	bool isEmpty()
	{
		if (Front != nullptr)
			return false;
		return true;
	}


	void Enqueue(T item , int priority)
	{

		Node<T>* newNode = new Node<T>;
		newNode->SetItem(item);
		newNode->SetNext(nullptr);
		newNode->SetPriority(priority);

		int priorityOfFront =-1;


		if (isEmpty())
		{
			Front = newNode;
			Rear = newNode;
			return;
		}
		else
		{
			priorityOfFront = Front->GetPriority();

			if (Front == Rear)
			{
				if (priorityOfFront >= priority)
				{
					Rear = newNode;
				}
				else
				{
					Front = newNode;
				}

				Front->SetNext(Rear);

			}
			else
			{
				Node<T>* ptr = Front;
				if (ptr->GetPriority() < priority)
				{
					Front = newNode;
					Front->SetNext(ptr);
					return;
				}
				
				while (ptr->GetNext())
				{
					if (ptr->GetNext()->GetPriority() >= priority)
					{
						ptr = ptr->GetNext();
					}
					else
						break;
					
				}

				Node<T>* temp = ptr->GetNext();
				ptr->SetNext(newNode);
				newNode->SetNext(temp);
			
				

			}

		}
	}

	bool Dequeue(T& dequeued)
	{
		if (isEmpty())
		{
			dequeued = -1;
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
			return true;
		}
	}


	~LinkedPriorityQueue()
	{

	}


};
