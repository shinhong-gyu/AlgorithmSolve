#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> level(N);

	for (int i = 0; i < N; i++)
	{
		cin >> level[i];
	}

	sort(level.begin(), level.end());

	int trim = round((double)N * 0.15);
	double sum = 0;

	for (int i = trim; i < N - trim; i++)
	{
		sum += level[i];
	}
	if (N == 0)
	{
		cout << 0 << endl;
	}
	else
	{
		cout << round(sum / (N - trim * 2)) << endl;
	}
}