#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		int q = 0;
		int d = 0;
		int n = 0;
		int p = 0;

		q = N / 25;
		N %= 25;
		d = N / 10;
		N %= 10;
		n = N / 5;
		N %= 5;
		p = N;

		cout << q << " " << d << " " << n << " " << p << "\n";
	}
}