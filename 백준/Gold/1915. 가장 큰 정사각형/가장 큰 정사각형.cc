#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() 
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<int>> dp(N + 1, vector<int>(M + 1, 0));
	int max_side = 0;

	for (int i = 1; i <= N; ++i) {
		string row_str;
		cin >> row_str;
		for (int j = 1; j <= M; ++j) 
		{
			if (row_str[j - 1] == '1') 
			{
				dp[i][j] = min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] }) + 1;

				if (dp[i][j] > max_side) 
				{
					max_side = dp[i][j];
				}
			}
		}
	}

	cout << max_side * max_side << endl;

	return 0;
}