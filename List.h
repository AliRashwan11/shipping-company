#pragma once

template <typename T>
class List
{
	
public:

	virtual void InsertBeg(const T&)=0;
	virtual void InsertEnd(const T&)=0;
	virtual bool Find(T)=0;
	virtual void PrintList()=0;
	virtual void DeleteAll()=0;

};
