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

	int T;
	cin >> T;

	while (T--)
	{
		long long x = 0, y = 0;

		cin >> x >> y;

		double dist = y - x;

		if (dist <= 3)
		{
			cout << dist << "\n";
			continue;
		}

		int count = 0;

		double n = floor(sqrt(dist));

		if (dist == n * n)
		{
			count += 2 * n - 1;
		}
		else if (n * n < dist && dist <= n * n + n)
		{
			count += 2 * n;
		}
		else if (n * n + n < dist && dist <= (n + 1) * (n + 1))
		{
			count += 2 * n + 1;
		}



		cout << count << "\n";
	}
}