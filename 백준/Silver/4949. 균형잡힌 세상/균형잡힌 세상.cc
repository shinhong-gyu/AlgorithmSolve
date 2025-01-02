#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> strArray;
	stack<char> parentheses;

	while (true)
	{
		string temp;
		getline(cin, temp);

		if (strcmp(temp.c_str(), ".") == 0)
		{
			break;
		}
		strArray.push_back(temp);
	}

	for (auto str : strArray)
	{
		bool isBalanced = true;
		parentheses = stack<char>();
		for (auto c : str)
		{
			if (c == '(' || c == '[')
			{
				parentheses.push(c);
			}
			else if (c == ')')
			{
				if (parentheses.empty() || parentheses.top() != '(')
				{
					isBalanced = false;
					break;
				}
				else
				{
					parentheses.pop();
				}
			}
			else if (c == ']')
			{
				if (parentheses.empty() || parentheses.top() != '[')
				{
					isBalanced = false;
					break;
				}
				else
				{
					parentheses.pop();
				}
			}
		}

		if (!parentheses.empty())
		{
			isBalanced = false;
		}

		if (isBalanced)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
}
