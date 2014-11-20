#include "stdafx.h"
#include "ListLinkedSimple.h"
#include <new>
using std::cout; using std::endl; using std::cin;
template <class List_entry>
ListLinkedSimple<List_entry>::ListLinkedSimple() : count_(0)
{
}
template <class List_entry>
ListLinkedSimple<List_entry>::ListLinkedSimple(const ListLinkedSimple<List_entry> &org)
{
	Node<List_entry> *copy_position, *original;
	original = org.head_;
	if (original != nullptr && !full())
	{
		head_ = new Node<List_entry>(original->entry, nullptr);
		copy_position = head_;
		while (original->next != nullptr)
		{
			copy_position->next = new Node<List_entry>(original->next->entry, copy_position);
			copy_position = copy_position->next;
			original = original->next;
		}

	}
	count_ = org.count_;
}
template <class List_entry>
ListLinkedSimple<List_entry>& ListLinkedSimple<List_entry>::operator=(const ListLinkedSimple<List_entry> &source)
{
	if (this != &source)
	{
		Node<List_entry> *copy_position, *original = source.head_;

		if (original != nullptr && !full())
		{
			head_ = new Node<List_entry>(original->entry, nullptr);
			copy_position = head_;
			while (original->next != nullptr)
			{
				copy_position->next = new Node<List_entry>(original->next->entry, nullptr);
				copy_position = copy_position->next;
				original = original->next;
			}
		}
		count_ = source.count_;
	}
	return *this;
}
template <class List_entry>
ListLinkedSimple<List_entry>::~ListLinkedSimple()
{
	clear();
}
template <class List_entry>
int ListLinkedSimple<List_entry>::size() const
{
	int count = 1;
	const Node<List_entry>* position = head_;
	if (position == nullptr) return 0;
	while (position->next != nullptr)
	{
		count++;
		position = position->next;
	}
	return count;
}
template <class List_entry>
bool ListLinkedSimple<List_entry>::full() const
{
	Node<List_entry> *temp = new (std::nothrow)Node < List_entry > ;
	if (temp == nullptr) return true;
	delete temp;
	return false;
}
template <class List_entry>
bool ListLinkedSimple<List_entry>::empty() const
{
	if (count_ == 0) return true;
	return false;
}
template <class List_entry>
void ListLinkedSimple<List_entry>::clear()
{
	List_entry dummy;
	while (!empty())
		remove(0, dummy);
}
template <class List_entry>
void ListLinkedSimple<List_entry>::traverse(void(*visit)(List_entry &))
{
	if (count_ == 0) return;
	Node<List_entry> *current = head_;
	while (current->next != nullptr)
	{
		(*visit)(current->entry);
		current = current->next;
	}
}
template <class List_entry>
Error_code ListLinkedSimple<List_entry>::retrieve(int position, List_entry &x) const
{
	if (position < 0 || position > count_ - 1)
		return range_error;
	Node<List_entry> *current;
	current = set_position(position);
	x = current->entry;

	return success;
}
template <class List_entry>
Error_code ListLinkedSimple<List_entry>::replace(int position, const List_entry &x)
{
	if (position < 0 || position > count_ - 1)
		return range_error;
	Node<List_entry> *current;
	current = set_position(position);
	current->entry = x;
	return success;
}
template <class List_entry>
Error_code ListLinkedSimple<List_entry>::remove(int position, List_entry &x)
{
	if (position < 0 || position > count_ - 1)
		return range_error;
	if (count_ == 1)
	{
		x = head_->entry;
		delete head_;
		head_ = nullptr;
		count_ = 0;
		return success;
	}
	Node<List_entry> *previous, *current, *following;
	previous = set_position(position - 1);
	current = previous->next;
	following = current->next;
	x = current->entry;
	delete current;
	if (previous != nullptr)
		previous->next = following;
 
	count_--;
	return success;

}
template <class List_entry>
Error_code ListLinkedSimple<List_entry>::insert(int position, const List_entry &x)
{
	if (position < 0 || position > count_)
		return range_error;
	Node<List_entry> *new_node, *previous, *following;
	if (position > 0) {
		previous = set_position(position - 1);
		following = previous->next;
	}
	else{
		previous = nullptr;
		following = head_;
	}

	if (full())
		return overflow;
	new_node = new Node<List_entry>(x, following);
	if (position == 0)
		head_ = new_node;
	else
		previous->next = new_node;
	count_++;
	return success;
}
template <class List_entry>
Node<List_entry> *ListLinkedSimple<List_entry>::set_position(int position) const
{
	Node<List_entry> *q = head_;
	for (int i = 0; i < position; i++) q = q->next;
	return q;
}
template <class List_entry>
void ListLinkedSimple<List_entry>::testInput()
{
	cout << "Testing CLASS: ListLinkedSimple" << endl;
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