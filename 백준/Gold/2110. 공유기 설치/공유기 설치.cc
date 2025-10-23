#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, C;
vector<int> houses;

bool CheckPossibility(int mid)
{
	int count = 1;
	int cur = 0;
	for (int i = 1; i < N; i++)
	{
		if (houses[i] - houses[cur] >= mid)
		{
			cur = i;
			count++;
		}

		if (count == C)
		{
			return true;
		}
	}

	return false;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);



	cin >> N >> C;

	houses.resize(N);

	for (int i = 0; i < N; i++)
	{
		cin >> houses[i];
	}

	sort(houses.begin(), houses.end());

	int start = 1;
	int end = houses[N - 1] - houses[0];

	int answer = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;

		if (CheckPossibility(mid))
		{
			answer = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	cout << answer;
}