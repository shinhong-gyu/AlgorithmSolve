#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

class IntQueue
{
public:
	void push(int n)
	{
		q.push_back(n);
		p_back++;
	}

	void pop()
	{
		if (q.size() > 0)
		{
			cout << q[0] << endl;

			vector<int> temp;

			for (int i = 1; i <= p_back; i++)
			{
				temp.push_back(q[i]);
			}

			q = vector<int>();
			q = temp;

			p_back--;
		}
		else
		{
			cout << -1 << endl;
		}
	}

	void size()
	{
		cout << q.size() << endl;
	}

	void empty()
	{
		if (!q.empty())
		{
			cout << 0 << endl;
		}
		else
		{
			cout << 1 << endl;
		}
	}

	void front()
	{
		if (!q.empty())
		{
			cout << q[0] << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}

	void back()
	{
		if (!q.empty())
		{
			cout << q[p_back] << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}

private:
	vector<int> q;
	int stackSize = 0;
	int p_back = -1;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	IntQueue queue;

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
			queue.push(val);
		}
		else if (strcmp(temp.c_str(), "front") == 0)
		{
			queue.front();
		}
		else if (strcmp(temp.c_str(), "back") == 0)
		{
			queue.back();
		}

		else if (strcmp(temp.c_str(), "size") == 0)
		{
			queue.size();
		}
		else if (strcmp(temp.c_str(), "empty") == 0)
		{
			queue.empty();
		}
		else if (strcmp(temp.c_str(), "pop") == 0)
		{
			queue.pop();
		}
	}

}
