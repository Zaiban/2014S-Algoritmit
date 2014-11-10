#include <iostream>

#include "Postfix_calculator.h"

using std::cin; using std::cout; using std::endl;

int main(int argc, char* argv[])
{
	bool prompt = false;
	if (argc == 2)
	if (strcmp(argv[1], "-p") == 0)
		prompt = true;

	Postfix_calculator test;
	test.introduction();

	if (prompt)
		test.askPrompt();
	else
		test.askInput();

	
	



	system("pause");
	return 0;
}