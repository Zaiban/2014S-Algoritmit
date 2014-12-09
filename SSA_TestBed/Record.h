#pragma once
#include "Key.h"
class Record
{
public:
	Record();
	~Record();

	operator Key();
private:
	Key key;
};

