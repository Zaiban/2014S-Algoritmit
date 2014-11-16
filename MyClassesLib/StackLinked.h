#pragma once
#include "NODE.H"
#include "Utility.h"

#ifdef COMPILE_MYCLASSESLIB
#define MYCLASSESLIB_EXPORT __declspec(dllexport)
#else
#define MYCLASSESLIB_EXPORT //__declspec(dllimport)
#endif

template <class Stack_entry>
class MYCLASSESLIB_EXPORT StackLinked
{
public:
	StackLinked();
	StackLinked(const StackLinked<Stack_entry> &);
	~StackLinked();
	StackLinked<Stack_entry>& operator=(const StackLinked<Stack_entry> &);

	// Returns true if the StackLinked is empty
	// Otherwise returns false
	bool empty() const;
	// Node_entry is added to the top of the StackLinked
	// Returns overflow if dynamic memory is exhausted
	Error_code push(const Stack_entry &);
	// The top of the StackLinked is removed
	// Returns underflow if StackLinked is empty
	// Otherwise returns success
	Error_code pop();
	// Returns Node_entry that contains top of the StackLinked
	// Returns underflow if StackLinked is empty
	Error_code top(Stack_entry &) const;

	// Prints a message for the user asking him to input a line of text
	// Inputted text is then parsed to the stack starting from the first letter
	void askInput();
private:
	Node<Stack_entry> *top_node;
};

