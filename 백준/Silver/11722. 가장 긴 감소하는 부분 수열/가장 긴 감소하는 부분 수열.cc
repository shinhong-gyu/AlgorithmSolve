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

	vector<int> dp(N, 1);
	vector<int> arr(N);

	for (int idx = 0; idx < N; idx++)
	{
		cin >> arr[idx];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] < arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << *std::max_element(dp.begin(), dp.end()) << "\n";
}