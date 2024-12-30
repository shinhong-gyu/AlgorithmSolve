#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	long long numerator = 1;
	long long denominator = 1;

	int l = k > n - k ? k : n - k;

	for (int i = 0; i < n - l; i++)
	{
		numerator *= (n - i);
		denominator *= (i + 1);
	}
	cout << numerator / denominator << "\n";
}