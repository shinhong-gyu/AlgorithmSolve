#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int img[101][101] = { 0 };
int colorBlindImg[101][101] = { 0 };

struct Point
{
	Point(int y, int x) : y(y), x(x) {};

	int y;
	int x;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			char temp;
			cin >> temp;

			switch (temp)
			{
			case 'R':
				img[i][j] = 1;
				colorBlindImg[i][j] = 1;
				break;
			case 'G':
				img[i][j] = 2;
				colorBlindImg[i][j] = 1;
				break;
			case 'B':
				img[i][j] = 3;
				colorBlindImg[i][j] = 2;
				break;
			}
		}
	}

	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0, -1,1 };

	int preColor = -1;
	int preX = 0;
	int preY = 0;
	int areaCount = 0;

	vector<vector<bool>> visited(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			queue<Point> q;

			if (!visited[i][j] && (img[i][j] != preColor || (preX != j && preY != i)))
			{
				areaCount++;

				q.push(Point{ i,j });

				visited[i][j] = true;

				while (!q.empty())
				{
					int y = q.front().y;
					int x = q.front().x;

					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int curY = y + dy[k];
						int curX = x + dx[k];

						if (curY >= 0 && curY < N && curX >= 0 && curX < N)
						{
							if (!visited[curY][curX] && img[y][x] == img[curY][curX])
							{
								q.push(Point(curY, curX));
								visited[curY][curX] = true;
							}
						}
					}
				}

			}
			preColor = img[i][j];
			preX = j;
			preY = i;
		}
	}

	cout << areaCount << " ";

	for (int i = 0; i < N; i++)
	{
		visited[i].assign(N, false);
	}

	int blindAreaCount = 0;
	preColor = -1;
	preX = 0;
	preY = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			queue<Point> q;

			if (!visited[i][j] && (colorBlindImg[i][j] != preColor || (preX != j && preY != i)))
			{
				blindAreaCount++;

				q.push(Point{ i,j });

				visited[i][j] = true;

				while (!q.empty())
				{
					int y = q.front().y;
					int x = q.front().x;

					q.pop();

					for (int k = 0; k < 4; k++)
					{
						int curY = y + dy[k];
						int curX = x + dx[k];

						if (curY >= 0 && curY < N && curX >= 0 && curX < N)
						{
							if (!visited[curY][curX] && colorBlindImg[y][x] == colorBlindImg[curY][curX])
							{
								q.push(Point(curY, curX));
								visited[curY][curX] = true;
							}
						}
					}
				}

			}
			preColor = colorBlindImg[i][j];
			preX = j;
			preY = i;
		}
	}

	cout << blindAreaCount;
}