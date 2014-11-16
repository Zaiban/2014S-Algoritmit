#ifndef UTILITY_H_
#define UTILITY_H_

#ifdef COMPILE_MYCLASSESLIB
#define MYCLASSESLIB_EXPORT __declspec(dllexport)
#else
#define MYCLASSESLIB_EXPORT //__declspec(dllimport)
#endif

enum MYCLASSESLIB_EXPORT Error_code{
	success,
	fail,
	overflow,
	underflow,
	range_error
};

#include <iostream>
bool user_says_yes();
int create_rand(int, int);


#endif