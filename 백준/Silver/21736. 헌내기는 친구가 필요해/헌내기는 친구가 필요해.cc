#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point
{
	int y = 0;
	int x = 0;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, count = 0;
	cin >> N >> M;

	queue<Point> q;
	vector<vector<char>> campus(N, vector<char>(M));
	vector<vector<bool>> check(N, vector<bool>(M));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> campus[i][j];
			if (campus[i][j] == 'I') q.push({ i,j });
		}
	}

	while (!q.empty())
	{
		Point cur = q.front();
		q.pop();

		int x = cur.x;
		int y = cur.y;

		if (campus[y][x] == 'P') count++;

		if (y + 1 < N && check[y + 1][x] == false && campus[y + 1][x] != 'X')
		{
			check[y + 1][x] = true;
			q.push({ y + 1,x });
		}
		if (y - 1 >= 0 && check[y - 1][x] == false && campus[y - 1][x] != 'X')
		{

			check[y - 1][x] = true;
			q.push({ y - 1,x });
		}
		if (x + 1 < M && check[y][x + 1] == false && campus[y][x + 1] != 'X')
		{
			check[y][x + 1] = true;
			q.push({ y,x + 1 });
		}
		if (x - 1 >= 0 && check[y][x - 1] == false && campus[y][x - 1] != 'X')
		{
			check[y][x - 1] = true;
			q.push({ y,x - 1 });
		}
	}
	if (count > 0)
	{
		cout << count << endl;
	}
	else
	{
		cout << "TT" << endl;
	}
}