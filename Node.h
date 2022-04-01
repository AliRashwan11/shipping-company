#pragma once


template <typename T>
class Node
{
	T item;
	Node<T>* Next;
	int priority;

public:

	Node()
	{
		Next = nullptr;
		priority = 0;
	}

	void SetNext(Node<T>* inP)
	{
		Next = inP;
	}
	
	Node <T> *GetNext()
	{
		return Next;
	}

	void SetItem(T inItem)
	{
		item = inItem;
	}

	T GetItem()
	{
		return item;
	}

	int GetPriority()
	{
		return priority;
	}

	void SetPriority(int a)
	{
		priority = a;
	}

};

