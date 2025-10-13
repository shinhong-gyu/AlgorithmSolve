#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int count = 0;



	while (N--)
	{
		string str;
		cin >> str;
		bool check = true;
		unordered_map<char, bool> m;

		for (int i = 0; i < str.length(); i++)
		{
			char c = str[i];

			if (m[c])
			{
				check = false;
				break;
			}

			if (i < str.length() - 1)
			{
				if (c == str[i + 1])
				{
					continue;
				}
				else
				{
					m[c] = true;
				}
			}
		}

		if (check)
		{
			count++;
		}
	}

	cout << count;
}
