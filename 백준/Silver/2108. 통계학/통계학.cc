#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.second == p2.second)
	{
		return p1.first < p2.first;
	}
	return p1.second > p2.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> a(N);
	map<int, int> m;

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < N; i++)
	{
		m[a[i]]++;
	}

	vector<pair<int, int>> v(m.begin(), m.end());

	sort(v.begin(), v.end(), compare);

	int freq = N > 1 && v[0].second == v[1].second ? v[1].first : v[0].first;

	cout << round(accumulate(a.begin(), a.end(), 0) / (double)N) + 0.0 << endl;
	cout << a[N / 2] << endl;
	cout << freq << endl;
	cout << a[N - 1] - a[0] << endl;
}
