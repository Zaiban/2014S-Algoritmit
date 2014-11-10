#include "QueueLinked.h"


QueueLinked::QueueLinked() : front(NULL), rear(NULL)
{
}
QueueLinked::QueueLinked(const QueueLinked &org)
{
	Node *new_copy, *original_node = org.front;
	if (original_node == NULL) front = NULL;
	else {                         //  Duplicate the linked nodes.
		front = new_copy = new Node(original_node->entry);
		while (original_node->next != NULL) {
			original_node = original_node->next;
			new_copy->next = new Node(original_node->entry);
			new_copy = new_copy->next;
		}
		rear = new Node(original_node->entry);
		
	}
}
QueueLinked::~QueueLinked()
{
	while (!empty())
		serve();
}
Node* QueueLinked::getFront() const
{
	return front;
}
Node* QueueLinked::getRear() const
{
	return rear;
}
QueueLinked& QueueLinked::operator=(const QueueLinked &source)
{
	Node *new_top, *new_copy, *original_node = source.front;
	if (original_node == NULL) new_top = NULL;
	else
	{
		new_copy = new_top = new Node(original_node->entry);
		while (original_node->next != NULL)
		{
			original_node = original_node->next;
			new_copy->next = new Node(original_node->entry);
			new_copy = new_copy->next;
		}
		rear = new Node(original_node->entry);
	}
	while (!empty())
		serve();
	front = new_top;

	return *this;
}

bool QueueLinked::empty() const
{
	if (front == NULL)
		return true;
	return false;
}
Error_code QueueLinked::append(const Node_entry &item)
{
	Node *new_rear = new Node(item);
	if (new_rear == NULL) return overflow;
	if (rear == NULL) front = rear = new_rear;
	else
	{
		rear->next = new_rear;
		rear = new_rear;
	}
	return success;
}
Error_code QueueLinked::serve()
{
	if (front == NULL) return underflow;
	Node *old_front = front;
	front = old_front->next;
	if (front == NULL) rear = NULL;
	delete old_front;
	return success;
}
Error_code QueueLinked::retrieve(Node_entry &item)
{
	if (front == NULL) return underflow;
	item = front->entry;
	return success;
}