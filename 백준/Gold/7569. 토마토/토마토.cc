#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Point
{
	int z;
	int y;
	int x;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, H;
	cin >> N >> M >> H;

	vector<vector<vector<int>>> storage(H, vector<vector<int>>(M, vector<int>(N)));


	queue<pair<Point, int>> q;
	int zeroCount = 0;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < N; k++)
			{
				cin >> storage[i][j][k];
				if (storage[i][j][k] == 1)
				{
					q.push({ {i,j,k},0 });
				}
				else if (storage[i][j][k] == 0)
				{
					zeroCount++;
				}
			}
		}
	}

	int dx[6] = { -1,1,0,0,0,0 };

	int dy[6] = { 0,0,-1,1,0,0 };

	int dz[6] = { 0,0,0,0,-1,1 };

	bool bCan = false;
	int answer = 0;
	int day = 0;
	while (!q.empty())
	{
		Point cur = q.front().first;
		day = q.front().second;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nz = cur.z + dz[i];
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && nz >= 0 && nz < H)
			{
				if (storage[nz][ny][nx] == 0)
				{
					storage[nz][ny][nx] = 1;
					zeroCount--;
					q.push({ {nz,ny,nx},day + 1 });
					answer = day + 1;
				}
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