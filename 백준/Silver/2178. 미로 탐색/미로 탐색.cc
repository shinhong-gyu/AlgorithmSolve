#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Point
{
	Point(int xParam, int yParam) { this->x = xParam; this->y = yParam; }
	int x;
	int y;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> maze(N, vector<int>(M));

	vector<vector<bool>> visit(N, vector<bool>(M, false));

	int j = 0;

	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		for (auto c : temp)
		{
			maze[i][j++] = c - '0';
		}
		j = 0;
	}

	queue<pair<Point, int>> q;

	Point start = { 0,0 };
	q.push(make_pair(start, 1));

	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };

	while (!q.empty())
	{
		Point current = q.front().first;
		int depth = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			Point target = Point(current.x + dx[i], current.y + dy[i]);

			if (target.x == M - 1 && target.y == N - 1)
			{
				cout << depth + 1;
				return 0;
			}

			if ((target.x >= 0 && target.x < M) && (target.y >= 0 && target.y < N) && visit[target.y][target.x] == false)
			{
				if (maze[target.y][target.x] == 1)
				{
					q.push(make_pair(target, depth + 1));
					visit[target.y][target.x] = true;
				}
			}
		}
	}
}