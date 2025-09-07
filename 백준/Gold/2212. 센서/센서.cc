#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int K;
	cin >> K;

	vector<int> sensor(N);

	vector<int> between;

	for (int i = 0; i < N; i++)
	{
		cin >> sensor[i];
	}

	sort(sensor.begin(), sensor.end());

	for (int i = 1; i < N; i++)
	{
		between.push_back(sensor[i] - sensor[i - 1]);
	}

	sort(between.begin(), between.end(), greater<int>());

	int answer = 0;
	for (int i = K - 1; i < between.size(); i++)
	{
		answer += between[i];
	}

	cout << answer;

}