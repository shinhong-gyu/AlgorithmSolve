#include <iostream>
#include <vector>

using namespace std;

#define ull unsigned long long

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ull N, K;
	cin >> N;
	cin >> K;

	ull s = 1, e = N * N, p = 0;

	while (s <= e)
	{
		ull mid = (s + e) / 2;

		ull count = 0;

		for (int i = 1; i <= N; i++)
		{
			count += min(mid / i, N);
		}

		if (count < K)
		{
			s = mid + 1;
		}
		else
		{
			p = mid;
			e = mid - 1;
		}
	}

	cout << p;
}