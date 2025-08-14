#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dp[101][101][101] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str1, str2, str3;

	cin >> str1;
	cin >> str2;
	cin >> str3;

	int LCS = -1;

	for (int i = 1; i <= (int)str1.length(); i++)
	{
		for (int j = 1; j <= (int)str2.length(); j++)
		{
			for (int k = 1; k <= (int)str3.length(); k++)
			{
				if (str1[i - 1] == str2[j - 1] && str2[j - 1] == str3[k - 1])
				{
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				}
				else
				{
					dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
				}
				if (LCS < dp[i][j][k])
				{
					LCS = dp[i][j][k];
				}

			}
		}
	}
	cout << LCS << "\n";

}