#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <queue>

using namespace std;


int A, B;
int N, M;

int maxWeight = -1;

vector<tuple<int, int, int>> bridges;

bool Check(int mid)
{
	vector<vector<int>> edges(N + 1, vector<int>());

	for (int i = 0; i < M; i++)
	{
		int cost = get<0>(bridges[i]);
		if (cost >= mid)
		{
			int x = get<1>(bridges[i]);
			int y = get<2>(bridges[i]);
			edges[x].push_back(y);
			edges[y].push_back(x);
		}
	}


	vector<bool> visited(N + 1, false);

	queue<int> q;

	q.push(A);
	visited[A] = true;

	while (!q.empty())
	{
		int cur = q.front();

		q.pop();

		if (cur == B)
		{
			return true;
		}

		for (int n : edges[cur])
		{
			if (!visited[n])
			{
				q.push(n);
				visited[n] = true;
			}
		}
	}

	return false;
}


int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;

		bridges.push_back({ c,a,b });

		maxWeight = max(c, maxWeight);
	}

	cin >> A >> B;

	int low = 1, high = maxWeight;
	int answer = -1;
	while (low <= high)
	{
		int mid = (low + high) / 2;

		if (Check(mid))
		{
			answer = max(answer, mid);
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	cout << answer;
}