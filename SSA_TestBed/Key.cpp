#include "Key.h"

int Key::comparisons = 0;

Key::Key()
{
}
Key::~Key()
{
}

int Key::the_key() const
{
	return key;
}

bool operator ==(const Key &x, const Key &y)
{
	Key::comparisons++;
	return x.the_key() == y.the_key();
}