#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	int S[100001] = {};

	for (int k = 1; k <= N; k++)
	{
		int temp;
		cin >> temp;
		S[k] = S[k - 1] + temp;
	}

	for (int k = 0; k < M; k++)
	{
		int i, j;
		cin >> i >> j;
		cout << S[j] - S[i - 1] << "\n";
	}
}