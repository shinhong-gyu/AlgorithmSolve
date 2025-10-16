#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char map[101][101];


int N, M;

struct Point
{
	int y, x;
};

vector<Point> wolf;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void BFS()
{
	queue<Point> q;

	vector<vector<bool>> visited(N, vector<bool>(M, false));

	for (const auto& p : wolf)
	{
		q.push(p);

		visited[p.y][p.x] = true;
	}

	while (!q.empty())
	{
		int curY = q.front().y;
		int curX = q.front().x;

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = curY + dy[i];
			int nextX = curX + dx[i];

			char topo = map[nextY][nextX];

			if (topo != '#')
			{
				if (topo == '+')
				{
					int slideY = nextY + dy[i];
					int slideX = nextX + dx[i];

					while (map[slideY][slideX] == '+' && (slideY >= 0 && slideY < N && slideX >= 0 && slideX < M))
					{
						slideY = slideY + dy[i];
						slideX = slideX + dx[i];
					}

					if (map[slideY][slideX] == '#')
					{
						slideY = slideY - dy[i];
						slideX = slideX - dx[i];
					}

					if (!visited[slideY][slideX])
					{
						q.push({ slideY,slideX });
						visited[slideY][slideX] = true;

						if (map[slideY][slideX] == 'P')
						{
							map[slideY][slideX] = '.';
						}
					}
				}
				else
				{
					if (!visited[nextY][nextX])
					{
						q.push({ nextY,nextX });
						visited[nextY][nextX] = true;

						if (map[nextY][nextX] == 'P')
						{
							map[nextY][nextX] = '.';
						}
					}
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

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'W')
			{
				wolf.push_back({ i,j });
			}

			else if (map[i][j] == '.')
			{
				map[i][j] = 'P';
			}
		}
	}

	BFS();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}
}