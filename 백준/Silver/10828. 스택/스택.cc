#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class IntStack
{
public:
	void push(int n)
	{
		s.push_back(n);
		p_Top++;
	}

	void pop()
	{
		if (s.size() > 0)
		{
			cout << s[p_Top] << endl;
			s.pop_back();
			p_Top--;
		}
		else
		{
			cout << -1 << endl;
		}
	}

	void size()
	{
		cout << s.size() << endl;
	}

	void empty()
	{
		if (!s.empty())
		{
			cout << 0 << endl;
		}
		else
		{
			cout << 1 << endl;
		}
	}

	void top()
	{
		if (!s.empty())
		{
			cout << s[p_Top] << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}

private:
	vector<int> s;
	int stackSize = 0;
	int p_Top = -1;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	IntStack stack;

	int N;
	cin >> N;

	while (N--)
	{
		string temp;
		int val;

		cin >> temp;

		if (strcmp(temp.c_str(), "push") == 0)
		{
			cin >> val;
			stack.push(val);
		}
		else if (strcmp(temp.c_str(), "top") == 0)
		{
			stack.top();
		}
		else if (strcmp(temp.c_str(), "size") == 0)
		{
			stack.size();
		}
		else if (strcmp(temp.c_str(), "empty") == 0)
		{
			stack.empty();
		}
		else if (strcmp(temp.c_str(), "pop") == 0)
		{
			stack.pop();
		}
	}

}
