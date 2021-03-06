#pragma once
#include"Node.h"

#include<iostream>
using namespace std;



template <typename T>
class PriorityQueue
{

public:

	virtual void Enqueue(T,int)=0;
	virtual bool isEmpty()=0;
	virtual bool Dequeue() = 0;
	virtual bool Peek(T&) = 0;
	virtual ~PriorityQueue() {};

};