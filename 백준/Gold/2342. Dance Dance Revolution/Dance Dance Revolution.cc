#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

// i -> j로 이동할 떄의 힘
int power[5][5];

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> seq;
	seq.push_back(-1);
	while (1)
	{
		int in;
		cin >> in;

		if (in == 0)
		{
			break;
		}

		seq.push_back(in);
	}

	vector<vector<vector<int>>> dp(seq.size(), vector<vector<int>>(5, vector<int>(5, INT_MAX)));
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			if (i == j)
			{
				power[i][j] = 1;
			}

			else if (abs(i - j) == 2)
			{
				power[i][j] = 4;
			}

			else
			{
				power[i][j] = 3;
			}
		}

		power[0][i] = 2;
	}

	dp[1][0][seq[1]] = 2;
	dp[1][seq[1]][0] = 2;


	for (int n = 2; n < seq.size(); n++)
	{
		int cur = seq[n];

		for (int i = 0; i <= 4; i++)
		{
			for (int j = 0; j <= 4; j++)
			{
				// n번까지 수행했을 때 왼다리가 i 오른 다리가 j에 있을 때의 최소 힘
				// n-1번 수행하고 왼다리를 움직였을 때, 오른다리 움직였을 떄 중 최소
				if (dp[n - 1][j][i] != INT_MAX)
				{
					dp[n][cur][i] = min(dp[n][cur][i], dp[n - 1][j][i] + power[j][cur]);
				}

				if (dp[n - 1][i][j] != INT_MAX)
				{
					dp[n][i][cur] = min(dp[n][i][cur], dp[n - 1][i][j] + power[j][cur]);
				}
			}
		}
	}

	int answer = INT_MAX;
	int last = seq[seq.size() - 1];
	for (int i = 0; i <= 4; i++)
	{
		answer = min(answer, min(dp[seq.size() - 1][last][i], dp[seq.size() - 1][i][last]));
	}

	cout << answer;
}