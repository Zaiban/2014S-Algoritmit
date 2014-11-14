#include "Life.h"
#include <string>
#include <fstream>


void Life::initialize(int maxrow_input, int maxcol_input){

	maxrow_user = maxrow_input;
	maxcol_user = maxcol_input;
	std::string inputRow; // Saves the user input at initialization

	unsigned row, col;
	for (row = 0; row < MAXROW; row++)
		for (col = 0; col < MAXCOL; col++)
			grid[row][col] = 0;

	if (load())
		return;

	cout << "Give the initial starting arrangement of living cells by inputting the letter x" << endl;
	
	for (row = 0; row < maxrow_user; row++)
	{
		cout << "Input row " << row << ": ";	
		std::getline(cin, inputRow); // Read the user input
		if (inputRow.size() < maxcol_user) // Make sure inputRow is large enough
			for (unsigned i = inputRow.size(); i < maxcol_user; i++)
				inputRow.push_back(' ');
		for (col = 0; col < maxcol_user; col++)
		{
			if (inputRow.at(col) == 'x')
				grid[row][col] = 1;
		}
	}

}

void Life::print(){

	unsigned row, col;
	cout << "\nThe current Life configuration is:" << endl;
	for (row = 0; row < maxrow_user; row++){
		for (col = 0; col < maxcol_user; col++)
			if (grid[row][col] == 1) cout << '*';
			else cout << ' ';
			cout << endl;
	}
	cout << endl;
}

void Life::update(){

	unsigned row, col;
	int new_grid[MAXROW][MAXCOL];

	for (row = 0; row < maxrow_user; row++)
		for (col = 0; col < maxcol_user; col++)
			switch (neighbor_count(row, col)){

			case 2:
				new_grid[row][col] = grid[row][col];
				break;
			case 3:
				new_grid[row][col] = 1;
				break;
			default:
				new_grid[row][col] = 0;
		}

	for (row = 1; row < maxrow_user; row++)
		for (col = 1; col < maxcol_user; col++)
			grid[row][col] = new_grid[row][col];
}

int Life::neighbor_count(int row, int col){

	int i, j;
	int count = 0;

	int limit_up = 1, limit_down = 1, limit_left = 1, limit_right = 1;
	if (row == 0)
		limit_up = 0;
	if (row == maxrow_user - 1)
		limit_down = 0;
	if (col == 0)
		limit_left = 0;
	if (col == maxcol_user - 1)
		limit_right = 0;

	for (i = row - limit_up; i <= row + limit_down; i++)
		for (j = col - limit_left; j <= col + limit_right; j++)
		{
		count += grid[i][j];
		}

	count -= grid[row][col];

	return count;

}
void Life::save()
{
	std::ofstream file;
	file.open("saved.txt");
	int row, col;
	for (row = 0; row < MAXROW; row++)
	{
		for (col = 0; col < MAXCOL; col++)
			file << grid[row][col];
		file << "\n";
	}
	file.close();
}
bool Life::load()
{
	char answer = '0';
	cin.ignore();
	std::ifstream file;
	file.open("saved.txt");
	if (file.is_open())
	{
		while (answer != 'y' && answer != 'n')
		{
			cout << "Do you want to load a previously saved game data?(y/n) " << endl;
			cin >> answer;

			if (answer == 'y')
			{
				unsigned row, col;
				std::string rowString;

				row = 0;
				while (getline(file, rowString))
				{
					for (col = 0; col < maxcol_user; col++)
						grid[row][col] = rowString.at(col) - '0';
					row++;
				}
				file.close();
				return true;
			}
		}
	}

	return false;
}