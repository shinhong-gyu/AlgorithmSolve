#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		vector<int> coins(N + 1);

		for (int i = 1; i <= N; i++)
		{
			cin >> coins[i];
		}

		int M;
		cin >> M;

		vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));

		for (int i = 1; i <= N; i++)
		{
			dp[i][coins[i]] = 1;
		}

		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++)
			{
				if (j - coins[i] > 0)
				{
					for (int k = 1; k <= i; k++)
					{
						if (dp[k][j - coins[i]] != 0)
						{
							dp[i][j] += dp[k][j - coins[i]];
						}
					}
				}
			}
		}
		int answer = 0;

		for (int i = 1; i <= N; i++)
		{
			answer += dp[i][M];
		}
		cout <<  answer << "\n";
	}
}