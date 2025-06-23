#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1001][3];
char rgb[1001];
int cost[1001][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	dp[1][0] = cost[1][0];
	dp[1][1] = cost[1][1];
	dp[1][2] = cost[1][2];

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			switch (j)
			{
			case 0:
				dp[i][j] = min(dp[i - 1][j + 1] + cost[i][j], dp[i - 1][j + 2] + cost[i][j]);
				break;

			case 1:

				dp[i][j] = min(dp[i - 1][j - 1] + cost[i][j], dp[i - 1][j + 1] + cost[i][j]);
				break;
			case 2:

				dp[i][j] = min(dp[i - 1][j - 1] + cost[i][j], dp[i - 1][j - 2] + cost[i][j]);
				break;
			}
		}
	}

	cout << min(min(dp[N][0], dp[N][1]), dp[N][2]);
}