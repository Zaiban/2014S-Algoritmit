#include "ListLinkedSimple.h"

template <class List_entry>
ListLinkedSimple<List_entry>::ListLinkedSimple() : count_(0)
{
}
template <class List_entry>
ListLinkedSimple<List_entry>::ListLinkedSimple(const ListLinkedSimple<List_entry> &org)
{
	// TODO
}
template <class List_entry>
ListLinkedSimple<List_entry>& ListLinkedSimple<List_entry>::operator=(const ListLinkedSimple<List_entry>&)
{
	// TODO
}
template <class List_entry>
ListLinkedSimple<List_entry>::~ListLinkedSimple()
{
	// TODO
}

template <class List_entry>
int ListLinkedSimple<List_entry>::size() const
{
	int count = 0;
	const Node<List_entry>* position = head;
	if (position == NULL) return 0;
	while (position->next != NULL)
	{
		count++;
		position = position->next;
	}
	return count + 1;
}
template <class List_entry>
bool ListLinkedSimple<List_entry>::full() const
{
	// TODO
}
template <class List_entry>
bool ListLinkedSimple<List_entry>::empty() const
{
	// TODO
}
template <class List_entry>
void ListLinkedSimple<List_entry>::clear()
{
	// TODO
}
template <class List_entry>
void ListLinkedSimple<List_entry>::traverse(void(*visit)(List_entry &))
{
	// TODO
}
template <class List_entry>
Error_code ListLinkedSimple<List_entry>::retrieve(int position, List_entry &x) const
{
	// TODO
}
template <class List_entry>
Error_code ListLinkedSimple<List_entry>::replace(int position, const List_entry &x)
{
	// TODO
}
template <class List_entry>
Error_code ListLinkedSimple<List_entry>::remove(int position, List_entry &x)
{
	// TODO
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
		previous = NULL;
		following = head;
	}

		
	new_node = new Node<List_entry>(x, following);
	if (new_node == NULL)
		return overflow;
	if (position == 0)
		head = new_node;
	else
		previous->next = new_node;
	count_++;
	return success;
}
template <class List_entry>
Node<List_entry> *ListLinkedSimple<List_entry>::set_position(int position) const
{
	Node<List_entry> *q = head;
	for (int i = 0; i < position; i++) q = q->next;
	return q;
}
template <class List_entry>
void ListLinkedSimple<List_entry>::testInput()
{
	cout << "Testing CLASS: ListLinkedSimple" << endl;
	cout << "Test input is asked until terminated" << endl;
	char input = 0;
	int pos, action;
	List_entry item, dummy;
	while (true)
	{
		cout << "\nChoose what function to test " << endl
			<< "\n[a]insert(position, item)"
			<< "\n[b]remove(position)"
			<< "\n[c]retrieve(position)"
			<< "\n[d]replace(position, item)"
			<< "\n[e]size()"
			<< "\n[f]clear()"
			<< "\n[Q]uit." << endl;

		cin.get(input);

		switch (input){
		case 'a':
		case 'A':
			cout << "input position: ";
			cin >> pos;
			cout << "input item: ";
			cin >> item;
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
			cin >> pos;
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
			cin >> pos;
			action = retrieve(pos, item);
			if (action == range_error)
				cout << "Invalid position" << endl;
			else if (action == success)
				cout << "Position contains: " << item << endl;
			break;
		case 'd':
		case 'D':
			cout << "input position: ";
			cin >> pos;
			cout << "input item: ";
			cin >> item;
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
		case 'q':
		case 'Q':
			cout << "Quitting.." << endl;
			return;
		default:
			cout << "Error: invalid input" << endl;
			break;
		}
		cin.clear();
		cin.ignore();
	}
}