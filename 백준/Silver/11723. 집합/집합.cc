#include <iostream>
#include <unordered_set>
#include <string>
#include <string.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	unordered_set<int> S;

	while (N--)
	{
		string temp;
		int a;
		cin >> temp;

		if (strcmp(temp.c_str(), "add") == 0)
		{
			cin >> a;
			S.insert(a);
		}
		else if (strcmp(temp.c_str(), "remove") == 0)
		{
			cin >> a;
			S.erase(a);
		}
		else if (strcmp(temp.c_str(), "check") == 0)
		{
			cin >> a;
			if (S.find(a) == S.end())
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << 1 << "\n";
			}

		}
		else if (strcmp(temp.c_str(), "toggle") == 0)
		{
			cin >> a;
			if (S.find(a) == S.end())
			{
				S.insert(a);
			}
			else
			{
				S.erase(a);
			}
		}
		else if (strcmp(temp.c_str(), "all") == 0)
		{
			S = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
		}
		else if (strcmp(temp.c_str(), "empty") == 0)
		{
			S = unordered_set<int>();
		}
	}
}
