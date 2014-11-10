#pragma once
#include "QueueLinked.h"
class QueueLinkedExtended :
	public QueueLinked
{
public:
	// POST: Return true if the ExtendedLinkedQueue is full, return false
	// otherwise.
	bool full() const;
	// POST: Return the number of entries in the ExtendedLinkedQueue
	unsigned int size() const;
	// POST: All entries in the ExtendedLinkedQueue have been removed, it is
	// now empty.
	void clear();
	// Return underflow if the ExtendedLinkedQueue is empty. Otherwise remove
	// and copy the item at the front of the Extended_queue to item and
	// return success.
	Error_code serve_and_retrieve(Node_entry &);

};

