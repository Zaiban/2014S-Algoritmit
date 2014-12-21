#pragma once
#include "Key.h"
#include <iostream>
class Record
{
public:
	Record();
	Record(int value);
	~Record();

	operator Key() const;
	friend std::ostream &operator<<(std::ostream &output, const Record &record);
private:
	Key mKey;
};