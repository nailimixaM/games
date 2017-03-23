// Practice 3.cpp : A Human-Human Tic-Tac-Toe game

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

const int gridLength = 3;
char grid[gridLength][gridLength];
void player();
void testMove();
void testWin();
void initialise();
void testPlayAgain();
int moves[9];
int go = 0, caller = 0, victory = 0, draw = 0;

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
	cout << "Initialising tic-tac-toe grid..." << endl;
	for (int j = 0; j < gridLength; j++)
	{
		for (int i = 0; i < gridLength; i++)
		{
			grid[i][j] = '*';
		}
	}
	for (int j = 0; j < gridLength; j++)
	{
		for (int i = 0; i < gridLength; i++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 10; i++)
	{
		moves[i] = 0;
	}
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
		switch (go)
		{
		case 1: grid[0][0] = 'x';
			break;
		case 2: grid[1][0] = 'x';
			break;
		case 3: grid[2][0] = 'x';
			break;
		case 4: grid[0][1] = 'x';
			break;
		case 5: grid[1][1] = 'x';
			break;
		case 6: grid[2][1] = 'x';
			break;
		case 7: grid[0][2] = 'x';
			break;
		case 8: grid[1][2] = 'x';
			break;
		case 9: grid[2][2] = 'x';
			break;
		}
	}
	else
	{
		switch (go)
		{
		case 1: grid[0][0] = 'o';
			break;
		case 2: grid[1][0] = 'o';
			break;
		case 3: grid[2][0] = 'o';
			break;
		case 4: grid[0][1] = 'o';
			break;
		case 5: grid[1][1] = 'o';
			break;
		case 6: grid[2][1] = 'o';
			break;
		case 7: grid[0][2] = 'o';
			break;
		case 8: grid[1][2] = 'o';
			break;
		case 9: grid[2][2] = 'o';
			break;
		}
	}
	
	for (int j = 0; j < gridLength; j++)
	{
		for (int i = 0; i < gridLength; i++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	testWin();
}

void testMove()
{
	if (moves[go - 1] != 0)
	{
		cout << "Error: you can not play here, please try again." << endl;
		player();
	}
	else
	{
		moves[go - 1] = 1;
	}
}

void testWin()
{
	for (int i = 0; i < 3; i++)
	{
		//Test columns
		if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2] && grid[i][0] != '*')
		{
			victory = 1;
		}
		//Test rows
		if (grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i] && grid[0][i] != '*')
		{
			victory = 1;
		}
	}

	//Test diagonals
	for (int i = 0; i < 3; i = i + 2)
	{
		if (grid[i][0] == grid[1][1] && grid[1][1] == grid[2 - i][2] && grid[i][i] != '*')
		{
			victory = 1;
		}
	}

	//Test cells for unfilled ones
	draw = -1;
	while (draw == -1)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (grid[i][j] == '*') draw = 0;
			}
		}
		if (draw != 0) draw = 1;
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
	getline(cin, answer);
	string yes;
	if (!answer.compare(yes))
	{
		main();
	}
	else cout << "Goodbye." << endl;
}
	