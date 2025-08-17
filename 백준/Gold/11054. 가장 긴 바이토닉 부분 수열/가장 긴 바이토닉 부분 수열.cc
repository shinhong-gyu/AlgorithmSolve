#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> seq(N);

	// seq[i]를 최대값으로 하는 가장 긴 증가하는 수열
	vector<int> dp(N);

	for (int i = 0; i < N; i++)
	{
		cin >> seq[i];
		dp[i] = 1;
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (seq[i] > seq[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	// 최대값을 seq[i]로 하는 가장 긴 감소하는 수열의 길이
	vector<int> dp1(N, 1);


	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = i; j <= N - 1; j++)
		{
			if (seq[i] > seq[j])
			{
				dp1[i] = max(dp1[i], dp1[j] + 1);
			}
		}
	}

	int len = 0;

	for (int i = 0; i < N; i++)
	{
		if (dp[i] + dp1[i] - 1 > len)
		{
			len = dp[i] + dp1[i] - 1;
		}
	}

	cout << len;
}