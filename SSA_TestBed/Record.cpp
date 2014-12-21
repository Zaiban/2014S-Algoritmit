#include "Record.h"

Record::Record()
{

}

Record::Record(int value)
{
	mKey = Key(value);
}


Record::~Record()
{
}

Record::operator Key() const
{
	return Key(mKey.the_key());
}
std::ostream &operator<<(std::ostream &output, const Record &record)
{
	output << record.mKey.the_key();
	return output;
}
