#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct Info
{
	int city, cost;
};


struct Compare
{
	bool operator() (const Info& p1, const Info& p2)
	{
		return p1.cost > p2.cost;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<pair<int, int>>> edges(N + 1);

	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;

		edges[A].push_back({ B,C });
	}

	priority_queue<Info, vector<Info>, Compare> pq;

	vector<pair<int, int>> mDistance(N + 1, { INT_MAX,-1 });

	int S, E;
	cin >> S >> E;

	mDistance[S] = { 0,-1 };
	pq.push({ S,0 });

	while (!pq.empty())
	{
		int curCity = pq.top().city;
		int curCost = pq.top().cost;

		pq.pop();

		if (curCost > mDistance[curCity].first)
		{
			continue;
		}

		for (const auto& edge : edges[curCity])
		{
			int nextCity = edge.first;
			int cost = edge.second;

			if (curCost + cost < mDistance[nextCity].first)
			{
				mDistance[nextCity].first = curCost + cost;

				mDistance[nextCity].second = curCity;

				pq.push({ nextCity,mDistance[nextCity].first });
			}
		}
	}

	stack<int> path;

	int cur = E;
	while (cur != S)
	{
		path.push(cur);
		cur = mDistance[cur].second;
	}

	path.push(S);

	cout << mDistance[E].first << "\n" << path.size() << "\n";

	while (!path.empty())
	{
		cout << path.top() << " ";

		path.pop();
	}
}