#pragma once

template <typename T>
class List
{
	
public:

	virtual void InsertBeg(T&)=0;
	virtual void InsertEnd(T&)=0;
	virtual bool Find(int)=0;
	virtual void PrintList()=0;
	virtual void DeleteAll()=0;

};
