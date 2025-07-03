#include <iostream>

using namespace std;

#define ull unsigned long long

int main()
{

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ull T, N;

	cin >> T;

	while (T--)
	{
		cin >> N;
		ull k = N * N;
		cout << k << '\n';
	}
}