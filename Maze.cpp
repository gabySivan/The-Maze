#include "Maze.h"

Maze::Maze(int col, int row) : m_stack()
{
	int currCol;
	setCol(col);
	setRow(row);
	m_mat = new char*[m_col];
	for (currCol = 0; currCol < m_col; currCol++)
	{
		m_mat[currCol] = new char[m_row];
	}
	initializMat();
}

Maze::~Maze()
{
	int col;
	for (col = 0; col < m_col; col++)
	{
		delete[] m_mat[col];
	}
	delete[]m_mat;
}

void Maze::setCol(int col)
{
	m_col = col;
}

void Maze::setRow(int row)
{
	m_row = row;
}

void Maze::initializMat()
{
	int col, row;
	for (col = 0; col < m_col; col++)
	{
		for (row = 0; row < m_row; row++)
		{
			if (col % 2 == 0)
			{
				m_mat[col][row] = '*';
			}
			else
			{
				if (row % 2 == 0)
				{
					m_mat[col][row] = '*';
				}
				else
				{
					m_mat[col][row] = '$';
				}
			}
		}

	}
	m_mat[0][1] = ' ';//Maze entrance
	m_mat[m_col - 1][m_row - 2] = ' ';//Maze exit
}

void Maze::createMaze()
{
	Point point(1, 1);
	m_stack.Push(point);
	Point nextCell;
	Point currCell;
	int wallCol;
	int wallRow;

	while (!(m_stack.IsEmpty()))
	{
		currCell = m_stack.Pop();
		updateCell(currCell.getX(), currCell.getY(), ' ');
		if (availableNeighborExist(currCell))
		{
			nextCell = chooseNeighbor(currCell);
			wallCol = (currCell.getX() + nextCell.getX())/2;
			wallRow = (currCell.getY() + nextCell.getY()) / 2;
			updateCell(wallCol, wallRow, ' ');

			m_stack.Push(currCell);
			m_stack.Push(nextCell);
		}
		else
		{
			m_stack.Pop();
		}
	}
}

bool Maze::availableNeighborExist(const Point & currPoint)
{
	int count = 0;
	int colNum, rowNum, currCol, currRow ;
	currCol = currPoint.getX();
	currRow = currPoint.getY();
	
	if (currCol < m_col - 2 && m_mat[currCol +2][currRow] == '$')
	{
		count++;
	}
	if (currRow < m_row - 2 && m_mat[currCol][currRow+2] == '$')
	{
		count++;
	}
	if (currCol > 1 && m_mat[currCol - 2][currRow] == '$')
	{
		count++;
	}
	if (currRow > 1 && m_mat[currCol][currRow - 2] == '$')
	{
		count++;
	}
	return count;
}

Point  Maze::chooseNeighbor(Point & currCell)
{
	char left = ' ', down = ' ', right = ' ', up = ' ';
	int currCol = currCell.getX();
	int currRow = currCell.getY();
	if(currCol > 1)
		left = m_mat[currCol - 2][currRow];
	if(currCol < m_col-2)
		right = m_mat[currCol + 2][currRow];
	if (currRow < m_row - 2)
		down = m_mat[currCol][currRow+2];
	if(currRow > 1)
		up = m_mat[currCol][currRow - 2];

	int choise;
	int arr[4];
	int arrSize = 0;

	if (left == '$')
		arr[arrSize++] = 1;
	if (down == '$')
		arr[arrSize++] = 2;
	if (right == '$')
		arr[arrSize++] = 3;
	if (up == '$')
		arr[arrSize++] = 4;

	srand((unsigned)time(NULL));
	choise = rand() % arrSize;

	if (arr[choise] == 1)
	{
		return Point(currCol - 2, currRow);
	}
	else if (arr[choise] == 2)
	{
		return Point(currCol, currRow + 2);
	}
	else if (arr[choise] == 3)
	{
		return Point(currCol + 2, currRow);
	}
	else //(arr[choise] == 4)
	{
		return Point(currCol, currRow - 2);
	}
}

void Maze::updateCell(int col, int row, char c)
{
	m_mat[col][row] = c;
}

void Maze::showMaze()
{
	int col, row;
	for (row = 0; row < m_row; row++)
	{
		for (col = 0; col < m_col; col++)
		{
			cout << m_mat[col][row] << " ";
		}
		cout << endl;
	}
}




