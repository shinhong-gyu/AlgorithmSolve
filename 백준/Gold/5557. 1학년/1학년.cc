#include <iostream>
#include <vector>

using namespace std;
#define ull unsigned long long

// i번째까지 사용해서 j를 만들 수 있는 경우의 수
ull dp[101][21] = { 0 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> num(N + 1);
	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}

	int rValue = num[N];

	dp[1][num[1]] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j <= 20; j++)
		{

			if (j - num[i] >= 0 && dp[i - 1][j] != 0)
			{
				dp[i][j - num[i]] += dp[i - 1][j];
			}

			if (j + num[i] <= 20 && dp[i - 1][j] != 0)
			{
				dp[i][j + num[i]] += dp[i - 1][j];
			}
		}
	}

	cout << dp[N - 1][rValue];
}