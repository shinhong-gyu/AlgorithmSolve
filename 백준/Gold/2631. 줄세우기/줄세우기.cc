#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> children(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> children[i];
	}

	vector<int> dp(N + 1, 1);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (children[j] < children[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << N - *max_element(dp.begin(), dp.end());

}