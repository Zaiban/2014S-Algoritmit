#include "List.cpp"
#include <iostream>
#include <string>
using std::cout; using std::endl;

int main()
{
	// There are 3 test settings for each of "List.cpp", "ListLinkedSimple.cpp", "ListLinkedDouble.cpp"
	// Uncomment ONLY one of the following settings at time 
	// (depending on what class you have currently #included):

	// SETTING 1: FOR List.cpp
	

	List<char> test;
	test.testInput();
	
	
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


	system("pause");
	return 0;
}