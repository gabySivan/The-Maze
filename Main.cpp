#include "Maze.h"
#include <stdlib.h>



int main()
{
	int col, row;

	do
	{
		cout << "Please enter how many cols will be in your maze (must be odd number between 0-80)" << endl;
		cin >> col;
		cout << "Please enter how many rows will be in your maze (must be odd number between 0-25)" << endl;
		cin >> row;

	} while (col%2 == 0 || row%2 ==0);
	Maze maze(col, row);
	maze.showMaze();

	maze.createMaze();
	maze.showMaze();




}