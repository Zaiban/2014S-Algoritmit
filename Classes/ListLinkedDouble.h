#pragma once
#include "Utility.h"
#include "NODE_DLL.h"

template <class List_entry>
class ListLinkedDouble
{
public:
	ListLinkedDouble();
	ListLinkedDouble(const ListLinkedDouble<List_entry> &org);
	ListLinkedDouble<List_entry>& operator=(const ListLinkedDouble<List_entry> &);
	~ListLinkedDouble();
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
	mutable int current_position_;
	mutable Node<List_entry> *current_;

	void set_position(int position) const;
};

