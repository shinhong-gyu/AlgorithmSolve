#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> input(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> input[i];
	}

	sort(input.begin(), input.end());

	queue<vector<int>> q;

	q.push(vector<int>());

	vector<bool> visited(10001, false);

	while (!q.empty())
	{
		vector<int> cur = q.front();

		visited.assign(10001, false);

		for (auto n : cur)
		{
			visited[n] = true;
		}

		q.pop();

		if (cur.size() == M)
		{
			for (auto n : cur)
			{
				cout << n << " ";
			}
			cout << "\n";
			continue;
		}


		for (int i = 1; i <= N; i++)
		{
			vector<int> seq = cur;
			if (!visited[input[i]])
			{
				seq.push_back(input[i]);

				visited[input[i]] = true;

				q.push(seq);
			}
		}
	}
}