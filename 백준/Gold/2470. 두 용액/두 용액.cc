#include <iostream>
#include <climits>
#include <cmath>
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

	vector<int> liquid(N);

	for (int i = 0; i < N; i++)
	{
		cin >> liquid[i];
	}

	sort(liquid.begin(), liquid.end());

	int s = 0, e = N - 1;

	pair<int, int> answer;

	int minTemp = INT_MAX;
	while (s < e)
	{
		int sum = liquid[s] + liquid[e];

		if (abs(sum) < minTemp)
		{
			minTemp = abs(sum);
			answer.first = liquid[s];
			answer.second = liquid[e];
		}

		if (sum > 0)
		{
			e--;
		}
		else if (sum < 0)
		{
			s++;
		}
		else
		{
			cout << liquid[s] << " " << liquid[e];
			return 0;
		}
	}

	cout << answer.first << " " << answer.second;
}