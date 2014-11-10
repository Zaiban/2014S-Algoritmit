#include "Queue.h"


Queue::Queue() :count(0), rear(MAXQUEUE - 1), front(0)
{
}
Queue::~Queue()
{
}

bool Queue::empty() const
{
	return count == 0;
}
Error_code Queue::serve()
{
	if (count <= 0) return underflow;
	count--;
	front = ((front + 1) == MAXQUEUE) ? 0 : (front + 1);
	return success;
}
Error_code Queue::append(const Queue_entry &item)
{
	if (count >= MAXQUEUE) return overflow;
	count++;
	rear = ((rear + 1) == MAXQUEUE) ? 0 : (rear + 1);
	entry[rear] = item;
	return success;
}
Error_code Queue::retrieve(Queue_entry &item) const
{
	if (count <= 0) return underflow;
	item = entry[front];
	return success;
}