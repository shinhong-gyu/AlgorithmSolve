#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;



string prefix;
bool bCheck = true;

struct Node
{
	Node* next[26];

	Node()
	{
		fill(next, next + 26, nullptr);
	}

	~Node()
	{
		for (auto& n : next)
		{
			delete n;
		}
	}

	void Insert(const char* key)
	{
		if (*key == 0)
		{
			return;
		}
		else
		{
			int idx = *key - 'a';

			if (next[idx] == nullptr)
			{
				next[idx] = new Node();

				if (bCheck)
				{
					prefix += *key;
					bCheck = false;
				}
			}
			else
			{
				if (bCheck)
				{
					prefix += *key;
				}
			}

			next[idx]->Insert(key + 1);
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	unordered_map<string, int> m;

	Node* root = new Node();

	while (N--)
	{
		char str[11];
		cin >> str;

		string temp(str);
		m[temp]++;

		bCheck = true;
		prefix = "";

		root->Insert(str);

		if (prefix == temp && m[temp] > 1)
		{
			cout << prefix << m[temp] << "\n";
		}
		else
		{
			cout << prefix << "\n";
		}
	}

	delete root;
}