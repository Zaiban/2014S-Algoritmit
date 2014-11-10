#include "QueueExtended.h"


bool QueueExtended::full() const
{
	if (count >= MAXQUEUE)
		return true;
	else
		return false;
}

unsigned int QueueExtended::size() const
{
	return count;
}

void QueueExtended::clear()
{
	count = 0;
	front = 0;
	rear = MAXQUEUE - 1;
}

Error_code QueueExtended::serve_and_retrieve(Queue_entry &item)
{
	if (count <= 0) return underflow;
	retrieve(item);
	serve();
	return success;
}