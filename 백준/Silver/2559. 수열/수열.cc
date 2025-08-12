#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;

	cin >> N >> K;

	vector<int> temp(N);

	for (int i = 0; i < N; i++)
	{
		cin >> temp[i];
	}

	vector<int>::iterator start = temp.begin();
	vector<int>::iterator end = start + K;



	int max = INT_MIN;

	while (end <= temp.end())
	{

		int sum = 0;

		for (auto iter = start; iter < end; iter++)
		{
			sum += *iter;
		}

		if (sum > max)
		{
			max = sum;
		}

		if (end == temp.end())
		{
			break;
		}

		start++;
		end++;
	}

	cout << max;


}