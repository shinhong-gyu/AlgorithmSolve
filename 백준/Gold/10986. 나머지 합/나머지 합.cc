#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long count = 0;
	int N, M;
	cin >> N >> M;

	vector<long> S(N,0) ;
	vector<long> RestSum(M,0) ;
	cin >> S[0];

	for (int i = 1; i < N; i++)
	{
		int temp = 0;
		cin >> temp;
		S[i] = S[i - 1] + temp;
	}

	for (int i = 0; i < N; i++)
	{
		int temp = S[i] % M;
		if (temp == 0) count++;
		RestSum[temp]++;
	}

	for (int i = 0; i < M; i++)
	{
		if (RestSum[i] > 1)
			count = count + ((RestSum[i] * (RestSum[i] - 1)) / 2);
	}

	cout << count << "\n";
}