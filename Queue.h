#pragma once



template<typename T>
class Queue
{


public:

	virtual void Enqueue(T) = 0;
	virtual bool Dequeue() = 0;
	virtual bool Peek(T&) = 0;
	virtual bool isEmpty() = 0;
	virtual ~Queue() {};

};

// interface of queue ADT