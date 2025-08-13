#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<long long> dp(N + 1);
	dp[0] = 1;
	dp[1] = 1;

	if (N == 1)
	{
		cout << 1;
		return 0;
	}

	for (int i = 2; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}

	cout << dp[N];
}