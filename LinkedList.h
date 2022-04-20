#pragma once
#include"List.h"

template <typename T>
class LinkedList : public List<T>
{
	Node<T>* Head;

public:

	LinkedList()
	{
		Head = nullptr;
	}

	~LinkedList()
	{
		DeleteAll();
	}

	void PrintList()	
	{
		Node<T>* p = Head;

		while (p)
		{
			cout << "[ " << p->GetItem() << " ]";
			cout << "--->";
			p = p->GetNext();
		}
	}

	void InsertBeg(const T& data)
	{
		Node<T>* R = new Node<T>(data);
		R->SetNext(Head);
		Head = R;

	}

	void InsertEnd(const T& data)
	{
		Node<T>* R = Head;
		Node<T>* obj = new Node<T>;
		obj->SetItem(data);
		obj->SetNext(NULL);
		if (Head == NULL)
		{
			Head = obj;
		}
		else
		{
			while (R->GetNext())
			{
				R = R->GetNext();
			}
			R->SetNext(obj);
		}

	}

	bool Find(T Key)
	{
		Node<T>* ptr = Head;
		while (ptr)
		{
			if (ptr->GetItem() == Key)
			{
				return true;
			}
			ptr = ptr->GetNext();
		}
		return false;
	}

	bool DeleteNode(const T& value)
	{
		Node<T>* ptr = Head;
		Node<T>* temp = NULL;
		if (Head)
		{
			if (Head->GetItem() == value)
			{
				temp = Head;
				if (Head->GetNext())
				{
					Head = Head->GetNext();
				}
				else
				{
					Head = NULL;
				}
				delete temp;
				temp = NULL;
				return true;
			}
			while (ptr->GetNext())
			{
				if (ptr->GetNext()->GetItem() == value)
				{
					temp = ptr->GetNext();
					ptr->SetNext(ptr->GetNext()->GetNext());
					delete temp;
					temp = NULL;
					return true;
				}
				ptr = ptr->GetNext();
			}

		}

		return false;
	}


	void DeleteAll()
	{
		Node<T>* P = Head;
		while (Head)
		{
			P = Head->GetNext();
			delete Head;
			Head = P;
		}
	}

};

void LinkedList<Cargo*>::PrintList()
{
	Node<Cargo*>* p = Head;

	while (p)
	{
		cout << "[ " << p->GetItem()->GetCost() << " ]";
		cout << "--->";
		p = p->GetNext();
	}
}
