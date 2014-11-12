#include "ListLinkedSimple.cpp"
#include <iostream>

using std::cout; using std::endl;

int main()
{
	ListLinkedSimple<char> test_org;
	char item;
	for (int i = 0; i < 5; i++)
	{
		item = 'a' + i;
		test_org.insert(0, item);
	}
	test_org.retrieve(0, item);
	cout << "test_org 0 on: " << item << endl;
	

	ListLinkedSimple<char> test_copy(test_org);
	test_copy.retrieve(0, item);
	cout << "test_copy 0 on: " << item << endl;

	ListLinkedSimple<char> test_assigned = test_org;
	test_assigned.retrieve(0, item);
	cout << "test_assigned 0 on: " << item << endl;

	system("pause");
	return 0;
}