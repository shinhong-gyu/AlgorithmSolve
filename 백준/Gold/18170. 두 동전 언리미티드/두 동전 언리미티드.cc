#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


struct Coin
{
	int y, x;
};

struct State
{
	Coin c1, c2;
	int count = 0;
};

char map[21][21];
int N, M;
State start;

int BFS()
{
	queue<State> q;

	bool visited[21][21][21][21] = { false };

	visited[start.c1.y][start.c1.x][start.c2.y][start.c2.x] = true;

	q.push(start);

	while (!q.empty())
	{
		State cur = q.front();

		q.pop();

		// 위
		if (cur.c1.y - 1 >= 0 && cur.c2.y - 1 >= 0)
		{
			State next = cur;

			next.count = cur.count + 1;

			if (map[cur.c1.y - 1][cur.c1.x] != '#')
			{
				next.c1.y = cur.c1.y - 1;
				next.c1.x = cur.c1.x;
			}

			if (map[cur.c2.y - 1][cur.c2.x] != '#')
			{
				next.c2.y = cur.c2.y - 1;
				next.c2.x = cur.c2.x;
			}


			if (next.c1.y != next.c2.y || next.c1.x != next.c2.x)
			{
				if (!visited[next.c1.y][next.c1.x][next.c2.y][next.c2.x])
				{
					visited[next.c1.y][next.c1.x][next.c2.y][next.c2.x] = true;
					q.push(next);
				}
			}
		}
		else
		{
			if ((cur.c1.y - 1 < 0 && cur.c2.y - 1 >= 0) || (cur.c1.y - 1 >= 0 && cur.c2.y - 1 < 0))
			{
				return cur.count + 1;
			}
		}

		// 아래
		if (cur.c1.y + 1 < N && cur.c2.y + 1 < N)
		{
			State next = cur;

			next.count = cur.count + 1;

			if (map[cur.c1.y + 1][cur.c1.x] != '#')
			{
				next.c1.y = cur.c1.y + 1;
				next.c1.x = cur.c1.x;
			}

			if (map[cur.c2.y + 1][cur.c2.x] != '#')
			{
				next.c2.y = cur.c2.y + 1;
				next.c2.x = cur.c2.x;
			}
			if (next.c1.y != next.c2.y || next.c1.x != next.c2.x)
			{
				if (!visited[next.c1.y][next.c1.x][next.c2.y][next.c2.x])
				{
					visited[next.c1.y][next.c1.x][next.c2.y][next.c2.x] = true;
					q.push(next);
				}
			}
		}
		else
		{
			if ((cur.c1.y + 1 < N && cur.c2.y + 1 >= N) || (cur.c1.y + 1 >= N && cur.c2.y + 1 < N))
			{
				return cur.count + 1;
			}
		}

		// 오른쪽
		if (cur.c1.x + 1 < M && cur.c2.x + 1 < M)
		{
			State next = cur;

			next.count = cur.count + 1;

			if (map[cur.c1.y][cur.c1.x + 1] != '#')
			{
				next.c1.y = cur.c1.y;
				next.c1.x = cur.c1.x + 1;
			}

			if (map[cur.c2.y][cur.c2.x + 1] != '#')
			{
				next.c2.y = cur.c2.y;
				next.c2.x = cur.c2.x + 1;
			}

			if (next.c1.y != next.c2.y || next.c1.x != next.c2.x)
			{
				if (!visited[next.c1.y][next.c1.x][next.c2.y][next.c2.x])
				{
					visited[next.c1.y][next.c1.x][next.c2.y][next.c2.x] = true;
					q.push(next);
				}
			}
		}
		else
		{
			if ((cur.c1.x + 1 < M && cur.c2.x + 1 >= M) || (cur.c1.x + 1 >= M && cur.c2.x + 1 < M))
			{
				return cur.count + 1;
			}
		}

		// 왼쪽
		if (cur.c1.x - 1 >= 0 && cur.c2.x - 1 >= 0)
		{
			State next = cur;

			next.count = cur.count + 1;

			if (map[cur.c1.y][cur.c1.x - 1] != '#')
			{
				next.c1.y = cur.c1.y;
				next.c1.x = cur.c1.x - 1;
			}

			if (map[cur.c2.y][cur.c2.x - 1] != '#')
			{
				next.c2.y = cur.c2.y;
				next.c2.x = cur.c2.x - 1;
			}

			if (next.c1.y != next.c2.y || next.c1.x != next.c2.x)
			{
				if (!visited[next.c1.y][next.c1.x][next.c2.y][next.c2.x])
				{
					visited[next.c1.y][next.c1.x][next.c2.y][next.c2.x] = true;
					q.push(next);
				}
			}
		}
		else
		{
			if ((cur.c1.x - 1 < 0 && cur.c2.x - 1 >= 0) || (cur.c1.x - 1 >= 0 && cur.c2.x - 1 < 0))
			{
				return cur.count + 1;
			}
		}
	}

	return -1;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	bool a = false;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'o')
			{
				if (!a)
				{
					start.c1.y = i;
					start.c1.x = j;
					a = true;
				}
				else
				{
					start.c2.y = i;
					start.c2.x = j;
				}
			}
		}
	}

	cout << BFS();
}
