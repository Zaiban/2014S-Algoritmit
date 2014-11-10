#pragma once
#include "Stack.h"

class Postfix_calculator
{
public:
	Postfix_calculator();
	~Postfix_calculator();

	// prints the welcome message
	void introduction();
	// takes a decimal number as input
	// the decimal number is then pushed on top of the stack
	// if the push fails, an error message is printed
	void pushNumber(Stack_entry);
	// takes an arithmetic operator (+-*/) as input
	// the arithmetic operation is then performed
	// if the operation fails, an error message is printed
	void operation(char);
	// prints the top of the stack
	void printTop();
	// asks console input for the calculator
	// until terminated by inputting the letter 'q' or 'Q'
	void askInput();
	// flips the position of the top 2 numbers on the stack
	void exchange();
	// sums all the items on the stack
	// leaves only the result on the stack
	void sum();
	// calculates the average of the items on the stack
	// leaves only the result on the stack
	void average();
	// reads one line of command parameters from the console
	void askPrompt();

private:
	Stack numbers_;
};