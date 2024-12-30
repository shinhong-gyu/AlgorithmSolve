#include "iostream"

using namespace std;

int gcd(int p1, int p2)
{
	if (p2 == 0) return p1;
	return gcd(p2, p1 % p2);
}

int gcm(int p1, int p2)
{
	return p1 * p2 / gcd(p1, p2);
}

int main()
{
	int a, b;
	cin >> a >> b;

	if(a < b) swap(a,b);

	cout << gcd(a,b) << endl;
	cout << gcm(a,b) << endl;
}