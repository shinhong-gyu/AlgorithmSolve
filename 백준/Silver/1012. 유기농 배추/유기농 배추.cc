#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int M, N;

bool IsValidLocation(int y, int x)
{
	if (y >= N || x >= M || x < 0 || y < 0)
	{
		return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	int K;

	while (T--)
	{
		cin >> M >> N >> K;

		vector<vector<int>> field(N, vector<int>(M, 0));
		stack<pair<int, int>> s;

		for (int i = 0; i < K; i++)
		{
			int x, y;
			cin >> x >> y;

			field[y][x] = 1;
		}

		int count = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (field[i][j] == 1)
				{
					s.push({ i,j });
					count++;

					while (!s.empty())
					{
						int row = s.top().first;
						int col = s.top().second;

						field[row][col] = 0;

						s.pop();

						if (IsValidLocation(row - 1, col) && field[row - 1][col] == 1)
						{
							s.push({ row - 1, col });
						}
						if (IsValidLocation(row + 1, col) && field[row + 1][col] == 1)
						{
							s.push({ row + 1, col });
						}
						if (IsValidLocation(row, col - 1) && field[row][col - 1] == 1)
						{
							s.push({ row, col - 1 });
						}
						if (IsValidLocation(row, col + 1) && field[row][col + 1] == 1)
						{
							s.push({ row, col + 1 });
						}
					}
				}
			}
		}
		cout << count << endl;
	}
}