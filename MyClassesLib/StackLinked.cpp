#include "stdafx.h"
#include "StackLinked.h"

#include <string>
using std::cin; using std::cout; using std::endl; using std::string;

template <class Stack_entry>
StackLinked<Stack_entry>::StackLinked() :top_node(nullptr)
{
}
template <class Stack_entry>
StackLinked<Stack_entry>::StackLinked(const StackLinked &org)
{
	Node<Stack_entry> *new_copy, *original_node = org.top_node;
	if (original_node == NULL) top_node = NULL;
	else
	{
		top_node = new_copy = new Node<Stack_entry>(original_node->entry);
		// Check if next org node exists
		while (original_node->next != NULL)
		{
			// Move to the next org node
			original_node = original_node->next;
			// Make the NEXT new node 
			// put the address to CURRENT new node's 'next' pointer
			new_copy->next = new Node<Stack_entry>(original_node->entry);
			// Move to the next new node
			new_copy = new_copy->next;
		}
	}
}
template <class Stack_entry>
StackLinked<Stack_entry>::~StackLinked()
{
	while (!empty())
		pop();
}
template <class Stack_entry>
StackLinked<Stack_entry>& StackLinked<Stack_entry>::operator=(const StackLinked<Stack_entry> &source)
{
	Node<Stack_entry> *new_top, *new_copy, *original_node = source.top_node;
	if (original_node == NULL) new_top = NULL;
	else
	{
		new_copy = new_top = new Node<Stack_entry>(original_node->entry);
		while (original_node->next != NULL)
		{
			original_node = original_node->next;
			new_copy->next = new Node<Stack_entry>(original_node->entry);
			new_copy = new_copy->next;
		}
	}
	while (!empty())
		pop();
	top_node = new_top;

	return *this;
}
template <class Stack_entry>
bool StackLinked<Stack_entry>::empty() const
{
	if (top_node == NULL) 
		return true;
	return false;
}
template <class Stack_entry>
Error_code StackLinked<Stack_entry>::push(const Stack_entry &item)
{
	Node<Stack_entry> *new_top = new Node<Stack_entry>(item, top_node);
	if (new_top == NULL) return overflow;
	top_node = new_top;
	return success;
}
template <class Stack_entry>
Error_code StackLinked<Stack_entry>::pop()
{
	Node<Stack_entry> *old_top = top_node;
	if (top_node == nullptr) return underflow;
	top_node = old_top->next;
	delete old_top;
	return success;
}
template <class Stack_entry>
Error_code StackLinked<Stack_entry>::top(Stack_entry &item) const
{
	if (top_node == nullptr) return underflow;
	item = top_node->entry;
	return success;
}
template <class Stack_entry>
void StackLinked<Stack_entry>::askInput()
{
	string input;
	Stack_entry item;
	cin.clear();
	cin.ignore();
	getline(cin, input);

	for (unsigned i = 0; i < input.size(); i++)
	{
		item = input.at(i);
		push(item);
	}
}