#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cctype>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		string commands;
		cin >> commands;

		int n;
		cin >> n;

		deque<int> d = deque<int>();

		string temp;
		cin >> temp;

		string temp2 = "";
		for (auto c : temp)
		{
			if (isdigit(c))
			{
				temp2 += c;
			}
			else
			{
				if (!temp2.empty())
				{
					d.push_back(stoi(temp2));
					temp2 = "";
				}
			}
		}

		bool bError = false;
		int rCount = 0;
		bool reverse = false;
		for (auto command : commands)
		{
			if (command == 'R')
			{
				reverse = !reverse;
			}
			else
			{
				if (d.empty())
				{
					bError = true;
					break;
				}
				if (reverse)
				{
					d.pop_back();
				}
				else
				{
					d.pop_front();
				}
			}

		}

		if (bError)
		{
			cout << "error\n";
			continue;
		}

		cout << "[";
		
		if (reverse)
		{
			for (int i = d.size() - 1; i >= 0; i--)
			{
				cout << d[i] << (0 < i ? "," : "");
			}
		}
		else
		{
			for (int i = 0; i < d.size(); i++)
			{
				cout << d[i] << (d.size() - 1 > i ? "," : "");
			}
		}
		cout << "]\n";
	}
}