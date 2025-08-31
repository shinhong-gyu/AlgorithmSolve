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

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	vector<int> dp(N);

	int total = 0;

	dp[0] = v[0];

	for (int i = 1; i < N; i++)
	{
		dp[i] = max(dp[i - 1] + v[i], v[i]);
	}

	cout << *max_element(dp.begin(), dp.end());
}