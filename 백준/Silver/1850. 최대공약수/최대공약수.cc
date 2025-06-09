#include <iostream>
#include <vector>

using namespace std;

#define ull unsigned long long

ull gcd(ull a, ull b)
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

	ull A, B;
	cin >> A >> B;

	if (B > A)
	{
		ull temp = A;
		A = B;
		B = temp;
	}

	ull gcdValue = gcd(A, B);

	for (ull i = 0; i < gcdValue; i++)
	{
		cout << 1;
	}
}