#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<vector<long long>> dp(K + 1, vector<long long>(N + 1, 0));

	for (int n = 0; n <= N; n++)
	{
		dp[1][n] = 1;
	}

	for (int k = 2; k <= K; k++)
	{
		dp[k][0] = 1;

		for (int n = 1; n <= N; n++)
		{
			dp[k][n] = (dp[k - 1][n] + dp[k][n - 1]) % 1000000000;
		}
	}

	cout << dp[K][N];

	return 0;
}