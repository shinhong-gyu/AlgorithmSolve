#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<unsigned long long, unsigned long long> dp[91];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	dp[1].first = 0;
	dp[1].second = 1;

	for (int i = 2; i <= N; i++)
	{
		dp[i].first = dp[i - 1].second + dp[i - 1].first;
		dp[i].second = dp[i - 1].first;
	}

	cout << dp[N].first + dp[N].second;
}