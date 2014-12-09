#pragma once
#include "List.h"
#include "Record.h"
class Ordered_list :
	public List < Record >
{
public:
	Ordered_list();
	~Ordered_list();
};

