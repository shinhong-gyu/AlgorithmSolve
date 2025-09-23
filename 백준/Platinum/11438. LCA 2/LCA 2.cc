#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> edges;
vector<int> depth;
vector<vector<int>> parent;

void BFS()
{
	queue<pair<int, int>> q;

	q.push({ 1,0 });

	vector<bool> visited(N + 1);

	visited[1] = true;

	while (!q.empty())
	{
		int cur = q.front().first;
		int d = q.front().second;

		q.pop();

		for (int n : edges[cur])
		{
			if (!visited[n])
			{
				q.push({ n,d + 1 });
				depth[n] = d + 1;
				visited[n] = true;
				parent[0][n] = cur;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	edges.resize(N + 1);

	parent.resize(21, vector<int>(N + 1));

	depth.resize(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		int p, c;
		cin >> p >> c;

		edges[c].push_back(p);
		edges[p].push_back(c);
	}

	BFS();

	int kMax = 0;

	int temp = 1;

	while (temp <= N)
	{
		temp <<= 1;
		kMax++;
	}

	for (int i = 1; i <= kMax; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}

	int M;
	cin >> M;

	while (M--)
	{
		int a, b;
		cin >> a >> b;

		if (depth[a] > depth[b])
		{
			int temp = a;
			a = b;
			b = temp;
		}

		for (int k = kMax; k >= 0; k--)
		{
			if (pow(2, k) <= depth[b] - depth[a])
			{
				if (depth[a] <= depth[parent[k][b]])
				{
					b = parent[k][b];
				}
			}
		}

		for (int k = kMax; k >= 0 && a != b; k--)
		{
			if (parent[k][a] != parent[k][b])
			{
				a = parent[k][a];
				b = parent[k][b];
			}
		}

		int LCA = a;

		if (a != b)
		{
			LCA = parent[0][LCA];
		}

		cout << LCA << "\n";
	}
}