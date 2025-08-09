#include <iostream>
#include <vector>
#include <queue>
#include <climits>

#define INF INT_MAX

using namespace std;

struct Node
{
	int vertex;
	int cost;
};

struct compare
{
	bool operator()	(const Node& n1, const Node& n2)
	{
		return n1.cost > n2.cost;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E;
	cin >> V >> E;

	int s;
	cin >> s;

	vector<vector<pair<int, int>>> costs(V + 1);

	// 1. 인접 그래프 구현
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		costs[a].push_back({ b, c });
	}

	vector<int> mDistance(V + 1, INF);

	priority_queue<Node, vector<Node>, compare> pq;

	mDistance[s] = 0;
	pq.push({ s, 0 });

	while (!pq.empty())
	{
		int vertex = pq.top().vertex;
		int cost = pq.top().cost;
		pq.pop();

		for (const auto& p : costs[vertex])
		{
			int nextV = p.first;
			int nextCost = p.second;

			if (mDistance[nextV] > cost + nextCost)
			{
				mDistance[nextV] = cost + nextCost;

				pq.push({ nextV,mDistance[nextV] });
			}
		}
	}

	int count = 0;
	for (int d : mDistance)
	{
		if (count == 0)
		{	
			count++;
			continue;
		}
		if (d == INF)
		{
			cout << "INF" << "\n";
		} 
		else
		{
			cout << d << "\n";
		}
	}

}