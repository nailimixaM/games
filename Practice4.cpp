// An m x n grid Connect 4 game (human-human)

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

const int gridHeight = 8;
const int gridWidth = 8;
char grid[gridWidth][gridHeight];
int numbs[gridWidth];
void initialise();
void player();
void testMove();
void testWin();
void testPlayAgain();
int victory = 0, draw = 0, go = 0, caller = 0, index = 0;

int main()
{
	initialise();
	player();
	testPlayAgain();
	system("Pause");
	return 0;
}

void initialise()
{
	cout << "Initialising Connect 4 grid..." << endl;
	for (int j = 0; j < gridHeight; j++)
	{
		for (int i = 0; i < gridWidth; i++)
		{
			grid[i][j] = '*';
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < gridWidth; i++)
	{
		numbs[i] = i;
		cout << numbs[i] << " ";
	}
	cout << endl;
	victory = 0;
	draw = 0;
	cout << "Initialise succeeded." << endl;
}

void player()
{
	if (caller % 2 == 0)
	{
		cout << "Player 1 move:" << endl;
	}
	else cout << "Player 2 move:" << endl;

	cin >> go;
	testMove();

	if (caller % 2 == 0)
	{
		grid[go][index] = 'X';
	}
	else grid[go][index] = 'O';
	
	for (int j = 0; j < gridHeight; j++)
	{
		for (int i = 0; i < gridWidth; i++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < gridWidth; i++)
	{
		numbs[i] = i;
		cout << numbs[i] << " ";
	}
	cout << endl;
	testWin();
}

void testMove()
{
	if (go > gridWidth - 1|| go < 0)
	{
		cout << "Error, please enter valid move" << endl;
		player();
	}
	int i = gridHeight - 1;
	while (grid[go][i] == 'X' || grid[go][i] == 'O')
	{
		i--;
		if (i < 0)
		{
			cout << "Error, please enter valid move" << endl;
			player();
		}
	}
	index = i;
}

void testWin()
{
	//Check vertical
	if (index < gridHeight - 3)
	{			
		if (grid[go][index] == grid[go][index + 1] && grid[go][index + 1] == grid[go][index + 2] && grid[go][index + 2] == grid[go][index + 3])
		{
			victory = 1;
		}
	}

	//Check horizontal
	for (int i = go - 3; i < go + 1; i++)
	{
		if (i >= 0 && i < gridWidth - 3 && grid[i][index] == grid[i + 1][index] && grid[i + 1][index] == grid[i + 2][index] && grid[i + 2][index] == grid[i + 3][index])
		{
			victory = 1;
		}
	}

	//Check diagonal (top left to bottom right)
	int index2 = index - 3;
	for (int i = go - 3; i < go + 1; i++)
	{
		if (i >= 0 && i < gridWidth - 3 && index2 >= 0)
		{
			if (grid[i][index2] == grid[i + 1][index2 + 1] && grid[i + 1][index2 + 1] == grid[i + 2][index2 + 2] && grid[i + 2][index2 + 2] == grid[i + 3][index2 + 3])
			{
				//cout << "Game is won (negative diag.)" << endl;
				victory = 1;
			}
		}
		index2++;
	}

	//Check diagonal (bottom left to top right)
	index2 = index + 3;
	for (int i = go - 3; i < go + 1; i++)
	{
		if (i >= 0 && i < gridWidth - 3 && index2 >= 0)
		{
			if (grid[i][index2] == grid[i + 1][index2 - 1] && grid[i + 1][index2 - 1] == grid[i + 2][index2 - 2] && grid[i + 2][index2 - 2] == grid[i + 3][index2 - 3])
			{
				//cout << "Game is won (positive diag.)" << endl;
				victory = 1;
			}
		}
		index2--;
	}

	//Check if all slots filled
	for (int i = 0; i < gridWidth; i++)
	{
		if (grid[i][0] != '*'){}
		else break;
		if (i == gridWidth - 1)
		{
			draw = 1;
		}
	}

	if (victory == 1)
	{
		if (caller % 2 == 0)
		{
			cout << "Player 1 wins!" << endl;
		}
		else cout << "Player 2 wins!" << endl;
	}
	else if (draw == 1)
	{
		cout << "Game is drawn!" << endl;
	}
	else
	{
		++caller;
		player();
	}
}

void testPlayAgain()
{
	cout << "Would you like to play another game? (yes/no)" << endl;
	string answer;
	cin >> answer;
	if (answer == "yes") main();
	else cout << "Goodbye." << endl;
}