#pragma once
#include "Queue.h"

#ifdef COMPILE_MYCLASSESLIB
#define MYCLASSESLIB_EXPORT __declspec(dllexport)
#else
#define MYCLASSESLIB_EXPORT //__declspec(dllimport)
#endif

class QueueExtended :
	public Queue
{
public:
	// POST: Return true if the Extended_queue is full, return false
	// otherwise.
	bool full() const;
	// POST: Return the number of entries in the Extended_queue
	unsigned int size() const;
	// POST: All entries in the Extended_queue have been removed, it is
	// now empty.
	void clear();
	// Return underflow if the Extended_queue is empty. Otherwise remove
	// and copy the item at the front of the Extended_queue to item and
	// return success.
	Error_code serve_and_retrieve(Queue_entry &);

private:

};

