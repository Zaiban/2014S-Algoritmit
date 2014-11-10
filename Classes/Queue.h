#pragma once

#include "Utility.h"
typedef char Queue_entry;
const int MAXQUEUE = 10;

class Queue
{
public:
	// POST: The queue is initialized empty.
	Queue();
	~Queue();
	
	// POST: Return true if the Queue is empty, otherwise return false.
	bool empty() const;
	// POST: The front of the Queue is removed. 
	// If the Queue is empty return an Error_code of underflow
	Error_code serve();
	// POST: item is added to the rear of the Queue. If the Queue is full
	// return an Error_code of overflow and leave the Queue unchanged.
	Error_code append(const Queue_entry &);
	// POST: The front of the Queue is retrieved to the output parameter
	// item. It the Queue is empty return an Error_code of underflow.
	Error_code retrieve(Queue_entry &) const;
protected:
	int count;
	int front, rear;
	Queue_entry entry[MAXQUEUE];
};

