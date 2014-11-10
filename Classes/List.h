#pragma once
#include "Utility.h"

const int MAX_LIST = 10;
template <class List_entry>
class List
{
public:
	List();
	~List();

	int size() const;
	bool full() const;
	bool empty() const;
	void clear();
	void traverse(void(*visit)(List_entry &));
	Error_code retrieve(int position, List_entry &x) const;
	Error_code replace(int position, const List_entry &x);
	Error_code remove(int position, List_entry &x);
	Error_code insert(int position, const List_entry &x);
	
	void testInput();
protected:
	int count_;
	List_entry entry[MAX_LIST];
};

