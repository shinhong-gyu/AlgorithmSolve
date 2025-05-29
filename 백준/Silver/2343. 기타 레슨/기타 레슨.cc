#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> lessons(N);
	
	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> lessons[i];
		sum += lessons[i];
	}

	int max = sum;
	int min = *max_element(lessons.begin(),lessons.end());


	while (min <= max)
	{
		int mid = (min + max) / 2;
		int count = 0;
		sum = 0;

		for (int i = 0; i < (int)lessons.size(); i++)
		{
			if (sum + lessons[i] > mid)
			{
				count++;
				sum = 0;
			}
			sum += lessons[i];
		}

		if (sum != 0)
		{
			count++;
		}

		if (count > M)
		{
			min = mid + 1;
		}
		else
		{
			max = mid - 1;
		}
	}

	cout << min << "\n";
}