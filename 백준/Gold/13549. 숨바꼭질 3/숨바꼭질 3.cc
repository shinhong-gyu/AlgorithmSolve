#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> minTime(100001, INT_MAX);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	queue<pair<int, int>> q;


	q.push(make_pair(N, 0));
	minTime[N] = 0;

	int min = INT_MAX;

	while (!q.empty())
	{
		int cur = q.front().first;
		int depth = q.front().second;

		q.pop();

		if (cur == K)
		{
			if (depth < min)
			{
				min = depth;
			}
			continue;
		}

		if (cur * 2 <= 100000 && minTime[cur * 2] > depth)
		{
			q.push(make_pair(cur * 2, depth));
			minTime[cur * 2] = depth;
		}

		if (cur + 1 <= 100000 && minTime[cur + 1] > depth + 1)
		{
			q.push(make_pair(cur + 1, depth + 1));
			minTime[cur + 1] = depth + 1;
		}

		if (cur - 1 >= 0 && minTime[cur - 1] > depth + 1)
		{
			q.push(make_pair(cur - 1, depth + 1));
			minTime[cur - 1] = depth - 1;
		}
	}

	cout << min;
}

