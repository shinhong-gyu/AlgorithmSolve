#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<vector<char>> digits(9);
	map<char, int> power;

	int maxLenght = 0;
	for (int i = 1; i <= N; i++)
	{
		string temp;
		cin >> temp;

		for (int j = temp.length(); j >= 1; j--)
		{
			int digit = temp.length() - j;
			char c = temp[j - 1];

			power[c] += pow(10, digit);
		}
	}

	unsigned long long answer = 0;

	vector<int> v;

	for (auto& p : power)
	{
		v.push_back(p.second);
	}

	sort(v.begin(), v.end(), greater<int>());

	int num = 9;

	for (int n : v)
	{
		answer += num * n;
		num--;
	}

	cout << answer;
}