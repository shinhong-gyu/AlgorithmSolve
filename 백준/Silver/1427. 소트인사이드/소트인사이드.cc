#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string temp;
	cin >> temp;

	vector<int> v;

	for (auto c : temp)
	{
		v.push_back(c - '0');
	}

	for (int i = 0; i < v.size(); i++)
	{
		int max = -1;
		int idx = -1;
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[j] > max)
			{
				max = v[j];
				idx = j;
			}
		}

		if (idx == -1) break;
		if(v[i] > v[idx]) continue;
		int temp = v[i];
		v[i] = v[idx];
		v[idx] = temp;
	}

	for (auto n : v)
	{
		cout << n;
	}
	cout << "\n";
}