#include "recursive_binary_1.h"
Error_code recursive_binary_1(const Ordered_list &the_list, const Key &target,
	int bottom, int top, int &position)
{
	Record data;
	if (bottom < top) {              // List has more than one entry.
		int mid = (bottom + top) / 2;
		the_list.retrieve(mid, data);
		if (data < target)  // Reduce to top half of list.
			return recursive_binary_1(the_list, target, mid + 1, top, position);
		else                          // Reduce to bottom half of list.
			return recursive_binary_1(the_list, target, bottom, mid, position);
	}
	else if (top < bottom)
		return not_present;           // List is empty.
	else {                           // List has exactly one entry.
		position = bottom;
		the_list.retrieve(bottom, data);
		if (data == target) return success;
		else return not_present;
	}
}
