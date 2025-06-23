#include <iostream>
#include <cmath>

using namespace std;

int A, B, C;

int DivideAndConquer(int M)
{
	if (M == 0)
	{
		return 1;
	}

	if (M == 1)
	{
		return A % C;
	}

	long long temp = DivideAndConquer(M / 2);

	if (M % 2 == 1)
	{
		return (((temp * temp) % C) * (A % C)) % C;
	}
	else
	{

		return (temp * temp) % C;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;

	cout << DivideAndConquer(B);
}