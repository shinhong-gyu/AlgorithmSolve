#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int L;
		cin >> L;

		if (L % 2 != 0)
		{
			cout << 0 << "\n";
			continue;
		}

		int n = L / 2;
		vector<unsigned long long> dp(n + 1, 0);

		dp[0] = 1;

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				unsigned long long result = (dp[j] % 1000000007) * (dp[i - j - 1] % 1000000007);
				dp[i] += result;
				dp[i] %= 1000000007;
			}
		}

		cout << dp[n] % 1000000007 << "\n";
	}
}
