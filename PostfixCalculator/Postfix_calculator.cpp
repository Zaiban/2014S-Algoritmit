#include "Postfix_calculator.h"
#include <iostream>
#include <string>
#include <vector>
using std::cout; using std::cin; using std::endl; using std::string; 
using std::stod; using std::vector;
Postfix_calculator::Postfix_calculator()
{
}
Postfix_calculator::~Postfix_calculator()
{
}

void Postfix_calculator::introduction()
{
	cout << "Welcome to my great Postfix Calculator!!"
		<< "\nPlease follow the instructions carefully, for your own good." << endl;
}
void Postfix_calculator::pushNumber(Stack_entry item)
{
	if (numbers_.push(item) == overflow)
		cout << "Warning: Stack full, lost numbe" << endl;
}
void Postfix_calculator::operation(char op)
{
	Stack_entry p, q;
	if (numbers_.top(p) == underflow)
	{
		cout << "Stack is empty" << endl;
		return;
	}
	else{
		numbers_.pop();
		if (numbers_.top(q) == underflow)
		{
			cout << "Stack has just one entry" << endl;
			numbers_.push(p);
			return;
		}
	}
	switch (op){
	case '+':
		numbers_.pop();
		if (numbers_.push(q + p) == overflow)
			cout << "Warning: Stack full, lost result" << endl;
		break;
	case '-':
		numbers_.pop();
		if (numbers_.push(q - p) == overflow)
			cout << "Warning: Stack full, lost result" << endl;
		break;
	case '*':
		numbers_.pop();
		if (numbers_.push(q * p) == overflow)
			cout << "Warning: Stack full, lost result" << endl;
		break;
	case '/':
		numbers_.pop();
		if (numbers_.push(q / p) == overflow)
			cout << "Warning: Stack full, lost result" << endl;
		break;
	default:
		cout << "The operator is invalid. Please enter correct input." << endl;
		break;
	}
}
void Postfix_calculator::printTop()
{
	Stack_entry item;
	if (numbers_.top(item) == underflow)
		cout << "Stack is empty" << endl;
	else
		cout << "Top of the stack is: " << item << endl;
}
void Postfix_calculator::askInput()
{
	char input;
	Stack_entry item;
	
	while (true)
	{
		cout << "Please enter a valid command:" << endl
			<< "[?]push to stack   [=]print top" << endl
			<< "[+] [-] [*] [/]   are arithmetic operations" << endl
			<< "[x]exchange   [s]sum   [a]average" << endl
			<< "[Q]uit." << endl;

		cin.get(input);

		switch (input){
		case '?':
			cout << "Enter a number: ";
			
			cin >> item;
			pushNumber(item);
			break;
		case '=':
			printTop();
			break;
		case '+':
		case '-':
		case '*':
		case '/':
			operation(input);
			break;
		case 'q':
		case 'Q':
			cout << "Quitting.." << endl;
			return;
		case 'x':
		case 'X':
			exchange();
			break;
		case 's':
		case 'S':
			sum();
			break;
		case 'a':
		case 'A':
			average();
			break;
		default:
			cout << "Error: invalid input" << endl;
			break;
		}
		cin.clear();
		cin.ignore();
	}
}
void Postfix_calculator::exchange()
{
	Stack_entry q, p;
	if (numbers_.top(q) == underflow)
	{
		cout << "Stack is empty" << endl;
		return;
	}
	else
	{
		numbers_.pop();
		if (numbers_.top(p) == underflow)
		{
			cout << "Stack has just one entry" << endl;
			numbers_.push(q);
			return;
		}
		numbers_.pop();
		numbers_.push(q);
		numbers_.push(p);
	}
}
void Postfix_calculator::sum()
{
	if (numbers_.empty())
	{
		cout << "Stack is empty" << endl;
		return;
	}
	for (int i = 0; i < numbers_.getCount(); i++)
		operation('+');
}
void Postfix_calculator::average()
{
	if (numbers_.empty())
	{
		cout << "Stack is empty" << endl;
		return;
	}
	Stack_entry count = numbers_.getCount();
	sum();
	numbers_.push(count);
	operation('/');
}
void Postfix_calculator::askPrompt()
{
	// Stores the inputted line of commands
	string prompt;
	// Stores the invividual commands in a vector of strings
	vector <string>commands;

	Stack_entry number;
	char command;
	string::size_type pos = 0;

	cout << "Please type a line of commands" << endl;
	getline(cin, prompt);

	// Parse the prompt to multiple substrings
	// and store them to a vector
	for (unsigned i = 0; i < prompt.size(); i++)
	{
		command = prompt.at(i);
		if (prompt.at(i) == ' ' || i == prompt.size()-1 )
		{
			commands.push_back(prompt.substr(pos, i+1-pos));
			pos = i+1;
		}

	}
	// Take and perform the commands out of the vector, one by one
	for (unsigned i = 0; i < commands.size(); i++)
	{
		// Trim the last space out if it exists
		commands.at(i).erase(commands.at(i).find_last_not_of(" ")+1);
		// If the first character of command i is a number
		// this command is handled as pushNumber(Stack_entry);
		if (commands.at(i).at(0) >= '0' && commands.at(i).at(0) <= '9')
		{
			number = stod(commands.at(i));
			pushNumber(number);
		}
		// Else if the entry is exactly 1 character long
		// perform a switch case that executes commands
		else if (commands.at(i).size() == 1)
		{
			command = commands.at(i).at(0);
			switch (command){
			case '+':
			case '-':
			case '*':
			case '/':
				operation(command);
				break;
			case 'x':
			case 'X':
				exchange();
				break;
			case 's':
			case 'S':
				sum();
				break;
			case 'a':
			case 'A':
				average();
				break;
			}
		}
	}
	printTop();
}