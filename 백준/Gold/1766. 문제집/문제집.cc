#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> preBuild(N + 1, vector<int>());
	vector<int> indegree(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;

		preBuild[A].push_back(B);
		indegree[B]++;
	}

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
		{
			pq.push(i);
		}
	}

	while (!pq.empty())
	{
		int top = pq.top();
		pq.pop();

		for (const auto& prob : preBuild[top])
		{
			indegree[prob]--;

			if (indegree[prob] == 0)
			{
				pq.push(prob);
			}
		}

		cout << top << " ";
	}
}