#pragma once
#include "PriorityQueue.h"

//class Cargo;


template<typename T>
class LinkedPriorityQueue : public PriorityQueue<T>
{
	Node<T>* Front;
	Node<T>* Rear;
	int count;

public:

	LinkedPriorityQueue()
	{
		Front = nullptr;
		Rear = nullptr;
		count = 0;
	}


	bool isEmpty()
	{
		if (Front != nullptr)
			return false;
		return true;
	}


	void Enqueue(T item , int priority)
	{
		count++;
		Node<T>* Anewnode = new Node<T>;
		Anewnode->SetItem(item);
		Anewnode->SetNext(nullptr);
		Anewnode->SetPriority(priority);

		int priorityOfFront =-1;

		if (isEmpty())
		{

			Rear = Anewnode;
			Front = Anewnode;
			return;
		}
		else
		{
			priorityOfFront = Front->GetPriority();

			if (Front == Rear)
			{
				if (priorityOfFront >= priority)
				{
					Rear = Anewnode;
				}
				else
				{
					Front = Anewnode;
				}

				Front->SetNext(Rear);

			}
			else
			{
				Node<T>* ptr = Front;
				if (ptr->GetPriority() < priority)
				{
					Front = Anewnode;
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
				ptr->SetNext(Anewnode);
				Anewnode->SetNext(temp);
			
				

			}

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

			if (count==1)
			{

				//delete Front;
				Front = nullptr;
				Rear = nullptr;

			}
			else
			{
				Node<T>* temp = Front;
				Front = Front->GetNext();
				//delete temp;
			}
			count--;
			return true;
		}
	}
	
	int GetNumberOfEntries()
	{
		int counter = 0;
		LinkedPriorityQueue<T> temp = *this;
		while (!temp.isEmpty())
		{
			temp.Dequeue();
			counter++;
		}
		return counter;
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
