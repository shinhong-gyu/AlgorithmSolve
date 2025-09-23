#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


int N;
vector<vector<int>> edges;
vector<int> n_depth;
vector<int> parent;

void BFS()
{
	queue<pair<int, int>> q;

	q.push({ 1,0 });

	vector<bool> visited(N + 1, false);

	visited[1] = true;

	while (!q.empty())
	{
		int cur = q.front().first;
		int depth = q.front().second;

		q.pop();

		for (int n : edges[cur])
		{
			if (!visited[n])
			{
				q.push({ n,depth + 1 });
				n_depth[n] = depth + 1;
				parent[n] = cur;
				visited[n] = true;
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
	n_depth.resize(N + 1);
	parent.resize(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		int p, c;
		cin >> p >> c;

		edges[c].push_back(p);
		edges[p].push_back(c);

	}

	BFS();

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;


		if (n_depth[a] < n_depth[b])
		{
			int temp = a;
			a = b;
			b = temp;
		}

		while (n_depth[a] != n_depth[b])
		{
			a = parent[a];
		}

		while (a != b)
		{
			a = parent[a];
			b = parent[b];
		}

		cout << a << "\n";
	}
}