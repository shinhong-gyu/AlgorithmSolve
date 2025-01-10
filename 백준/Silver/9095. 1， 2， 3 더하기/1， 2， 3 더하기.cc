#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	int dp[12] = { 0 };

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	while (T--)
	{
		int N;
		cin >> N;

		for (int i = 4; i <= N; i++)
		{
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		}
		cout << dp[N] << endl;
	}
}