#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


bool compare(pair<int, pair<int, string>> p1, pair<int, pair<int, string>> p2)
{
	if (p1.second.first != p2.second.first)
	{
		return p1.second.first < p2.second.first;
	}
	else
	{
		return p1.first < p2.first;
	}
}

int main()
{
	int N;
	cin >> N;

	vector<pair<int, pair<int, string>>> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> v[i].second.first >> v[i].second.second;
		v[i].first = i;
	}

	sort(v.begin(),v.end(),compare);

	for (int i = 0; i < N; i++)
	{
		cout << v[i].second.first << " " << v[i].second.second << endl;
	}
}