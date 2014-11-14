#include "stdafx.h"
#include "QueueLinkedExtended.h"
#include <new>


bool QueueLinkedExtended::full() const
{
	Node_entry item = 0;
	Node *new_rear = new (std::nothrow)Node(item);
	if (new_rear == NULL)
		return true;

	delete new_rear;
	return false;
}
unsigned int QueueLinkedExtended::size() const
{
	unsigned int count = 0;
	const Node* position = front;
	if (position == NULL) return 0;
	while (position->next != NULL)
	{
		count++;
		position = position->next;
	}
	return count + 1;
}
void QueueLinkedExtended::clear()
{
	while (!empty())
		serve();
}
Error_code QueueLinkedExtended::serve_and_retrieve(Node_entry &item)
{
	if (retrieve(item) == underflow) return underflow;
	serve();
	return success;
}