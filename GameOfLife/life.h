#ifndef LIFE_H_
#define LIFE_H_

#include <iostream>
using std::cout; using std::cin; using std::endl;

const int MAXROW = 30, MAXCOL = 75;

class Life{
public:
	void initialize(int, int);
	void print();
	void update();
	void save(); // Saves the grid to file saved.txt
	bool load(); // Asks if user wants game loaded from saved.txt, TRUE if file is loaded

private:
	int grid[MAXROW][MAXCOL];
	unsigned maxrow_user;
	unsigned maxcol_user;

	int neighbor_count(int row, int col);
};

#endif