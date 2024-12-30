#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<pair<int, int>> v(N);


	for (int i = 0; i < N; i++)
	{
		cin >> v[i].first >> v[i].second;
	}

	vector<int> rate(N);

	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (v[i].first < v[j].first && v[i].second < v[j].second)
			{
				count++;
			}
		}
		if (count == 0)
			rate[i] = 1;
		else
		{
			rate[i] = count + 1;
		}
		count = 0;
	}

	for (int i = 0; i < N; i++)
	{
		cout << rate[i] << " ";
	}
}