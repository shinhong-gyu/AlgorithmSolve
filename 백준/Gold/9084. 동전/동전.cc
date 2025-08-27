#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		vector<int> coin(N);

		for (int i = 0; i < N; i++)
		{
			cin >> coin[i];
		}

		int target;
		cin >> target;

		vector<vector<int>> dp(N, vector<int>(target + 1, 0));

		int cur = coin[0];

		for (int i = cur; i <= target; i += cur)
		{
			dp[0][i]++;
		}

		for (int i = 1; i < N; i++)
		{
			int cur = coin[i];

			for (int j = cur; j <= target; j += cur)
			{
				dp[i][j]++;
			}

			for (int j = 1; j <= target; j++)
			{
				dp[i][j] += dp[i - 1][j];
				for (int k = cur; j - k >= 0; k += cur)
				{
					dp[i][j] += dp[i - 1][j - k];
				}
			}
		}

		cout << dp[N - 1][target]<< "\n";
	}
}