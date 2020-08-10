#ifndef __MAZE_H
#define __MAZE_H

#include <time.h>
#include "Stack.h"
#include"Point.h"

class Maze
{
public:
	Maze(int col, int row);
	~Maze();

	void setCol(int col);//set col
	void setRow(int row);//set row
	void initializMat();//initializ mat
	
	void createMaze();
	void solveMaze() {};//TODO

	bool availableNeighborExist(const Point& currPoint);
	Point chooseNeighbor(Point& currCell);

	void updateCell(int col, int row, char c);

	void showMaze();

	

private:
	Stack m_stack;
	char** m_mat;
	int m_col;
	int m_row;


};


#endif // !__MAZE_H
