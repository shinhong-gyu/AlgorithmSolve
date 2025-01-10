#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	long long dp[101] = { 0 };
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	while (T--)
	{
		int N;
		cin >> N;

		for (int i = 4; i <= N; i++)
		{
			dp[i] = dp[i - 2] + dp[i - 3];
		}
		cout << dp[N] << endl;
	}
}