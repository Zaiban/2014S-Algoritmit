#include <iostream>
#include <string>
using std::cout; using std::endl; using std::string;

void testList();
void testListLinkedSimple();
void testListLinkedDouble();
void testQueueLinked();
void testQueueLinkedExtended();
void testStackLinked();
void test_search

// There are different settings for testing each class
// Uncomment ONLY one of the following settings at time 
// (depending on what class you have currently #included):
int main()
{
	string choose;
	
	



	system("pause");
	return 0;
}

void testList()
{
	// SETTING 1: FOR List.cpp

	/*
	List<char> test;
	test.testInput();
	*/
}
void testListLinkedSimple()
{
	//SETTING 2: FOR ListLinkedSIMPLE.cpp

	/*
	while (true)
	{
	cout << "\nType: 'c' for testing constructors"
	<< "\nor 'm' for testing methods or 'q' to quit" << endl;
	getline(std::cin, choose);
	if (choose == "c")
	{
	ListLinkedSimple<char> test_org;
	char item;
	for (int i = 5; i >= 0; i--)
	{
	item = 'a' + i;
	test_org.insert(0, item);
	}
	test_org.retrieve(0, item);
	cout << "test_org 0 is: " << item << endl;


	ListLinkedSimple<char> test_copy(test_org);
	test_copy.retrieve(0, item);
	cout << "test_copy 0 is: " << item << endl;

	ListLinkedSimple<char> test_assigned;
	test_assigned = test_org;
	test_assigned.retrieve(0, item);
	cout << "test_assigned 0 is: " << item << endl;
	}
	else if (choose == "m")
	{
	ListLinkedSimple<char> test;

	test.testInput();
	}
	else if(choose == "q") break;
	}
	*/
}
void testListLinkedDouble()
{
	// SETTING 3: FOR ListLinkedDOUBLE.cpp 

	/*
	while (true)
	{
	cout << "\nType: 'c' for testing constructors"
	<< "\nor 'm' for testing methods or 'q' to quit" << endl;
	getline(std::cin, choose);
	if (choose == "c")
	{
	ListLinkedDouble<char> test_org;
	char item;
	for (int i = 5; i >= 0; i--)
	{
	item = 'a' + i;
	test_org.insert(0, item);
	}
	test_org.retrieve(0, item);
	cout << "test_org 0 is: " << item << endl;


	ListLinkedDouble<char> test_copy(test_org);
	test_copy.retrieve(0, item);
	cout << "test_copy 0 is: " << item << endl;

	ListLinkedDouble<char> test_assigned;
	test_assigned = test_org;
	test_assigned.retrieve(0, item);
	cout << "test_assigned 0 is: " << item << endl;
	}
	else if (choose == "m")
	{
	ListLinkedSimple<char> test;

	test.testInput();
	}
	else if (choose == "q") break;
	}
	*/
}
void testQueueLinked()
{
	// SETTING 4: FOR QueueLinked.cpp

	/*
	QueueLinked<char> test;
	char item;
	test.append('a');
	cout << "a appended" << endl;
	test.append('k');
	cout << "k appended" << endl;
	test.retrieve(item);
	cout << item << " retrieved before serve" << endl;
	test.serve();
	test.retrieve(item);
	cout << item << " retrieved after serve" << endl;
	*/
}
void testQueueLinkedExtended()
{
	// SETTING 5: FOR QueueLinkedExtended.cpp

	/*
	QueueLinkedExtended<char> test, assigned;
	char item;
	test.append('a');
	cout << "a appended" << endl;
	test.append('k');
	cout << "k appended" << endl;
	QueueLinkedExtended<char> copy(test);
	assigned = test;
	test.retrieve(item);
	cout << item << " retrieved before serve from org" << endl;
	test.serve();
	test.retrieve(item);
	cout << item << " retrieved after serve from org" << endl;

	assigned.retrieve(item);
	cout << item << " retrieved before serve from assigned" << endl;
	assigned.serve();
	assigned.retrieve(item);
	cout << item << " retrieved after serve from assigned" << endl;

	copy.retrieve(item);
	cout << item << " retrieved before serve from copy" << endl;
	copy.serve();
	copy.retrieve(item);
	cout << item << " retrieved after serve from copy" << endl;
	*/
}
void testStackLinked()
{
	// SETTING 6: FOR StackLinked.cpp

	/*
	StackLinked<char> test;
	char item;
	test.push('a'); cout << "a pushed" << endl;
	test.push('k'); cout << "k pushed" << endl;
	test.top(item); cout << item << " on top before pop" << endl;
	test.pop();
	test.top(item); cout << item << " on top after pop" << endl;
	*/
}