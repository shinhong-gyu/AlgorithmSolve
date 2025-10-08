#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

using namespace std;

int N, M, C;
int S_r, S_c;
int map[1001][1001];

struct Coord
{
	int y, x;
};

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int benefit[1000001] = { 0 };

void BFS()
{
	// 좌표, 빛 세기 
	queue<pair<Coord, int>> q;

	vector<vector<bool>> visited(N + 1, vector<bool>(M + 1, false));

	q.push({ {S_r,S_c},0 });
	visited[S_r][S_c] = true;

	while (!q.empty())
	{
		Coord cur = q.front().first;
		int intensity = q.front().second;
		q.pop();

		benefit[intensity] += map[cur.y][cur.x];

		for (int i = 0; i < 4; i++)
		{
			int nextY = cur.y + dy[i];
			int nextX = cur.x + dx[i];

			if (nextY >= 1 && nextY <= N && nextX >= 1 && nextX <= M)
			{
				if (map[nextY][nextX] != -1 && !visited[nextY][nextX])
				{
					q.push({ {nextY,nextX},intensity + 1 });
					visited[nextY][nextX] = true;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> C;

	cin >> S_r >> S_c;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}

	BFS();

	int answer = 0;

	int sum = 0;

	for (int i = 0; i <= N * M; i++)
	{
		sum += benefit[i];

		answer = max(sum - C * i, answer);
	}

	cout << answer;
}