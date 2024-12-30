#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int temp = i;
		int sum = 0;
		while (temp > 0)
		{
			int rest = temp % 10;
			temp /= 10;
			sum += rest;
		}
		sum += i;
		if (sum == N) {
			cout << i << endl;
			return 0;
		}
	}
	cout << 0 << endl;
}