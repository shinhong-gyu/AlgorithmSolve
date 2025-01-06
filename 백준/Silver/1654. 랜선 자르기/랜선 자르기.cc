#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K, N;
	cin >> K >> N;

	vector<long long> lanLine(K);

	long long low = 1, high = 0;
	long long mid, count = 0, max = 0;
	for (int i = 0; i < K; i++)
	{
		cin >> lanLine[i];
		if (lanLine[i] > high) high = lanLine[i];
	}

	while (low <= high)
	{
		mid = (low + high) / 2;
		count = 0;

		for (int i = 0; i < K; i++)
		{
			count += (lanLine[i] / mid);
		}

		if (count >= N)
		{
			max = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << max << endl;
}