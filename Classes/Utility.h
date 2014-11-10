#ifndef UTILITY_H_
#define UTILITY_H_

enum Error_code{
	success,
	overflow,
	underflow,
	range_error
};

#include <iostream>
bool user_says_yes();
int create_rand(int, int);


#endif