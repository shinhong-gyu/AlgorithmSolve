#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int rgb[1001][3];

// i번째를 j로 칠할 떄의 최솟값
int dp[1001][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
	}

	dp[1][0] = rgb[1][0];
	dp[1][1] = rgb[1][1];
	dp[1][2] = rgb[1][2];

	// n = 0 일떄
	dp[2][0] = min(dp[1][1], dp[1][2]) + rgb[2][0];
	dp[2][1] = dp[1][2] + rgb[2][1];
	dp[2][2] = dp[1][1] + rgb[2][2];

	for (int i = 3; i <= N - 1; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
	}

	dp[N][0] = min(dp[N - 1][1], dp[N - 1][2]) + rgb[N][0];

	// n = 1 일떄
	dp[2][0] = dp[1][2] + rgb[2][0];
	dp[2][1] = min(dp[1][0], dp[1][2]) + rgb[2][1];
	dp[2][2] = dp[1][0] + rgb[2][2];

	for (int i = 3; i <= N - 1; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
	}

	dp[N][1] = min(dp[N - 1][0], dp[N - 1][2]) + rgb[N][1];


	// n = 0 일떄
	dp[2][0] = dp[1][1] + rgb[2][0];
	dp[2][1] = dp[1][0] + rgb[2][1];
	dp[2][2] = min(dp[1][0], dp[1][1]) + rgb[2][2];

	for (int i = 3; i <= N - 1; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
	}

	dp[N][2] = min(dp[N - 1][0], dp[N - 1][1]) + rgb[N][2];

	cout << min(dp[N][0], min(dp[N][1], dp[N][2]));
}