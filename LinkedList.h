#pragma once
#include"List.h"

class LinkedList : public List<Cargo*>
{
	Node<Cargo*>* Head;
	int Cargos;

public:

	LinkedList()
	{
		Head = nullptr;
		Cargos = 0;
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
		
		if (!p)
			return;
		while (p)
		{
			cout << "[ " << p->GetItem()->GetID() << " ]";
			cout << "--->";
			p = p->GetNext();
		}
		return;
	}

	void PrintListSimNormal()
	{

		Node<Cargo*>* p = Head;

		cout << "[";
		
		if (!p)
			cout << "]";
	


		while (p)
		{
			cout << p->GetItem()->GetID();
			if (p->GetNext())
				cout << ",";
			else
				cout << "]";
			p = p->GetNext();
		}

		cout << " ";
		return;
	}

	void PrintListSimSpecial()
	{
		Node<Cargo*>* p = Head;

		if (!p)
			return;
		while (p)
		{
			cout << "( " << p->GetItem()->GetID();
			if (p->GetNext())
				cout << ",";
			else
				cout << ")";
			p = p->GetNext();
		}
		cout << " ";

		return;
	}

	void PrintListSimVIP()
	{
		Node<Cargo*>* p = Head;

		if (!p)
			return;
		while (p)
		{
			cout << "( " << p->GetItem()->GetID();
			if (p->GetNext())
				cout << ",";
			else
				cout << ")";
			p = p->GetNext();
		}
		cout << endl;
		return;
	}

	int GetNumberOfCargos()
	{
		return Cargos;
	}

	void InsertBeg(Cargo*& item)
	{
		Node<Cargo*>* R = new Node<Cargo*>(item);
		R->SetNext(Head);
		Head = R;
		Cargos++;
	}

	void PrintIdList()
	{
		Node<Cargo*>* temp = Head;
		while (!temp)
		{
			cout << temp->GetItem()->GetID() << endl;
			temp = temp->GetNext();
		}
		cout << "finished" << endl;
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

	bool isEmpty()
	{
		if (!Head)
			return true;
		return false;
	}

	void InsertEnd(Cargo*& data)
	{
		Cargos++;
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

	Cargo* DeleteFirst()
	{
		Cargo* temp = nullptr;
		if (!Head)
			return nullptr;
		Cargos--;
		if (!Head->GetNext())
		{
			temp = Head->GetItem();
			delete Head;
			Head = nullptr;
			return temp;
		}
		temp = Head->GetItem();
		Node<Cargo*>* tempn = Head;
		Head = Head->GetNext();
		delete tempn;
		return temp;
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
		Cargos--;
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
		Cargos = 0;
	}


};

