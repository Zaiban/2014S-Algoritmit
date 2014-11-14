#include "stdafx.h"
#include "ListLinkedDouble.h"
#include <iostream>
#include <new>
using std::cout; using std::endl; using std::cin;
template <class List_entry>
ListLinkedDouble<List_entry>::ListLinkedDouble() :count_(0), current_position_(0)
{
}
template <class List_entry>
ListLinkedDouble<List_entry>::ListLinkedDouble(const ListLinkedDouble<List_entry> &org)
{
	Node<List_entry> *copy_position, *original;
	org.set_position(0);
	original = org.current_;
	if (original != nullptr && !full())
	{
		current_ = new Node<List_entry>(original->entry, nullptr);
		current_position_ = 0;
		copy_position = current_;
		while (original->next != nullptr)
		{
			copy_position->next = new Node<List_entry>(original->next->entry, copy_position, nullptr);
			copy_position = copy_position->next;
			original = original->next;
		}

	}
	count_ = org.count_;
}
template <class List_entry>
ListLinkedDouble<List_entry>& ListLinkedDouble<List_entry>::operator=(const ListLinkedDouble<List_entry> &source)
{
	if (this != &source)
	{
		Node<List_entry> *copy_position, *original;
		source.set_position(0);
		original = source.current_;
		if (original != nullptr && !full())
		{
			current_ = new Node<List_entry>(original->entry, nullptr);
			current_position_ = 0;
			copy_position = current_;
			while (original->next != nullptr)
			{
				copy_position->next = new Node<List_entry>(original->next->entry, copy_position, nullptr);
				copy_position = copy_position->next;
				original = original->next;
			}

		}
		count_ = source.count_;
	}
	return *this;
}
template <class List_entry>
ListLinkedDouble<List_entry>::~ListLinkedDouble()
{
	//TO-DO
}
template <class List_entry>
int ListLinkedDouble<List_entry>::size() const
{
	int count_ = 1;
	set_position(0);
	const Node<List_entry>* position = current_;
	if (position == nullptr) return 0;
	while (position->next != nullptr)
	{
		count_++;
		position = position->next;
	}
	return count_;
}
template <class List_entry>
bool ListLinkedDouble<List_entry>::full() const
{
	Node<List_entry> *temp = new (std::nothrow)Node<List_entry>;
	if (temp == nullptr) return true;
	delete temp;
	return false;
}
template <class List_entry>
bool ListLinkedDouble<List_entry>::empty() const
{
	if (count_ == 0) return true;
	return false;
}
template <class List_entry>
void ListLinkedDouble<List_entry>::clear()
{
	List_entry dummy;
	while (!empty())
		remove(0, dummy);
}
template <class List_entry>
void ListLinkedDouble<List_entry>::traverse(void(*visit)(List_entry &))
{
	if (count_ == 0) return;
	set_position(0);
	while (current_->next != nullptr)
	{
		(*visit)(current_->entry);
		current_ = current_->next;
	}
}
template <class List_entry>
Error_code ListLinkedDouble<List_entry>::retrieve(int position, List_entry &x) const
{
	if (position < 0 || position > count_ - 1)
		return range_error;
	set_position(position);
	x = current_->entry;
	return success;
}
template <class List_entry>
Error_code ListLinkedDouble<List_entry>::replace(int position, const List_entry &x)
{
	if (position < 0 || position > count_ - 1)
		return range_error;
	set_position(position);
	current_->entry = x;

	return success;
}
template <class List_entry>
Error_code ListLinkedDouble<List_entry>::remove(int position, List_entry &x)
{
	if (position < 0 || position > count_ - 1)
		return range_error;
	if (count_ == 1)
	{
		x = current_->entry;
		delete current_;
		current_ = nullptr;
		current_position_ = 0;
		count_ = 0;
		return success;
	}
	Node<List_entry> *previous, *following;
	set_position(position);
	previous = current_->back;
	following = current_->next;
	x = current_->entry;
	delete current_;
	current_ = following;
	if (previous != nullptr)
		previous->next = following;
	if (following != nullptr)
		following->back = previous;

	count_--;
	return success;
}
template <class List_entry>
Error_code ListLinkedDouble<List_entry>::insert(int position, const List_entry &x)
{
	Node<List_entry> *new_node, *following, *preceding;
	if (position < 0 || position > count_) return range_error;
	if (position == 0) {
		if (count_ == 0) following = nullptr;
		else {
			set_position(0);
			following = current_;
		}
		preceding = nullptr;
	}
	else {
		set_position(position - 1);
		preceding = current_;
		following = preceding->next;
	}
	new_node = new Node<List_entry>(x, preceding, following);

	if (full()) return overflow;
	if (preceding != nullptr) preceding->next = new_node;
	if (following != nullptr) following->back = new_node;
	current_ = new_node;
	current_position_ = position;
	count_++;
	return success;
}
template <class List_entry>
void ListLinkedDouble<List_entry>::testInput()
{
	cout << "Testing CLASS: ListLinkedDouble" << endl;
	cout << "Test input is asked until terminated" << endl;
	char command[2];
	int pos, action;
	List_entry item, dummy;
	while (true)
	{
		cout << "\nChoose what method to test " << endl
			<< "\n[a]insert(position, item)"
			<< "\n[b]remove(position)"
			<< "\n[c]retrieve(position)"
			<< "\n[d]replace(position, item)"
			<< "\n[e]size()"
			<< "\n[f]clear()"
			<< "\n[Q]uit." << endl;

		cin.getline(command, 2);

		switch (command[0]){
		case 'a':
		case 'A':
			cout << "input position: ";
			cin.getline(command, 2);
			pos = atoi(command);
			cout << "input item: ";
			cin.getline(command, 2);
			item = command[0];
			action = insert(pos, item);
			if (action == overflow)
				cout << "List is full" << endl;
			else if (action == range_error)
				cout << "Invalid position" << endl;
			else if (action == success)
				cout << "Item inserted" << endl;
			break;
		case 'b':
		case 'B':
			cout << "input position: ";
			cin.getline(command, 2);
			pos = atoi(command);
			action = remove(pos, dummy);
			if (action == underflow)
				cout << "List is empty" << endl;
			else if (action == range_error)
				cout << "Invalid position" << endl;
			else if (action == success)
				cout << "Item deleted" << endl;
			break;
		case 'c':
		case 'C':
			cout << "input position: ";
			cin.getline(command, 2);
			pos = atoi(command);
			action = retrieve(pos, item);
			if (action == range_error)
				cout << "Invalid position" << endl;
			else if (action == success)
				cout << "Position contains: " << item << endl;
			break;
		case 'd':
		case 'D':
			cout << "input position: ";
			cin.getline(command, 2);
			pos = atoi(command);
			cout << "input item: ";
			cin.getline(command, 2);
			item = command[0];
			action = replace(pos, item);
			if (action == range_error)
				cout << "Invalid position" << endl;
			else if (action = success)
				cout << "Position replaced" << endl;
			break;
		case 'e':
		case 'E':
			cout << "Size of the list: " << size() << endl;
			break;
		case'f':
		case'F':
			clear();
			cout << "List has been cleared" << endl;
			break;
		case 'q':
		case 'Q':
			cout << "Quitting.." << endl;
			return;
		default:
			cout << "Error: invalid input" << endl;
			break;
		}
	}
}
template <class List_entry>
void ListLinkedDouble<List_entry>::set_position(int position) const
{
	if (current_position_ <= position)
		for (; current_position_ != position; current_position_++)
			current_ = current_->next;
	else
		for (; current_position_ != position; current_position_--)
			current_ = current_->back;
}