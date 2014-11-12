#pragma once
#include "NODE.H"
#include "Utility.h"

class QueueLinked
{
public:
	QueueLinked();
	QueueLinked(const QueueLinked &);
	QueueLinked& operator=(const QueueLinked &);
	~QueueLinked();
	
	// Returns true if the QueueLinked is empty
	// Otherwise returns false
	bool empty() const;
	// Node_entry is added to the top of the QueueLinked
	// Returns overflow if dynamic memory is exhausted
	Error_code append(const Node_entry &);
	// The end of the QueueLinked is removed
	// Returns underflow if QueueLinked is empty
	// Otherwise returns success
	Error_code serve();
	Error_code retrieve(Node_entry &);
protected:
	Node *front, *rear;
};

