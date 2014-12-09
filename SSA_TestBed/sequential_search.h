#pragma once
#include "Utility.h"
#include "List.cpp"
#include "Record.h"
#include "Key.h"

/*
Post: If an entry in the_list has key equal to target, then return
success and the output parameter position locates such an entry
within the list.
Otherwise return not_present and position becomes invalid.
*/
Error_code sequential_search(const List<Record> &the_list,
	const Key &target, int &position);