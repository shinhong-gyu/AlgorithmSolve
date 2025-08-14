#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct square
{
	int origin;
	int count;
	bool check;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str1;
	string str2;

	cin >> str1;
	cin >> str2;

	vector<vector<square>> dp(str1.length() + 1, vector<square>(str2.length() + 1, { 0,0,false }));

	for (int i = 1; i <= (int)str1.length(); i++)
	{
		for (int j = 1; j <= (int)str2.length(); j++)
		{
			// str1의 i번쨰랑 str2의 j번째가 같으면
			if (str1[i - 1] == str2[j - 1])
			{
				if (dp[i - 1][j - 1].check == true)
				{
					dp[i][j].count = dp[i - 1][j - 1].count + 1;

					dp[i][j].origin = max(dp[i][j].count, max(dp[i - 1][j].origin, dp[i][j - 1].origin));

					dp[i][j].check = true;
				}
				else
				{
					dp[i][j].origin = max(dp[i - 1][j].origin, dp[i][j - 1].origin);
					dp[i][j].count = 1;
					dp[i][j].check = true;
				}
			}
			else
			{
				dp[i][j].origin = max(dp[i - 1][j].origin, dp[i][j - 1].origin);
				dp[i][j].count = 0;
				dp[i][j].check = false;
			}
		}
	}

// 	for (int i = 1; i <= (int)str1.length(); i++)
// 	{
// 		for (int j = 1; j <= (int)str2.length(); j++)
// 		{
// 			cout << dp[i][j].origin << " ";
// 		}
// 		cout << endl;
// 	}
	cout << dp[(int)str1.length()][(int)str2.length()].origin;
}