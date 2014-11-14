#pragma once
#include "Stack.h"

#ifdef COMPILE_MYCLASSESLIB
#define MYCLASSESLIB_EXPORT __declspec(dllexport)
#else
#define MYCLASSESLIB_EXPORT //__declspec(dllimport)
#endif

class MYCLASSESLIB_EXPORT StackExtended :
	public Stack
{
public:
	StackExtended();
	~StackExtended();

	void clear(); // Reset the stack to be empty.
	bool full() const; // If the stack is full, return true; else return false.
	int size() const; // Return the number of entries in the stack.
};

