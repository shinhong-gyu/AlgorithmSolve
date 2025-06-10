#include <iostream>
#include <vector>
#include <queue> // stack 대신 queue 사용
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K, X;
	cin >> N >> M >> K >> X;

	vector<vector<int>> edges(N+1);
	vector<int> minDistance(N+1, -1);

	queue<pair<int, int>> q;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		edges[a].push_back(b);
	}

	vector<int> citys;

	minDistance[X] = 0;
	q.push(make_pair(X, 0));

	while (!q.empty())
	{
		int node = q.front().first;
		int depth = q.front().second;
		q.pop();

		if (depth >= K) {
			continue;
		}

		for (int neighbor : edges[node]) 
		{
			if (minDistance[neighbor] == -1) 
			{
				minDistance[neighbor] = depth + 1;
				q.push(make_pair(neighbor, depth + 1));
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if(minDistance[i] == K)
		{
			citys.push_back(i);
		}
	}

	sort(citys.begin(), citys.end());

	if (citys.empty())
	{
		cout << -1;
	}
	else
	{
		for (int city : citys)
		{
			cout << city << "\n";
		}
	}

	return 0;
}