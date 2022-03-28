#pragma once


template <typename T>
class Node
{
	T item;
	Node<T>* Next;

public:

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



};

