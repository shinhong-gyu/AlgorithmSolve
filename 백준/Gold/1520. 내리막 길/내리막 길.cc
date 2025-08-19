#include <iostream>

using namespace std;

int map[501][501];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int dp[501][501];

int N, M;
static int path = 0;

int DFS(int r, int c)
{
	if (r == N && c == M)
	{
		return 1;
	}

	if (dp[r][c] != -1)
	{
		return dp[r][c];
	}

	dp[r][c] = 0;

	for (int i = 0; i < 4; i++)
	{
		int nextY = r + dy[i];
		int nextX = c + dx[i];

		if (nextY <= N && nextY > 0 && nextX <= M && nextX > 0)
		{
			if (map[nextY][nextX] < map[r][c])
			{
				dp[r][c] += DFS(nextY, nextX);
			}
		}
	}

	return dp[r][c];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	int answer = DFS(1, 1);
	cout << answer;
}