#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> trust(N + 1, vector<int>());


	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;

		trust[A].push_back(B);
	}

	int efficient = -1;


	vector<int> answer(N + 1, 0);

	vector<bool> visited(N + 1, false);

	for (int i = 1; i <= N; i++)
	{
		fill(visited.begin(), visited.end(), false);

		if (trust[i].size() <= 0)
		{
			answer[i]++;
			continue;
		}


		queue<int> q;

		q.push(i);
		visited[i] = true;

		while (!q.empty())
		{
			int c = q.front();

			q.pop();

			for (int n : trust[c])
			{
				if (!visited[n])
				{
					q.push(n);
					answer[n]++;
					visited[n] = true;
				}
			}
		}
	}

	int maxEfficient = *max_element(answer.begin(), answer.end());

	for (int i = 1; i <= N; i++)
	{
		if (answer[i] == maxEfficient)
		{
			cout << i << " ";
		}
	}
}