#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Point
{
	int y;
	int x;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> M >> N;

	vector<vector<int>> storage(N, vector<int>(M));


	queue<pair<Point, int>> q;
	int startX = 0;
	int startY = 0;
	int zeroCount = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> storage[i][j];
			if (storage[i][j] == 1)
			{
				q.push({ { i,j },0 });
			}
			else if (storage[i][j] == 0)
			{
				zeroCount++;
			}
		}
	}


	int dx[4] = { -1,1,0,0 };

	int dy[4] = { 0,0,-1,1 };

	bool bCan = false;
	int answer = 0;
	int day = 0;
	while (!q.empty())
	{
		Point cur = q.front().first;
		day = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && storage[ny][nx] == 0)
			{
				storage[ny][nx] = 1;
				zeroCount--;
				q.push({ { ny,nx },day + 1 });
				answer = day + 1;
			}
		}

		if (zeroCount == 0)
		{
			break;
		}
	}

	if (zeroCount == 0)
	{
		cout << answer << endl;
		return 0;
	}
	cout << -1 << endl;

}