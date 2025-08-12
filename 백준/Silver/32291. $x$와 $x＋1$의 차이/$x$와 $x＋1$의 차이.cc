#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long X;

	cin >> X;


	long long K = 1 + X;

	vector<long long> answer;

	for (long long i = 1; i * i <= K; i++)
	{
		if (K % i == 0 && i <= X)
		{
			answer.push_back(i);

			if (K / i > 1 && K / i <= X && i * i != K)
			{
				answer.push_back(K / i);
			}
		}
	}

	sort(answer.begin(), answer.end());

	for (auto n : answer)
	{
		cout << n << " ";
	}

}
