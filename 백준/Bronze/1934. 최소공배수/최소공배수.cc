#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
	if (a % b == 0)
	{
		return b;
	}

	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		int A, B;

		cin >> A >> B;

		if (B > A)
		{
			int temp = A;
			A = B;
			B = temp;
		}

		int lcm = (A * B) / gcd(A, B);

		cout << lcm << "\n";
	}
}