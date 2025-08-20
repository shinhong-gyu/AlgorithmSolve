#include <iostream>
#include <vector>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> coins(N + 1);

	vector<int> dp(K + 1, 0);

	for (int i = 1; i <= N; i++)
	{
		cin >> coins[i];
	}

	for (int i = 1; i <= N; i++)
	{
		vector<int> temp_dp = dp;

		for (int j = 1; j <= K; j++)
		{
			for (int k = 1; k * coins[i] <= K; k++)
			{
				if (j - k * coins[i] > 0)
				{
					temp_dp[j] += dp[j - k * coins[i]];
				}
				else
				{
					break;
				}
			}
		}

		for (int k = 1; k * coins[i] <= K; k++)
		{
			temp_dp[k * coins[i]] += 1;
		}

		dp = temp_dp;
	}


	cout << dp[K];
}