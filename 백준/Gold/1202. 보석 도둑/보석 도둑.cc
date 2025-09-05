#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool Pred(const pair<int, int>& p1, const pair<int, int>& p2)
{
	if (p1.first == p2.first)
	{
		return p1.second < p2.second;
	}

	return p1.first < p2.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	// {무게 ,가치}
	vector<pair<int, int>> jewel(N);

	for (int i = 0; i < N; i++)
	{
		cin >> jewel[i].first >> jewel[i].second;
	}

	vector<int> volume(K);

	for (int i = 0; i < K; i++)
	{
		cin >> volume[i];
	}

	sort(jewel.begin(), jewel.end());
	sort(volume.begin(), volume.end());

	unsigned long long answer = 0;
	priority_queue<int> pq;
	int jewelIdx = 0;

	// 보석의 가치가 가장 큰 것을 넣을 수 있는 가방 중 가장 용량이 작은 가방에 집어 넣음
	for (int i = 0; i < K; i++)
	{
		while (jewelIdx < N && jewel[jewelIdx].first <= volume[i])
		{
			pq.push(jewel[jewelIdx].second);
			jewelIdx++;
		}

		if (!pq.empty())
		{
			answer += pq.top();
			pq.pop();
		}
	}

	cout << answer;
}
