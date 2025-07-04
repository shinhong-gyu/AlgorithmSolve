#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int value[10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int N, end, begin;

	vector<pair<int, int>> schedule;

	cin >> N ;

	for (int i = 0; i < N; i++)
	{
		cin >> begin >> end;
		schedule.push_back(make_pair(end, begin));
	}
	
	sort(schedule.begin(), schedule.end());
	
	int time = schedule[0].first;
	int count = 1;
	for (int i = 1 ;i < N; i++) 
	{
		if (time <= schedule[i].second )
		{
			count++;
			time = schedule[i].first;
		}
	}

	cout << count;
}