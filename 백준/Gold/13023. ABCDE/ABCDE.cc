#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

vector<vector<int>> edge;
vector<bool> visited;

bool answer = false;

void DFS(int v, int depth)
{
	if (depth == 5 || answer)
	{
		answer = true;
		return;
	}

	visited[v] = true;

	for (int n : edge[v])
	{

		if (!visited[n])
		{
			DFS(n, depth + 1);
		}
	}
	visited[v] = false;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	edge.resize(N);
	visited.resize(N, false);

	for (int i = 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;

		if (a > b)
		{
			swap(a, b);
		}

		edge[a].push_back(b);
		edge[b].push_back(a);

	}

	for (int i = 0; i < N; i++)
	{
		if (!visited[i])
		{
			DFS(i, 1);

			if (answer)
			{
				break;
			}
		}
	}

	cout << answer;
}