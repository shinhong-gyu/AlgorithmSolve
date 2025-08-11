#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<pair<int, int>> articles;

	articles.push_back({ 0,0 });

	for (int i = 0; i < N; i++)
	{
		int W, V;
		cin >> W >> V;

		articles.push_back({ W,V });
	}

	vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

	// i는 배낭에 넣을 물건 번호, j는 현재 배낭의 무게를 의미
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			if (j >= articles[i].first)
			{
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - articles[i].first] + articles[i].second);
			}
			else
			{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][K];
}