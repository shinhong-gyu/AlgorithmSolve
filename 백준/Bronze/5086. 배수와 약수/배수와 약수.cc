#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		int a, b;
		cin >> a >> b;

		if (a == 0 && b == 0)
		{
			break;
		}

		if (b > a && b % a == 0)
		{
			cout << "factor" << "\n";
			continue;
		}
		else if (a > b && a % b == 0)
		{
			cout << "multiple" << "\n";
			continue;
		}
		else
		{
			cout << "neither" << "\n";
			continue;
		}
	}
}