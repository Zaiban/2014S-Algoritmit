#include "QueueLinked.h"


QueueLinked::QueueLinked() : front(nullptr), rear(nullptr)
{
}
QueueLinked::QueueLinked(const QueueLinked &org)
{
	Node *new_copy, *original_node = org.front;
	if (original_node == nullptr) front = nullptr;
	else {                         //  Duplicate the linked nodes.
		front = new_copy = new Node(original_node->entry);
		while (original_node->next != nullptr) {
			original_node = original_node->next;
			new_copy->next = new Node(original_node->entry);
			new_copy = new_copy->next;
		}
		rear = new Node(original_node->entry);
		
	}
}
QueueLinked& QueueLinked::operator=(const QueueLinked &source)
{
	Node *new_top, *new_copy, *original_node = source.front;
	if (original_node == nullptr) new_top = nullptr;
	else
	{
		new_copy = new_top = new Node(original_node->entry);
		while (original_node->next != nullptr)
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
QueueLinked::~QueueLinked()
{
	while (!empty())
		serve();
}

bool QueueLinked::empty() const
{
	if (front == nullptr)
		return true;
	return false;
}
Error_code QueueLinked::append(const Node_entry &item)
{
	Node *new_rear = new Node(item);
	if (new_rear == nullptr) return overflow;
	if (rear == nullptr) front = rear = new_rear;
	else
	{
		rear->next = new_rear;
		rear = new_rear;
	}
	return success;
}
Error_code QueueLinked::serve()
{
	if (front == nullptr) return underflow;
	Node *old_front = front;
	front = old_front->next;
	if (front == nullptr) rear = nullptr;
	delete old_front;
	return success;
}
Error_code QueueLinked::retrieve(Node_entry &item)
{
	if (front == nullptr) return underflow;
	item = front->entry;
	return success;
}