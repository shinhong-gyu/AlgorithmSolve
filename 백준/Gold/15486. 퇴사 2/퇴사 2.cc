#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> consult(N + 1);
	// i 일차에 얻을 수 있는 최대 이득
	vector<int> dp(N + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> consult[i].first >> consult[i].second;

	}

	for (int i = 1; i <= N; i++)
	{
		dp[i] = max(dp[i], dp[i - 1]);

		if (i + consult[i].first - 1 <= N)
		{
			dp[i + consult[i].first - 1] = max(dp[i + consult[i].first - 1], dp[i - 1] + consult[i].second);
		}
	}

	cout << *max_element(dp.begin(), dp.end());
}