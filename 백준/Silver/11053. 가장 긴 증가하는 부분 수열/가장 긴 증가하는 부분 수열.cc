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

	int arr[1001];
	int dp[1001];

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << *std::max_element(dp, dp + N);
}