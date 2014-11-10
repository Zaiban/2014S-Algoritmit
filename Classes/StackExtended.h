#pragma once
#include "Stack.h"
class StackExtended :
	public Stack
{
public:
	StackExtended();
	~StackExtended();

	void clear(); // Reset the stack to be empty.
	bool full() const; // If the stack is full, return true; else return false.
	int size() const; // Return the number of entries in the stack.
};

