#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<int> lineup(N);
	vector<int> diff(N);

	for (int i = 0; i < N; i++)
	{
		cin >> lineup[i];

		if (i != 0)
		{
			diff[i] = lineup[i] - lineup[i - 1];
		}
	}

	sort(diff.begin(), diff.end(), greater<int>());

	int sum = accumulate(diff.begin() + K - 1, diff.end(), 0);

	cout << sum;
}