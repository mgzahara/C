#include <iostream>
#include <fstream>
#include "sudoku.h"
using namespace std;

Sudoku::Sudoku()
{
    int i, j;

    for (i = 0; i < 9; i++)
    {
	for (j = 0; j < 9; j++)
	    setElement(i,j,0);
    }
}

Sudoku::~Sudoku()
{
}

int Sudoku::getElement(int x, int y)
{
    if (x >= 0 && x < 9 && y >= 0 && y < 9)
	return(puzzle[x][y]);
    else
    {
	cout << "Sudoku::getElement - Requested array element does not exist";
	cout  << endl;
	return(0);
    }
}

void Sudoku::setElement(int x, int y, int value)
{
    if (x >= 0 && x < 9 && y >= 0 && y < 9)
	puzzle[x][y] = value;
    else
    {
	cout << "Sudoku::setElement - Requested array element does not exist"; 
	cout  << endl;
    }
}

bool Sudoku::solve()
{
    int row, col;
    bool cellFound = findOpenCell(row,col);


//    cout << "row:" << row << " col:" << col << endl;

    if(!cellFound)
    {
	return true;
    }

    for(int digit = 1; digit <= 9; digit++)
    {
	//cout << "digit: " << digit << endl;
	if(rowGood(row,digit) && colGood(col, digit) && squareGood(row,col,digit))
	{
	    puzzle[row][col] = digit;
	    if(solve())
	    {
		return true;
	    }
	    puzzle[row][col] = 0;  
	}
    }
  //  cout << "returning FALSE from SOLVE()\n";
    return false;
}

bool Sudoku::findOpenCell(int &row, int &col)
{
    for(row = 0; row < 9; row++)
    {
	for(col = 0; col < 9; col++)
	{
	    if(puzzle[row][col] == 0)
	    {
		//cout << "returned TRUE from findOpenCell()\n";
		return true;
	    }
	}
    }
//    cout << "returning TRUE from findOpenCell()\n";
    return false;
}

bool Sudoku::rowGood(int row, int guess)
{
    for(int i = 0; i < 9; i++)
    {
	if(puzzle[row][i] == guess)
	{
	 //   cout << "returning FALSE from rowGood()\n";
	    return false;
	}

    }
//    cout << "returning TRUE from rowGood()\n";
    return true;
}

bool Sudoku::colGood(int col, int guess)
{
    for(int i = 0; i < 9; i++)
    {
        if(puzzle[i][col] == guess)
        {
	   // cout << "returning FALSE from colGood()\n";
            return false;
        }

    }
//    cout << "returning TRUE from colGood()\n";
    return true;
}

bool Sudoku::squareGood(int row, int col, int guess)
{
    row = 3 * (row / 3);
    col = 3 * (col / 3);

    for(int i = 0; i < 3; i++)
    {
	for(int j = 0; j < 3; j++)
	{
	    if(puzzle[row + i][col + j] == guess)
	    {
		//cout << "returning FALSE from squareGood()\n";
		return false;
	    }
	}
    }
//    cout << "returning TRUE from squareGood()\n";
    return true;
}

void Sudoku::fillPuzzle(ifstream &infile)
{
    int i,j,value;

    for (i = 0; i < 9; i++)
    {
	for (j = 0; j < 9; j++)
	{
	    infile >> value;
	    setElement(i,j,value);
	}
	//cout << endl;
    }
}

void Sudoku::printPuzzle()
{
    int i, j;

    for (i = 0; i < 9; i++)
    {
	for (j = 0; j < 9; j++)
	    cout << getElement(i,j) << " ";
	cout << endl;
    }
}
