#pragma once
#include"List.h"

class LinkedList : public List<Cargo*>
{
	Node<Cargo*>* Head;

public:

	LinkedList()
	{
		Head = nullptr;
	}

	LinkedList(LinkedList& copy)
	{
		Head = copy.Head;
	}

	~LinkedList()
	{
		DeleteAll();
	}

	void PrintList()	
	{
		Node<Cargo*>* p = Head;
		
		while (p)
		{
			cout << "[ " << p->GetItem()->GetID() << " ]";
			cout << "--->";
			p = p->GetNext();
		}
		return;
	}

	void InsertBeg(Cargo*& item)
	{
		Node<Cargo*>* R = new Node<Cargo*>(item);
		R->SetNext(Head);
		Head = R;
	}

	Cargo* FindCargo(int key)
	{
		Cargo* ret = nullptr;
		Node<Cargo*>* ptr = Head;
		while (ptr)
		{
			if (ptr->GetItem()->GetID() == key)
			{
				ret = ptr->GetItem();
				break;
			}
			ptr = ptr->GetNext();
		}
		return ret;
	}

	void InsertEnd(Cargo*& data)
	{
		Node<Cargo*>* R = Head;
		Node<Cargo*>* obj = new Node<Cargo*>;
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

	bool Find(int key)
	{
		Node<Cargo*>* ptr = Head;
		while (ptr)
		{
			if (ptr->GetItem()->GetID() == key)
			{
				return true;
			}
			ptr = ptr->GetNext();
		}
		return false;

	}


	bool DeleteNode(int ID)
	{
		Node<Cargo*>* ptr = Head;
		Node<Cargo*>* temp = NULL;
		if (Head)
		{
			if (Head->GetItem()->GetID() == ID)
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
				if (ptr->GetNext()->GetItem()->GetID() == ID)
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
		Node<Cargo*>* P = Head;
		while (Head)
		{
			P = Head->GetNext();
			delete Head;
			Head = P;
		}
	}

};

