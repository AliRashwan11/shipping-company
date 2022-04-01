#pragma once


template <typename T>
class PriorityQueue
{

public:

	virtual void Enqueue(T,int)=0;
	virtual bool isEmpty()=0;
	virtual bool Dequeue(T&) = 0;
	virtual bool Peek(T&) = 0;
	virtual ~PriorityQueue() {};

};