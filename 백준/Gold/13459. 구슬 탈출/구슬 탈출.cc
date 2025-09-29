#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct State
{
	int rx, ry, bx, by, count;
};

char map[11][11];

State start;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool bfs()
{
	bool visited[11][11][11][11] = { false };

	queue<State> q;

	q.push(start);
	visited[start.ry][start.rx][start.by][start.bx] = true;

	while (!q.empty())
	{
		State cur = q.front();

		q.pop();

		if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O')
		{
			if (cur.count <= 10)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			// 빨간 공 처리
			State next;

			next.rx = cur.rx;
			next.ry = cur.ry;
			next.bx = cur.bx;
			next.by = cur.by;
			next.count = cur.count + 1;

			while (1)
			{
				if (map[next.ry + dy[i]][next.rx + dx[i]] != '#' && map[next.ry][next.rx] != 'O')
				{
					next.rx += dx[i];
					next.ry += dy[i];
				}
				else
				{
					break;
				}
			}
			// 파란 공 처리
			while (1)
			{
				if (map[next.by + dy[i]][next.bx + dx[i]] != '#' && map[next.by][next.bx] != 'O')
				{
					next.bx += dx[i];
					next.by += dy[i];
				}
				else
				{
					break;
				}
			}

			// 둘이 겹쳤을 때 처리
			if (next.bx == next.rx && next.ry == next.by)
			{
				long long deltaR = (next.rx - cur.rx) * (next.rx - cur.rx) + (next.ry - cur.ry) * (next.ry - cur.ry);
				long long deltaB = (next.bx - cur.bx) * (next.bx - cur.bx) + (next.by - cur.by) * (next.by - cur.by);

				if (map[next.ry][next.rx] != 'O')
				{
					// 움직인 거리가 더 먼 구슬을 한 칸 뒤로 보냄
					if (deltaR > deltaB)
					{
						next.rx -= dx[i];
						next.ry -= dy[i];
					}
					else
					{
						next.bx -= dx[i];
						next.by -= dy[i];
					}
				}
				else
				{
					continue;
				}
			}

			// 방문한적 없는 상태라면 q에 push
			if (!visited[next.ry][next.rx][next.by][next.bx])
			{
				q.push(next);
				visited[next.ry][next.rx][next.by][next.bx] = true;
			}
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'R')
			{
				start.rx = j;
				start.ry = i;
			}
			else if (map[i][j] == 'B')
			{
				start.bx = j;
				start.by = i;
			}
		}
	}

	cout << bfs();

	
}