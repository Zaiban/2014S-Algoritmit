#pragma once
#include "Record.h"
#include "List.h"

class OrderedList :public List<Record>
{
public:
	OrderedList();
	~OrderedList();
};

