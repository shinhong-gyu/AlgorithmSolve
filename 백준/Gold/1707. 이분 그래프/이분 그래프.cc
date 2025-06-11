#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void Search()
{
	int V, E;
	cin >> V >> E;

	vector<vector<int>> edges(V + 1);

	for (int i = 0; i < E; i++)
	{
		int u, v;
		cin >> u >> v;

		edges[u].push_back(v);
		edges[v].push_back(u);
	}


	vector<int> affiliations(V + 1, -1);
	vector<bool> visited(V + 1, false);

	for (int i = 1; i <= V; i++)
	{
		queue<pair<int, int>> q;

		if (affiliations[i] == -1)
		{
			q.push(make_pair(i, 1));
		}
		else
		{
			q.push(make_pair(i, affiliations[i]));
		}

		visited[i] = true;

		while (!q.empty())
		{

			int node = q.front().first;
			int affiliation = q.front().second;

			q.pop();

			int nextAffi = 1 - affiliation;

			for (auto edge : edges[node])
			{
				if (affiliations[edge] == affiliation)
				{
					cout << "NO" << "\n";
					return;
				}
				else
				{
					if (!visited[edge])
					{
						affiliations[edge] = nextAffi;

						q.push(make_pair(edge, nextAffi));
						visited[edge] = true;
					}
				}
			}
		}
	}

	cout << "YES" << "\n";
	return;
}

int main()
{
	ios::sync_with_stdio(false);

	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		Search();
	}
}

