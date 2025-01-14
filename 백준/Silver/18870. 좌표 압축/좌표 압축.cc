#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	unordered_set<long long> nums;
	vector<long long> v(N);
	map<long long, int> m;

	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
		nums.insert(v[i]);
	}

	vector<long long> temp(nums.begin(), nums.end());

	sort(temp.begin(), temp.end());

	for (int i = 0; i < temp.size(); i++)
	{
		m[temp[i]] = i;
	}

	for (auto n : v)
	{
		cout << m[n] << " ";
	}
	cout << endl;
}
