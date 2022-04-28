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

	int GetNumberOfEntries()
	{
		int counter = 0;
		LinkedQueue<T> temp = *this;
		while (!temp.isEmpty())
		{
			temp.Dequeue();
			counter++;
		}
		return counter;
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

	void PrintListSimNormal()
	{

		cout << "[";

		if (isEmpty())
			cout << "]";



		LinkedQueue<Cargo*> temp = *this;
		Cargo* tempt;


		while (!temp.isEmpty())
		{
			temp.Peek(tempt);
			temp.Dequeue();
			cout << tempt->GetID();

			if (!temp.isEmpty())
				cout << ",";
			else
				cout << "]";
		}
		cout << " ";
		return;
	}

	void PrintListSimSpecial()
	{

		cout << "(";

		if (isEmpty())
			cout << ")";



		LinkedQueue<Cargo*> temp = *this;
		Cargo* tempt;


		while (!temp.isEmpty())
		{
			temp.Peek(tempt);
			temp.Dequeue();
			cout << tempt->GetID();

			if (!temp.isEmpty())
				cout << ",";
			else
				cout << ")";
		}
		cout << " ";
		return;
	}

	void PrintListSimVIP()
	{

		cout << "{";

		if (isEmpty())
			cout << "}";



		LinkedQueue<Cargo*> temp = *this;
		Cargo* tempt;


		while (!temp.isEmpty())
		{
			temp.Peek(tempt);
			temp.Dequeue();
			cout << tempt->GetID();

			if (!temp.isEmpty())
				cout << ",";
			else
				cout << "}";
		}
		return;
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
				// delete Front;
				Front = nullptr;
				Rear = nullptr;

			}
			else
			{
				Node<T>* temp = Front;
				Front = Front->GetNext();
				// delete temp;

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
