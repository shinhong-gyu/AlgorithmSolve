#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int dp[1001][1001] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str1, str2;

	cin >> str1;
	cin >> str2;

	int LCS = -1;

	for (int i = 1; i <= str1.length(); i++)
	{
		for (int j = 1; j <= str2.length(); j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}

			if (dp[i][j] > LCS)
			{
				LCS = dp[i][j];
			}
		}
	}
	cout << LCS;
}