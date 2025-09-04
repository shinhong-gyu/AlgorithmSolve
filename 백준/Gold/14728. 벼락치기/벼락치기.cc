#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, T;
	cin >> N >> T;

	vector<int> K(N + 1);
	vector<int> S(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> K[i] >> S[i];
	}

	vector<vector<int>> dp(N + 1, vector<int>(T + 1, 0));

	for (int i = K[1]; i <= T; i++)
	{
		dp[1][i] = S[1];
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= T; j++)
		{
			if (j >= K[i])
			{
				dp[i][j] = max(dp[i - 1][j - K[i]] + S[i], dp[i - 1][j]);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][T];
}