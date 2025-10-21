#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> wines(N);

	for (int i = 0; i < N; i++)
	{
		cin >> wines[i];
	}

	vector<int> dp(N);

	dp[0] = wines[0];
	dp[1] = wines[1] + dp[0];
	dp[2] = max(max(wines[1] + wines[2], wines[0] + wines[2]), dp[1]);

	for (int i = 3; i < N; i++)
	{
		// i번째를 마시고 i-1번째는 마시지 않는 경우
		int case1 = dp[i - 2] + wines[i];
		// i,i-1번째를 연속으로 마시는 경우
		int case2 = i >= 3 ? dp[i - 3] + wines[i - 1] + wines[i] : 0;
		// i번째를 마시지 않는 경우
		int case3 = dp[i - 1];

		dp[i] = max(max(case1, case2), case3);
	}

	cout << dp[N - 1];
}