#include <iostream>
#include <vector>

using namespace std;

vector<vector<char>> board(50, vector<char>(50));

int makeChessBoard(int x, int y)
{
	int cntWB = 0;
	int cntBW = 0;
	for (int i = x; i < x + 8; i++)
	{
		for (int j = y; j < y + 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				if (board[i][j] == 'W')
				{
					cntBW++;
				}
			}
			else
			{
				if (board[i][j] == 'B')
				{
					cntBW++;
				}
			}
		}
	}

	for (int i = x; i < x + 8; i++)
	{
		for (int j = y; j < y + 8; j++)
		{
			if ((i + j) % 2 == 0)
			{
				if (board[i][j] == 'B') cntWB++;
			}
			else
			{
				if (board[i][j] == 'W') cntWB++;
			}
		}
	}
	return min(cntWB, cntBW);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int least = 64;

	int N, M;

	cin >> N >> M;


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}


	for (int i = 0; i <= N - 8; i++)
	{
		for (int j = 0; j <= M - 8; j++)
		{
			int temp = makeChessBoard(i, j);
			least = min(temp, least);
		}
	}
	cout << least << endl;
}