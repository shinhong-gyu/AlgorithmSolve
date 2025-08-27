#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string code;
	cin >> code;

	if (code[0] == '0')
	{
		cout << 0;
		return 0;
	}

	// i번째까지의 암호를 포함했을 때 해석 가능한 경우의 수
	vector<long long> dp(code.length(), 0);

	dp[0] = 1;

	for (int i = 1; i < code.length(); i++)
	{
		int a = code[i] - '0';
		int b = code[i - 1] - '0';

		int temp = b * 10 + a;

		if (a >= 1 && a <= 9)
		{
			dp[i] = dp[i - 1];
		}

		if (temp >= 10 && temp <= 26)
		{
			if (i >= 2)
			{
				dp[i] = (dp[i] + dp[i - 2]) % 1000000;
			}
			else
			{
				if (a != 0)
				{
					dp[i] = 2;
				}
				else
				{
					dp[i] = 1;
				}
			}
		}

		if (a == 0 && b == 0)
		{
			cout << 0;
			return 0;
		}
	}

	cout << dp[code.length() - 1] % 1000000;
}