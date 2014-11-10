#include "StackExtended.h"


StackExtended::StackExtended()
{

}

StackExtended::~StackExtended()
{
}

void StackExtended::clear()
{
	while (!empty())
		pop();
}
bool StackExtended::full() const
{
	if (count_ == MAXSTACK)
		return true;
	else
		return false;
}
int StackExtended::size() const
{
	return count_;
}