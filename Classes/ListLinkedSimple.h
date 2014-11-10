#pragma once
#include "Utility.h"
#include "NODE_SLL.h"

template <class List_entry>
class ListLinkedSimple
{
public:
	ListLinkedSimple();
	ListLinkedSimple(const ListLinkedSimple<List_entry> &org);
	ListLinkedSimple<List_entry>& operator=(const ListLinkedSimple<List_entry> &);
	~ListLinkedSimple();
	// The function returns the number of entries in the List
	int size() const;
	// The function returns true or false according to whether
	// the list is full or not
	bool full() const;
	// The function returns true or false according to whether 
	// the List is empty or not.
	bool empty() const;
	// All list entries have been removed; the List is empty
	void clear();
	void traverse(void(*visit)(List_entry &));
	Error_code retrieve(int position, List_entry &x) const;
	Error_code replace(int position, const List_entry &x);
	Error_code remove(int position, List_entry &x);
	Error_code insert(int position, const List_entry &x);

	void testInput();

protected:
	int count_;
	Node<List_entry> *head;

	Node<List_entry> *set_position(int position) const;
};

