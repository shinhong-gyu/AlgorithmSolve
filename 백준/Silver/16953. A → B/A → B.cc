#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define ll long long

int makeAtoB(ll A, ll B, int depth)
{
	++depth;
	if (A == B)
	{
		return depth;
	}

	if (A > B)
	{
		return -1;
	}

	int multi = makeAtoB(A * 2, B, depth);
	int plusOne = makeAtoB(A * 10 + 1, B, depth);

	int retValue;

	if (multi == -1 && plusOne == -1)
	{
		return -1;
	}

	else if (multi == -1 )
	{
		return plusOne;
	}
	else if (plusOne == -1)
	{
		return multi;
	}

	return multi > plusOne ? plusOne : multi;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll A,B;
	cin >> A >> B;

	cout << makeAtoB(A,B,0) << endl;
}