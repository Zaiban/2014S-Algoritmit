#pragma once
class Key
{
public:
	static int comparisons;

	Key();
	Key(int value);
	~Key();

	int the_key() const;
private:
	int mKey;
};

bool operator ==(const Key &x, const Key &y);
bool operator > (const Key &x, const Key &y);
bool operator < (const Key &x, const Key &y);
bool operator >=(const Key &x, const Key &y);
bool operator <=(const Key &x, const Key &y);
bool operator !=(const Key &x, const Key &y);