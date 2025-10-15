#include <iostream>
#include <string>

using namespace std;

string str;

int SimilarPalindrome(int s, int e)
{
	while (s <= e)
	{
		if (s == e)
		{
			return 1;
		}

		if (str[s] == str[e])
		{
			if (e - s == 1)
			{
				return 1;
			}

			s++;
			e--;
		}
		else
		{
			return 2;
		}
	}

	return 2;
}


void JudgePalindrome()
{
	int s = 0, e = str.length() - 1;
	bool similar = false;
	int answer = 2;
	while (s <= e)
	{
		if (s == e)
		{
			answer = 0;
			break;
		}

		if (str[s] == str[e])
		{
			if (e - s == 1)
			{
				answer = 0;
				break;
			}

			s++;
			e--;
		}
		else if (str[s] != str[e])
		{
			if (str[s + 1] == str[e])
			{
				answer = SimilarPalindrome(s + 1, e);
			}

			if (str[s] == str[e - 1])
			{
				if (answer != 1)
				{
					answer = SimilarPalindrome(s, e - 1);
				}
			}

			break;
		}
	}

	cout << answer << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--)
	{
		cin >> str;

		JudgePalindrome();
	}
}