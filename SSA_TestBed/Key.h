#pragma once
class Key
{
public:
	static int comparisons;

	Key();
	~Key();

	int the_key() const;
private:
	int key;
};

bool operator ==(const Key &x, const Key &y);
bool operator > (const Key &x, const Key &y);
bool operator < (const Key &x, const Key &y);
bool operator >=(const Key &x, const Key &y);
bool operator <=(const Key &x, const Key &y);
bool operator !=(const Key &x, const Key &y);