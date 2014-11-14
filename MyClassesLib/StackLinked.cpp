#include "stdafx.h"
#include "StackLinked.h"
#include <iostream>
#include <string>
using std::cin; using std::cout; using std::endl; using std::string;

StackLinked::StackLinked() :top_node(NULL)
{
}
StackLinked::StackLinked(const StackLinked &org)
{
	Node *new_copy, *original_node = org.top_node;
	if (original_node == NULL) top_node = NULL;
	else
	{
		top_node = new_copy = new Node(original_node->entry);
		// Check if next org node exists
		while (original_node->next != NULL)
		{
			// Move to the next org node
			original_node = original_node->next;
			// Make the NEXT new node 
			// put the address to CURRENT new node's 'next' pointer
			new_copy->next = new Node(original_node->entry);
			// Move to the next new node
			new_copy = new_copy->next;
		}
	}
}
StackLinked::~StackLinked()
{
	while (!empty())
		pop();
}
StackLinked& StackLinked::operator=(const StackLinked &source)
{
	Node *new_top, *new_copy, *original_node = source.top_node;
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
	}
	while (!empty())
		pop();
	top_node = new_top;

	return *this;
}

bool StackLinked::empty() const
{
	if (top_node == NULL) 
		return true;
	return false;
}
Error_code StackLinked::push(const Node_entry &item)
{
	Node *new_top = new Node(item, top_node);
	if (new_top == NULL) return overflow;
	top_node = new_top;
	return success;
}
Error_code StackLinked::pop()
{
	Node *old_top = top_node;
	if (top_node == NULL) return underflow;
	top_node = old_top->next;
	delete old_top;
	return success;
}
Error_code StackLinked::top(Node_entry &item) const
{
	if (top_node == NULL) return underflow;
	item = top_node->entry;
	return success;
}
void StackLinked::askInput()
{
	string input;
	Node_entry item;
	cin.clear();
	cin.ignore();
	getline(cin, input);

	for (unsigned i = 0; i < input.size(); i++)
	{
		item = input.at(i);
		push(item);
	}
}