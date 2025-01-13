#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long N, M;
	cin >> N >> M;

	vector<int> treeHeight(N);
	long long highest = -1;

	long long low = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> treeHeight[i];
		if (treeHeight[i] > highest) highest = treeHeight[i];
	}

	long long mid = 0, total = 0;
	long long max = 0;
	while (highest >= low)
	{
		mid = (low + highest) / 2;
		total = 0;

		for (auto h : treeHeight)
		{
			if (h - mid > 0)
			{
				total += (h - mid);
			}
		}
		if (total >= M)
		{
			max = mid;
			low = mid + 1;
		}
		else
		{
			highest = mid - 1;
		}
	}

	cout << max << "\n";
}
