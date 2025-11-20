#include <iostream>
#include <vector>
#include <climits>

#define INF INT_MAX


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int V, E;
	cin >> V >> E;

	vector<vector<int>> dist(V + 1, vector<int>(V + 1, INF));

	for (int i = 0; i < E; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;

		dist[A][B] = min(C, dist[A][B]);
	}

	for (int k = 1; k <= V; k++)
	{
		for (int i = 1; i <= V; i++)
		{
			for (int j = 1; j <= V; j++)
			{
				if (dist[k][j] != INF && dist[i][k] != INF)
				{
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}

	int minDist = INF;

	for (int i = 1; i <= V; i++)
	{
		minDist = min(dist[i][i], minDist);
	}

	if (minDist == INF)
	{
		cout << -1;
	}
	else
	{
		cout << minDist;
	}
	
}