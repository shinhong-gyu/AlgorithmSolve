#include <iostream>
#include "cmath"

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M = 1234567891;
	int r = 31;
	long long hash = 0;
	int N;
	cin >> N;

	char* s = new char[N + 1];

	cin >> s;

	for (int i = 0; i < N; i++)
	{
		hash += (s[i] - 'a' + 1) * pow(r, i);
	}
	cout << hash << endl;
}