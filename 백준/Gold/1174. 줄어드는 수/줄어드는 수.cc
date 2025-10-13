#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

#define ull unsigned long long

int N;
string cur = "";
ull maxDecs = 9876543210;
ull answer;

vector<ull> decs;

void solve()
{
	if (cur.length() >= 1)
	{
		for (int i = 0; i <= 9; i++)
		{
			if (cur.back() - '0' > i)
			{
				cur += to_string(i);
				solve();
				decs.push_back(stoull(cur));
				cur.pop_back();
			}
		}
	}
	else
	{
		for (int i = 0; i <= 9; i++)
		{
			cur += to_string(i);
			solve();
			decs.push_back(stoull(cur));
			cur.pop_back();
		}
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	solve();

	sort(decs.begin(), decs.end());

	if (N > decs.size())
	{
		cout << -1;
	}
	else
	{
		cout << decs[N - 1];
	}
}