#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	vector<long long> liquid(N);

	for (int i = 0; i < N; i++)
	{
		cin >> liquid[i];
	}

	int low = 0;
	int high = N - 1;
	long long little, big;
	long long sum = INT_MAX;
	pair<long long, long long> answer;

	while (low < high)
	{
		little = liquid[low];
		big = liquid[high];

		long long temp = little + big;

		if (sum >= std::abs(temp))
		{
			sum = std::abs(temp);
			answer = { little,big };
		}

		if (temp < 0)
		{
			low++;
		}
		else if (temp > 0)
		{
			high--;
		}
		else
		{
			cout << little << " " << big;
			return 0;
		}
	}

	cout << answer.first << " " << answer.second;

}