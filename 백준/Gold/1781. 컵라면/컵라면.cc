#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Pred
{
	bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)
	{
		return p1.second < p2.second;
	}

};



bool Pred1(const pair<int, int>& p1, const pair<int, int>& p2)
{
	return p1.first > p2.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<pair<int, int>, vector<pair<int, int>>, Pred> pq;

	// 남은 것들 중에서 deadline 보다 first가 작거나 같으면서 second가 가장 큰 것
	vector<pair<int, int>> lamen(N);

	int lastDay = -1;

	for (int i = 0; i < N; i++)
	{
		cin >> lamen[i].first >> lamen[i].second;

		if (lastDay < lamen[i].second)
		{
			lastDay = lamen[i].second;
		}
	}

	sort(lamen.begin(), lamen.end(), Pred1);

	int answer = 0;

	int idx = 0;

	for (int i = N; i >= 1; i--)
	{
		while (idx < lamen.size() && lamen[idx].first >= i)
		{
			pq.push(lamen[idx]);
			idx++;
		}

		if (!pq.empty())
		{
			answer += pq.top().second;

			pq.pop();
		}

	}

	cout << answer;
}

