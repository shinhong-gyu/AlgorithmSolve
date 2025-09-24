#include <iostream>

int dp[1001][1001];

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		dp[i][1] = i;
		dp[i][0] = 1;
		dp[i][i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
		}
	}

	cout << dp[N][K];
}