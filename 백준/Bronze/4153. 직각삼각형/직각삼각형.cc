#include <iostream>

using namespace std;

int main()
{
	long long a, b, c;

	while (true)
	{
		cin >> a >> b >> c;

		if (a > b) swap(a, b);
		if (a > c) swap(a, c);
		if (b > c) swap(b, c);

		if (a == 0 && b == 0 && c == 0) break;
		if (a * a + b * b == c * c) cout << "right" << endl;
		else cout << "wrong" << endl;
	}
}