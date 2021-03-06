//   Adrian_Butler_N Queen Project

// ConsoleApplication20.cpp : Defines the entry point for the console application.
//
// First i made a two dimensional array and then i made different function for the problem so it would //easier and more organized.
// I started with creating a function that checks if the queen could be placed in that certain row/column. //then i wanted to check the 
// different diagonal and side of the two dimensional array. Then i created a function that would put the //queens and the two dimensional array
// and backtrack if needed. then i created another function to display the two dimensional array.

#include <iostream>
using namespace std;

int B[8][8];


// check if a queen can be placed on two dimensional array //
bool Safe(int row, int col)
{
	int i, x;
	for (i = 0; i < col; i++)
	{
		if (B[row][i])
			return false;
	}


	i = row;
	x = col;
	while (i >= 0 && x >= 0)
	{
		if (B[i][x])
		{
			return false;
		}
		i--; x--;

	}

	i = row;
	x = col;
	while (x >= 0 && i < 8)
	{
		if (B[i][x])
		{
			return false;
		}
		i++; x--;
	}
	return true;
}

//  placing the queen //
bool solve(int col)
{
	if (col >= 8)
		return true;
	for (int i = 0; i < 8; i++)
	{
		if (Safe(i, col))
		{
			B[i][col] = 1;
			if (solve(col + 1) == true)
				return true;
			B[i][col] = 0;
		}
	}
	return false;
}

void printSolution()
{
	for (int i = 0; i < 8; i++)
	{
		for (int x = 0; x < 8; x++)
			cout << B[i][x] << " ";
		cout << endl;
	}
}

// Backtracking //
int main()
{

	if (solve(0) == false)
	{
		cout << "try again" << endl;
		return false;
	}
	else {
		cout << "queens can be placed on the two dimensional array" << endl;
		printSolution();
		return true;
	}





	return 0;
}
