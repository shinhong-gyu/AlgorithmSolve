#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> v(N);
	vector<int> negIdx;

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];

		if (v[i] < 0)
		{
			negIdx.push_back(i);
		}

	}

	// i번째까지의 최대 연속 합과 제거한 수의 인덱스
	vector<int> dp(N);
	vector<int> left_dp(N);

	dp[0] = v[0];
	left_dp[0] = v[0];

	for (int i = 1; i < N; i++)
	{
		dp[i] = max(dp[i - 1] + v[i], v[i]);
		left_dp[i] = max(left_dp[i - 1] + v[i], v[i]);
	}

	int answer = *max_element(dp.begin(), dp.end());
	vector<int> right_dp(N);

	right_dp[N - 1] = v[N - 1];


	for (int i = N - 2; i >= 0; i--)
	{
		right_dp[i] = max(right_dp[i + 1] + v[i], v[i]);
	}

	for (int i : negIdx)
	{
		if (i > 0 && i < N - 1)
		{
			dp[i] = max(dp[i],right_dp[i + 1] + left_dp[i - 1]);
		}
	}

	cout << *max_element(dp.begin(), dp.end());
}

