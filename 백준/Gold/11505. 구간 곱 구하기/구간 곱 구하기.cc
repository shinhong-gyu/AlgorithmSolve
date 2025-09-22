#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#define ull unsigned long long
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;

	int k = ceil(log(N) / log(2));

	vector<ull> st((int)pow(2, k + 1), 1);

	int base = (int)pow(2, k);

	for (int i = 0; i < N; i++)
	{
		cin >> st[base + i];
	}

	int oper = M + K;

	int i = (int)pow(2, k + 1) - 1;

	while (i > 1)
	{
		st[i / 2] = st[i / 2] * st[i] % 1000000007;
		i--;
	}

	while (oper--)
	{
		ull a, b, c;
		cin >> a >> b >> c;

		if (a == 1)
		{
			int target = base + b - 1;

			st[target] = c;

			while (target > 1)
			{
				target /= 2;

				st[target] = st[target * 2] % 1000000007 * st[target * 2 + 1] % 1000000007;
			}
		}
		else
		{
			int start = base + b - 1;
			int end = base + c - 1;

			ull result = 1;
			while (start <= end)
			{
				if (start % 2 == 1)
				{
					result = result * st[start] % 1000000007;
				}

				if (end % 2 == 0)
				{
					result = result * st[end] % 1000000007;
				}

				start = (start + 1) / 2;
				end = (end - 1) / 2;
			}

			cout << result % 1000000007 << '\n';
		}
	}
}