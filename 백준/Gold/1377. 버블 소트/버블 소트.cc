#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> A;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		A.push_back({ temp,i });
	}

	sort(A.begin(), A.end());

	int max = 0;

	for (int i = 0; i < N; i++)
	{
		int minus = A[i].second - i;

		if (minus > max) max = minus;
	}

	cout << max + 1 << endl;


}