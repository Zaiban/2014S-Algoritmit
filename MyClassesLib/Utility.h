#ifndef UTILITY_H_
#define UTILITY_H_

#ifdef COMPILE_MYCLASSESLIB
#define MYCLASSESLIB_EXPORT __declspec(dllexport)
#else
#define MYCLASSESLIB_EXPORT //__declspec(dllimport)
#endif

enum MYCLASSESLIB_EXPORT Error_code{
	success,
	overflow,
	underflow,
	range_error,
	stub_ec
};

#include <iostream>
bool user_says_yes();
int create_rand(int, int);


#endif