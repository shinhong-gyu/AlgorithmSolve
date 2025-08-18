#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	map<int, int> links;

	for (int i = 0; i < N; i++)
	{
		int n, k;
		cin >> n >> k;
		links[n] = k;
	}

	vector<int> arr;

	for (auto p : links)
	{
		arr.push_back(p.second);
	}

	vector<int> dp(N, 1);

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << arr.size() - *max_element(dp.begin(), dp.end());
}