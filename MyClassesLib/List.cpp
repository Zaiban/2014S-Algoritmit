#include "stdafx.h"
#include "List.h"
using std::cout; using std::cin; using std::endl;

template <class List_entry>
List<List_entry>::List() :count_(0)
{
}
template <class List_entry>
List<List_entry>::~List()
{
}

template <class List_entry>
int List<List_entry>::size() const
{
	return count_;
}
template <class List_entry>
bool List<List_entry>::full() const
{
	if (count_ == MAX_LIST) return true;
	return false;
}
template <class List_entry>
bool List<List_entry>::empty() const
{
	if (count_ == 0) return true;
	return false;
}
template <class List_entry>
void List<List_entry>::clear()
{
	count_ = 0;
}
template <class List_entry>
void List<List_entry>::traverse(void(*visit)(List_entry &))
{
	for (int i = 0; i < count_; i++)
		(*visit)(entry[i]);
}
template <class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const
{
	if (empty())
		return underflow;

	if (position < 0 || position > count_ - 1)
		return range_error;

	x = entry[position];

	return success;
}
template <class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x)
{
	if (empty())
		return underflow;

	if (position < 0 || position > count_ - 1)
		return range_error;

	entry[position] = x;
	return success;
}
template <class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x)
{
	if (empty())
		return underflow;

	if (position < 0 || position > count_-1)
		return range_error;

	x = entry[position];

	for (int i = position; i < count_-1; i++)
		entry[i] = entry[i+1];

	count_--;
	return success;
}
template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)
{
	if (full())
		return overflow;

	if (position < 0 || position > count_)
		return range_error;

	for (int i = count_ - 1; i >= position; i--)
		entry[i + 1] = entry[i];

	entry[position] = x;
	count_++;
	return success;
}
template <class List_entry>
void List<List_entry>::testInput()
{
	cout << "Testing CLASS: List" << endl;
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