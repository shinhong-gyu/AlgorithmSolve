#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		// 마지막으로 j가 사용됐을 때 i를 만들 수 있는 경우의 수
		vector<vector<int>> dp(10001, vector<int>(4,0));


		dp[1][1] = 1;
		dp[1][2] = 0;
		dp[1][3] = 0;
		dp[2][1] = 1;
		dp[2][2] = 1;
		dp[2][3] = 0;
		dp[3][1] = 1;
		dp[3][2] = 1;
		dp[3][3] = 1;

		for (int i = 4; i <= 10000; i++)
		{
			dp[i][1] = dp[i - 1][1];
			dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
			dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
		}

		cout << dp[N][1] + dp[N][2] + dp[N][3] << "\n";
	}
}