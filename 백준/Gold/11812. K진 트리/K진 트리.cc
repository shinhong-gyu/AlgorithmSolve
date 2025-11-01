#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

#define ll long long

ll N, K, Q;

ll parent(ll i)
{
	if (i == 1)
	{
		return 1;
	}
	else
	{
		return (i - 2) / K + 1;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K >> Q;


	while (Q--)
	{
		ll x, y;
		cin >> x >> y;

		ll distance = 0;

		if (K == 1)
		{
			distance = abs(x - y);
		}
		else
		{

			while (x != y)
			{
				if (x > y)
				{
					x = parent(x);
				}
				else
				{
					y = parent(y);
				}
				distance++;
			}

		}


		cout << distance << "\n";
	}
}