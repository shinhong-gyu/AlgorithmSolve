#include <iostream>
#include <vector>
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

	// {시작,끝}
	vector<pair<int, int>> lesson(N);

	for (int i = 0; i < N; i++)
	{
		cin >> lesson[i].first >> lesson[i].second;
	}

	sort(lesson.begin(), lesson.end());

	int room = 1;

	priority_queue<int,vector<int>,greater<int>> endTime;
	endTime.push(lesson[0].second);
	int answer = 1;

	for (int i = 1; i < N; i++)
	{
		if (lesson[i].first < endTime.top())
		{
			answer++;
		}
		else
		{
			endTime.pop();
		}

		endTime.push(lesson[i].second);
	}

	cout << answer;
}