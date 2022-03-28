#pragma once



template <typename T>
class stack
{

	

public:


	
	virtual bool isEmpty() = 0;	

	virtual bool pop() = 0;

	virtual void push(T) = 0;


	virtual ~stack() {};
};
