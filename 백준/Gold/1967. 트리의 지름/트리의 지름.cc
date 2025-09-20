#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

#define INF INT_MAX

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<vector<pair<int, int>>> edges(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;

		edges[A].push_back({ B, C });
		edges[B].push_back({ A, C });
	}

	vector<int> mDistance(N + 1, INF);
	vector<bool> visited(N + 1, false);

	queue<int> q;

	q.push(1);

	visited[1] = true;
	mDistance[1] = 0;

	while (!q.empty())
	{
		int cur = q.front();

		q.pop();

		for (auto p : edges[cur])
		{
			int next = p.first;
			int cost = p.second;

			if (!visited[next])
			{
				mDistance[next] = mDistance[cur] + cost;
				visited[next] = true;

				q.push(next);
			}
		}
	}

	fill(visited.begin(), visited.end(), false);

	int max_idx = max_element(mDistance.begin() + 1, mDistance.end()) - mDistance.begin();

	fill(mDistance.begin(), mDistance.end(), INF);

	q.push(max_idx);
	visited[max_idx] = true;
	mDistance[max_idx] = 0;


	while (!q.empty())
	{
		int cur = q.front();

		q.pop();

		for (auto p : edges[cur])
		{
			int next = p.first;
			int cost = p.second;

			if (!visited[next])
			{
				mDistance[next] = mDistance[cur] + cost;
				visited[next] = true;

				q.push(next);
			}
		}
	}

	cout << *max_element(mDistance.begin() + 1, mDistance.end());
}