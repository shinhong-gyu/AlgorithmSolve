#include <iostream>
#include <vector>
#include <cmath>
#include <climits>


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int k = (int)ceil(log(N) / log(2));

	vector<pair<int, int>> st((int)pow(2, k + 1));

	for (int i = 1; i < st.size(); i++)
	{
		st[i] = { INT_MAX,0 };
	}

	int base = pow(2, k);

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		st[i + base] = { temp, i + 1 };
	}

	int i = base + N - 1;

	while (i != 1)
	{
		st[i / 2] = min(st[i], st[i / 2]);
		i--;
	}

	int Q;
	cin >> Q;

	while (Q--)
	{
		int query, a, b;
		cin >> query >> a >> b;

		if (query == 1)
		{
			int target = base + a - 1;

			st[target] = { b,a };

			while (target != 1)
			{
				if (target % 2 == 1)
				{
					st[target / 2] = min(st[target - 1], st[target]);
				}
				else
				{
					st[target / 2] = min(st[target + 1], st[target]);
				}

				target /= 2;
			}

		}
		else
		{
			int L = min(a, b);
			int R = max(a, b);

			int start = base + a - 1;
			int end = base + b - 1;

			pair<int, int> result = { INT_MAX,0 };

			while (start <= end)
			{
				if (start % 2 == 1)
				{
					result = min(st[start], result);
				}

				if (end % 2 == 0)
				{
					result = min(st[end], result);
				}

				start = (start + 1) / 2;
				end = (end - 1) / 2;
			}

			cout << result.second << "\n";
		}
	}

}