#include <iostream>
#include <vector>
#include <queue>
#include <random>

using namespace std;

struct Link
{
	Link(int e, int w)
	{
		endNode = e;
		weight = w;
	}

	int endNode;

	int weight;
};

void bfs(std::queue<int>& q, std::vector<bool>& visited, std::vector<std::vector<Link>>& links, std::vector<int>& distance, int& maxLength, int& maxNode);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V;
	cin >> V;

	int NodeNum;

	vector<vector<Link>> links(V + 1, vector<Link>());

	queue<int> q;

	for (int i = 1; i <= V; i++)
	{
		cin >> NodeNum;

		int end;
		int weight;
		while (1)
		{
			cin >> end;

			if (end == -1)
			{
				break;
			}

			cin >> weight;

			links[NodeNum].push_back(Link(end, weight));
		}
	}

	int randNum = rand() % (V-1) + 1;

	q.push(randNum);

	vector<int> distance(V + 1, 0);

	vector<bool> visited(V + 1, false);

	int maxNode = -1;
	int maxLength = 0;

	bfs(q, visited, links, distance, maxLength, maxNode);

	distance = vector<int>(V + 1, 0);
	visited = vector<bool>(V + 1, false);
	maxLength = 0;

	q.push(maxNode);

	bfs(q, visited, links, distance, maxLength, maxNode);

	cout << maxLength;
}

void bfs(std::queue<int>& q, std::vector<bool>& visited, std::vector<std::vector<Link>>& links, std::vector<int>& distance, int& maxLength, int& maxNode)
{

	while (!q.empty())
	{
		int cur = q.front();

		visited[cur] = true;

		q.pop();

		int sum = 0;

		for (auto link : links[cur])
		{
			if (!visited[link.endNode])
			{
				distance[link.endNode] = distance[cur] + link.weight;

				q.push(link.endNode);

				if (distance[link.endNode] > maxLength)
				{
					maxNode = link.endNode;
					maxLength = distance[link.endNode];
				}
			}
		}
	}
}

