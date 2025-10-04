#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;



int N, M;
int map[501][501];

bool InRange(int i, int j)
{
	return i >= 0 && j >= 0 && i < N && j < M;
}

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int sum = 0;

bool visited[501][501] = { false };

void DFS(int i, int j, int depth, int cur)
{
	if (depth == 4)
	{
		sum = max(sum, cur);
		return;
	}

	for (int k = 0; k < 4; k++)
	{
		int nextY = i + dy[k];
		int nextX = j + dx[k];

		if (InRange(nextY, nextX) && !visited[nextY][nextX])
		{
			visited[nextY][nextX] = true;
			DFS(nextY, nextX, depth + 1, cur + map[nextY][nextX]);
			visited[nextY][nextX] = false;
		}
	}
}

void TShape(int r, int c)
{
	int curMax = -1;
	for (int i = 0; i < 4; i++)
	{
		int cur = map[r][c];

		bool IsValid = true;

		for (int j = 0; j < 4; j++)
		{
			if (i == j)
			{
				continue;
			}

			int nextY = r + dy[j];
			int nextX = c + dx[j];

			if (!InRange(nextY, nextX))
			{
				IsValid = false;
				break;
			}

			cur += map[nextY][nextX];

		}

		if (IsValid)
		{
			curMax = max(cur, curMax);
		}
	}

	sum = max(curMax, sum);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visited[i][j] = true;
			DFS(i, j, 1, map[i][j]);
			visited[i][j] = false;
			TShape(i, j);
		}
	}

	cout << sum;
}