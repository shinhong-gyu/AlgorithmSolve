#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	long long dp[1001];

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 2] * 2 + dp[i - 1]) % 10007;
	}
	cout << dp[N] << endl;
}