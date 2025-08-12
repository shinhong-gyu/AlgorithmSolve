#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	vector<long long> xCord(N);
	vector<long long> yCord(N);

	for (int i = 0; i < N; i++)
	{
		cin >> xCord[i] >> yCord[i];
	}

	long long pre = 0;
	long long post = 0;

	for (int i = 0; i < N; i++)
	{
		if (i < N - 1)
		{
			pre += xCord[i] * yCord[i + 1];
			post += yCord[i] * xCord[i + 1];
		}
		else
		{
			pre += xCord[i] * yCord[0];
			post += yCord[i] * xCord[0];
		}
	}

	printf("%.1f", 0.5 * (double)std::abs(pre - post));
}