#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sudoku[9][9];

bool rowCheck[9][10];
bool colCheck[9][10];
bool squareCheck[9][10];

int nthSquare(int row, int col)
{
	return row / 3 * 3 + col / 3;
}

bool solve_sudoku(int row, int col)
{
	if (col == 9)
	{
		return solve_sudoku(row + 1, 0);
	}

	if (row == 9)
	{
		return true;
	}


	if (sudoku[row][col] != 0)
	{
		return solve_sudoku(row, col + 1);
	}

	for (int i = 1; i <= 9; i++)
	{
		if (!rowCheck[row][i] && !colCheck[col][i] && !squareCheck[nthSquare(row, col)][i])
		{
			rowCheck[row][i] = true;
			colCheck[col][i] = true;
			squareCheck[nthSquare(row, col)][i] = true;

			sudoku[row][col] = i;

			if (solve_sudoku(row, col + 1))
			{
				return true;
			}

			rowCheck[row][i] = false;
			colCheck[col][i] = false;
			squareCheck[nthSquare(row, col)][i] = false;

			sudoku[row][col] = 0;
		}

	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 9; i++)
	{
		string temp;
		getline(cin, temp);

		int j = 0;
		for (char c : temp)
		{
			sudoku[i][j++] = c - '0';
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int n = sudoku[i][j];
			if (n != 0)
			{
				rowCheck[i][n] = true;
				colCheck[j][n] = true;
				squareCheck[nthSquare(i, j)][n] = true;
			}
		}
	}

	solve_sudoku(0, 0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << sudoku[i][j];
		}
		cout << "\n";
	}
}