#include "Utility.h"
#include "Ordered_list.h"
/*
Pre:  The indices bottom to top define the
range in the list to search for the target.
Post: If a Record in the range of locations
from bottom to top in the_list has key equal
to target, then position locates
one such entry and a code of success is returned.
Otherwise, the Error_code of not_present is returned
and position becomes undefined.
Uses: recursive_binary_1 and methods of the classes List and Record.
*/
Error_code recursive_binary_1(const Ordered_list &the_list, const Key &target,
	int bottom, int top, int &position);