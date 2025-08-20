#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<bool>> colNumber(9, vector<bool>(10));
vector<vector<bool>> rowNumber(9, vector<bool>(10));
vector<vector<bool>> quadNumber(9, vector<bool>(10));

int sudoku[9][9];

int QuadSection(int i, int j)
{
	return (i / 3) * 3 + (j / 3);
}

bool SolveSudoKu(int row, int col)
{
	if (col == 9)
	{
		return SolveSudoKu(row + 1, 0);
	}

	if (row == 9)
	{
		return true;
	}

	if (sudoku[row][col] != 0)
	{
		return SolveSudoKu(row, col + 1);
	}

	for (int i = 1; i <= 9; i++)
	{
		if (!colNumber[col][i] && !rowNumber[row][i] && !quadNumber[QuadSection(row, col)][i])
		{
			colNumber[col][i] = true;
			rowNumber[row][i] = true;
			quadNumber[QuadSection(row, col)][i] = true;

			sudoku[row][col] = i;

			if (SolveSudoKu(row, col + 1))
			{
				return true;
			}

			colNumber[col][i] = false;
			rowNumber[row][i] = false;
			quadNumber[QuadSection(row, col)][i] = false;

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
		for (int j = 0; j < 9; j++)
		{
			int temp;
			cin >> temp;
			sudoku[i][j] = temp;

			if (temp != 0)
			{
				rowNumber[i][temp] = true;
				colNumber[j][temp] = true;
				quadNumber[QuadSection(i, j)][temp] = true;
			}

		}
	}

	SolveSudoKu(0, 0);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << sudoku[i][j] << " ";
		}

		cout << "\n";
	}
}