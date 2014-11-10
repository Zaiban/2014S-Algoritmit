#include "utility.h"
#include "life.h"

void instructions();

int main()  //  Program to play Conway's game of Life.
/*
Pre:  The user supplies an initial configuration of living cells.
Post: The program prints a sequence of pictures showing the changes in
the configuration of living cells according to the rules for
the game of Life.
Uses: The class Life and its methods initialize(), print(), and update().
The functions  instructions(),  user_says_yes().
*/

{
	int input_rows = 0, input_columns = 0;

	Life configuration;

	while (input_rows < 5 || input_rows > 30)
	{
		cout << "Give the amount of rows for the area (5-30) ";
		cin >> input_rows;
	}

	while (input_columns < 5 || input_columns > 75)
	{
		cout << "Give the amount of columns for the area (5-75) ";
		cin >> input_columns;
	}

	instructions();
	configuration.initialize(input_rows, input_columns);
	configuration.print();
	cout << "Continue viewing new generations? " << endl;
	while (user_says_yes()) {
		configuration.update();
		configuration.print();
		cout << "Continue viewing new generations? " << endl;
	}
	cout << "Do you want to save the game?" << endl;
	if (user_says_yes())
		configuration.save();

}

void instructions()
/*
Pre:  None.
Post: Instructions for using the Life program have been printed.
*/

{
	cout << "Welcome to Conway's game of Life." << endl;
	cout << "This game uses a grid of size "
		<< "??" << " by " << "??" << " in which" << endl;
	cout << "each cell can either be occupied by an organism or not." << endl;
	cout << "The occupied cells change from generation to generation" << endl;
	cout << "according to the number of neighboring cells which are alive."
		<< endl;
}