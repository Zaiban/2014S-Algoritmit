#include "stdafx.h"
#include "Stack.h"

Stack::Stack() :count_(0)
{
}
Stack::~Stack()
{
}
int Stack::getCount() const
{
	return count_;
}
void Stack::setCount(int count)
{
	count_ = count;
}
Error_code Stack::pop()
{
	Error_code outcome = success;
	if (count_ == 0)
		outcome = underflow;
	else --count_;;
	return outcome;
}

Error_code Stack::top(Stack_entry &item) const
{
	Error_code outcome = success;
	if (count_ == 0)
		outcome = underflow;
	else
		item = entry[count_ - 1];
	return outcome;
}

Error_code Stack::push(const Stack_entry &item)
{
	Error_code outcome = success;
	if (count_ >= MAXSTACK)
		outcome = overflow;
	else
		entry[count_++] = item;
	return outcome;
}

bool Stack::empty() const
{
	bool outcome = true;
	if (count_ > 0) outcome = false;
	return outcome;
}