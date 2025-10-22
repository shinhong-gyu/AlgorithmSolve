#include <iostream>
#include <vector>
#include <cmath>
#define ull unsigned long long

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	int k = (int)ceil(log(N) / log(2));

	vector<ull> st((int)pow(2, k + 1), 0);

	int base = pow(2, k);

	while (M--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0)
		{
			int L = min(b, c);
			int R = max(b, c);

			int start = base + L - 1;
			int end = base + R - 1;

			ull result = 0;

			while (start <= end)
			{
				if (start % 2 == 1)
				{
					result += st[start];
				}

				if (end % 2 == 0)
				{
					result += st[end];
				}

				start = (start + 1) / 2;
				end = (end - 1) / 2;
			}

			cout << result << "\n";
		}
		else
		{
			int target = base + b - 1;
			ull origin = st[target];

			st[target] = c;

			int delta = c - origin;
			while (target != 1)
			{
				st[target / 2] += delta;
				target /= 2;
			}
		}
	}
}
