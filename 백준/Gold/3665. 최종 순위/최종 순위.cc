#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		vector<int> rate(N + 1);
		vector<int> indegree(N + 1);
		vector<vector<int> > edges(N + 1, vector<int>());

		for (int i = 1; i <= N; i++)
		{
			cin >> rate[i];
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = i + 1; j <= N; j++)
			{
				edges[rate[i]].push_back(rate[j]);
				indegree[rate[j]]++;
			}
		}

		int M;
		cin >> M;

		if (M == 0)
		{
			for (int i = 1; i <= N; i++)
			{
				cout << rate[i] << " ";
			}
			cout << "\n";
			continue;
		}

		bool IMPOSSIBLE = false;
		bool QM = false;
		for (int i = 0; i < M; i++)
		{
			int A, B;
			cin >> A >> B;

			auto iter = find(edges[B].begin(), edges[B].end(), A);

			if (iter != edges[B].end())
			{
				edges[B].erase(iter);
				indegree[A]--;

				edges[A].push_back(B);
				indegree[B]++;
			}
			else
			{
				iter = find(edges[A].begin(), edges[A].end(), B);

				if (iter != edges[A].end())
				{
					edges[A].erase(iter);
					indegree[B]--;

					edges[B].push_back(A);
					indegree[A]++;
				}
				else
				{
					IMPOSSIBLE = true;
				}
			}
		}


		queue<int> q;
		vector<int> thisYear;

		for (int i = 1; i <= N; i++)
		{
			if (indegree[rate[i]] == 0)
			{
				q.push(rate[i]);
			}
		}

		while (!q.empty())
		{
			if (q.size() >= 2)
			{
				QM = true;
				break;
			}

			int cur = q.front();
			q.pop();

			thisYear.push_back(cur);

			for (int n : edges[cur])
			{
				indegree[n]--;

				if (indegree[n] == 0)
				{
					q.push(n);
				}
			}
		}

		if (QM)
		{
			cout << "?" << "\n";
			continue;
		}

		if (thisYear.size() != N || IMPOSSIBLE)
		{
			cout << "IMPOSSIBLE" << "\n";
			continue;
		}

		for (int i = 0; i < N; i++)
		{
			cout << thisYear[i] << " ";
		}
		cout << "\n";

	}
}