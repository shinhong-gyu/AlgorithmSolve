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

	vector<pair<int, int>> links(M);
	vector<int> infected;

	for (int i = 0; i < M; i++)
	{
		cin >> links[i].first >> links[i].second;
	}

	for (auto link : links)
	{
		if (link.first == 1)
		{
			if (find(infected.begin(), infected.end(), link.second) == infected.end())
			{
				infected.push_back(link.second);
			}
		}
		else if (link.second == 1)
		{
			if (find(infected.begin(), infected.end(), link.first) == infected.end())
			{
				infected.push_back(link.first);
			}
		}
	}

	for (int i = 0; i < infected.size(); i++)
	{
		for (auto link : links)
		{
			if (link.first == infected[i])
			{
				if (find(infected.begin(), infected.end(), link.second) == infected.end())
				{
					if (link.second != 1)
					{
						infected.push_back(link.second);
					}
				}
			}
			else if (link.second == infected[i])
			{
				if (find(infected.begin(), infected.end(), link.first) == infected.end())
				{
					if (link.first != 1)
						infected.push_back(link.first);
				}
			}
		}
	}

	cout << infected.size();
}