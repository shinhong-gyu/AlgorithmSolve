#include <iostream>
#include <queue>
#include <vector>

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
		int n;
		cin >> n;

		vector<vector<int>> sticker(2, vector<int>(n));
		vector<vector<int>> dp(2, vector<int>(n));


		for (int i = 0; i < n; i++)
		{
			cin >> sticker[0][i];
		}

		for (int i = 0; i < n; i++)
		{
			cin >> sticker[1][i];
		}

		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];

		dp[0][1] = dp[1][0] + sticker[0][1];
		dp[1][1] = dp[0][0] + sticker[1][1];

		int answer = max(max(dp[0][0], dp[1][0]), max(dp[0][1], dp[1][1]));

		for (int i = 2; i < n; i++)
		{
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + sticker[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + sticker[1][i];

			int temp = max(dp[0][i], dp[1][i]);

			if (temp > answer)
			{
				answer = temp;
			}
		}

		cout << answer << "\n";
	}
}