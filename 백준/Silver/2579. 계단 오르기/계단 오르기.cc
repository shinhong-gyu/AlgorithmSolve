#include <iostream>
#include <vector>

using namespace std;

int dp[301] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> stair(N + 1);

	for (int i = 0; i < N; i++)
	{
		cin >> stair[i + 1];
	}

	int count = 0;

	dp[1] = stair[1];
	dp[2] = stair[1] + stair[2];
	dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);


	for (int i = 4; i <= N; i++)
	{
		dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	}

	cout << dp[N] << endl;

}