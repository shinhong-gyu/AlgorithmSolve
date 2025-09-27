#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#define ull unsigned long long 

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ull N;
	cin >> N;

	vector<ull> dice(6);

	for (int i = 0; i < 6; i++)
	{
		cin >> dice[i];
	}

	if (N == 1)
	{
		cout << accumulate(dice.begin(), dice.end(), 0) - *max_element(dice.begin(), dice.end());
		return 0;
	}

	ull answer = 0;

	// dice에서 인접한 3개의 면의 수의 최대
	ull threeMin;

	threeMin = min(dice[0] + dice[1] + dice[2], dice[0] + dice[3] + dice[4]);
	threeMin = min(threeMin, dice[0] + dice[1] + dice[3]);
	threeMin = min(threeMin, dice[0] + dice[2] + dice[4]);
	threeMin = min(threeMin, dice[5] + dice[1] + dice[2]);
	threeMin = min(threeMin, dice[5] + dice[1] + dice[3]);
	threeMin = min(threeMin, dice[5] + dice[2] + dice[4]);
	threeMin = min(threeMin, dice[5] + dice[3] + dice[4]);

	ull twoMin;

	twoMin = min(dice[0] + dice[1], dice[0] + dice[2]);
	twoMin = min(twoMin, dice[0] + dice[3]);
	twoMin = min(twoMin, dice[0] + dice[4]);
	twoMin = min(twoMin, dice[1] + dice[2]);
	twoMin = min(twoMin, dice[1] + dice[3]);
	twoMin = min(twoMin, dice[1] + dice[5]);
	twoMin = min(twoMin, dice[2] + dice[4]);
	twoMin = min(twoMin, dice[2] + dice[5]);
	twoMin = min(twoMin, dice[3] + dice[4]);
	twoMin = min(twoMin, dice[3] + dice[5]);
	twoMin = min(twoMin, dice[4] + dice[5]);

	ull oneMin = *min_element(dice.begin(), dice.end());

	cout << threeMin * 4 + (twoMin * ((N - 1) * 4 + (N - 2) * 4)) + (oneMin * ((N - 2) * (N - 2) + (N - 1) * (N - 2) * 4));
}