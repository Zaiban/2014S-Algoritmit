#ifndef STACK_H
#define STACK_H

#include "Utility.h"
typedef double Stack_entry;
const int MAXSTACK = 10;



class Stack{
public:
	Stack();
	/*
	Pre:  None.
	Post: The stack is initialized to be empty.
	*/
	~Stack();
	int getCount() const;
	void setCount(int);

	Error_code pop();
	/*
	Pre:  None.
	Post: If the Stack is not empty, the top of
	the Stack is removed.  If the Stack
	is empty, an Error_code of underflow is returned.
	*/
	Error_code top(Stack_entry &item) const;
	/*
	Pre:  None.
	Post: If the Stack is not empty, the top of
	the Stack is returned in item.  If the Stack
	is empty an Error_code of underflow is returned.
	*/
	Error_code push(const Stack_entry &item);
	/*
	Pre:  None.
	Post: If the Stack is not full, item is added to the top
	of the Stack.  If the Stack is full,
	an Error_code of overflow is returned and the Stack is left unchanged.
	*/
	bool empty() const;
	/*
	Pre:  None.
	Post: If the Stack is empty, true is returned.
	Otherwise false is returned.
	*/

private:
	int count_;
	Stack_entry entry[MAXSTACK];

};
#endif	