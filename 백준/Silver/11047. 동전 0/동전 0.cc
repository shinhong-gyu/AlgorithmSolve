#include <iostream>
#include <vector>


using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> wallet(N);
	int count = 0;
	for (int i = N - 1; i >= 0; i--)
	{

		cin >> wallet[i];

	}

	for (auto e : wallet)
	{
		if (e <= K)
		{
			count += (K / e);
			K %= e;
		}
	}
	cout << count << "\n";
}