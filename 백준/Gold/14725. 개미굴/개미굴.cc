#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<string> prey;

class Node
{
public:
	map<string, Node*> next;
	bool isEnd;

	Node() : isEnd(false) {}

	~Node()
	{
		for (auto& p : next)
		{
			delete p.second;
		}
	}

	void insert(int idx)
	{
		string temp = prey[idx];

		if (temp == "e")
		{
			isEnd = true;
		}
		else
		{
			if (next.find(temp) == next.end())
			{
				next[temp] = new Node();
			}

			next[temp]->insert(idx + 1);
		}
	}

	void Print(int depth)
	{
		if (!isEnd)
		{
			string d;

			for (int i = 0; i < depth; i++)
			{
				d += "--";
			}

			for (auto& p : next)
			{
				cout << d << p.first << "\n";

				p.second->Print(depth + 1);
			}
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	Node* root = new Node();

	while (N--)
	{
		int K;
		cin >> K;

		prey.clear();
		prey.resize(K + 1);

		for (int i = 0; i < K; i++)
		{
			cin >> prey[i];
		}

		prey[K] = "e";

		root->insert(0);
	}

	root->Print(0);
}