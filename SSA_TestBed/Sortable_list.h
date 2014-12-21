#pragma once
#include "List.h"
#include "Record.h"
class Sortable_list :
	public List < Record >
{
public:
	Sortable_list();
	~Sortable_list();
};

