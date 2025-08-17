#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;

	if (N * 100 >= M)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}

}