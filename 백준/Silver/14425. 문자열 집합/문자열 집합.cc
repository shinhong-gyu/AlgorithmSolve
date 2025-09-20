#include <iostream>

using namespace std;

class Node
{
public:

	Node* next[26];
	bool isEnd;

	Node() : isEnd(false)
	{
		fill(next, next + 26, nullptr);
	}

	~Node()
	{
		for (auto& child : next)
		{
			delete child;
		}
	}

	void insert(const char* key)
	{
		if (*key == 0)
		{
			isEnd = true;
		}
		else
		{
			int next_idx = *key - 'a';

			if (next[next_idx] == nullptr)
			{
				next[next_idx] = new Node();
			}

			next[next_idx]->insert(key + 1);
		}
	}

	Node* find(const char* key)
	{
		if (*key == 0)
		{
			return this;
		}

		int next_idx = *key - 'a';

		if (next[next_idx] == nullptr)
		{
			return nullptr;
		}

		return next[next_idx]->find(key + 1);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	Node* root = new Node();

	while (n > 0)
	{
		char text[501];
		cin >> text;
		root->insert(text);
		n--;
	}

	int count = 0;

	while (m > 0)
	{
		char text[501];
		cin >> text;

		Node* result = root->find(text);

		if (result && result->isEnd)
		{
			count++;
		}

		m--;
	}

	cout << count << "\n";
}
