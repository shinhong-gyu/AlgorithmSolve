#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define mod 1000000000

using namespace std;

unsigned long long dp[101][10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;
	}

	dp[1][0] = 0;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= 8; j++)
		{
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
		}

		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];

		for (int j = 0; j <= 9; j++)
		{
			dp[i][j] %= mod;
		}
	}

	int sum = 0;

	for (int i = 0; i <= 9; i++)
	{
		sum += dp[N][i];
		sum %= mod;
	}

	cout << sum;

}