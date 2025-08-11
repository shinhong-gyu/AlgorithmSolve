#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<ll> cost(N,0);
	vector<ll> oilprice(N);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> cost[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> oilprice[i];
	}

	ll use = 0;
	ll charge = 0;
	ll canGo = 0;

	for (int i = 0; i < cost.size(); i++)
	{
		charge = cost[i];


		for (int j = i + 1; j < cost.size(); j++)
		{
			if (oilprice[j] > oilprice[i])
			{
				charge += cost[j];
				canGo = j;
			}
			else
			{
				break;
			}
		}

		use += charge * oilprice[i];
		i = canGo;
		canGo = i + 1;
		charge = 0;
	}

	cout << use;
}