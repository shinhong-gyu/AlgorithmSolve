#include <iostream>
#include <vector>

using namespace std;

int N, W;

int dp[1001][3][31];

int record[1001];

int solve(int sec, int loc, int m)
{
	if (sec > N)
	{
		return 0;
	}

	if (dp[sec][loc][m] != -1)
	{
		return dp[sec][loc][m];
	}

	// 그대로 있는 경우
	int case1 = solve(sec + 1, loc, m);

	// 움직이는 경우
	int case2 = -1;
	if (m < W)
	{
		int next = loc == 1 ? 2 : 1;
		case2 = solve(sec + 1, next, m + 1);
	}

	int cur = (record[sec] == loc) ? 1 : 0;

	dp[sec][loc][m] = cur + max(case1, case2);

	return dp[sec][loc][m];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N >> W;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= 2; j++)
		{
			for (int k = 0; k <= W; k++)
			{
				dp[i][j][k] = -1;
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cin >> record[i];
	}



	cout << max(solve(1, 1, 0), solve(1, 2, 1));
}