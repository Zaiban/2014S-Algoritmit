#pragma once
#include "Utility.h"
const int MAX_LIST = 10;

#ifdef COMPILE_MYCLASSESLIB
#define MYCLASSESLIB_EXPORT __declspec(dllexport)
#else
#define MYCLASSESLIB_EXPORT //__declspec(dllimport)
#endif

template <class List_entry>
class MYCLASSESLIB_EXPORT List
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

