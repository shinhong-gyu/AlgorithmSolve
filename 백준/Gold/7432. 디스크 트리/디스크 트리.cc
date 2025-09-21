#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

vector<string> dir;

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
		if (dir[idx] == "e")
		{
			isEnd = true;
		}
		else
		{
			isEnd = false;

			if (next.find(dir[idx]) == next.end())
			{
				next[dir[idx]] = new Node();
			}

			next[dir[idx]]->insert(idx + 1);
		}
	}

	void Print(int depth)
	{
		string indent;

		for (int i = 0; i < depth; i++)
		{
			indent += " ";
		}

		for (auto& p : next)
		{
			cout << indent << p.first << "\n";

			p.second->Print(depth + 1);
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
		string temp;
		cin >> temp;

		stringstream ss(temp);
		string a;

		dir.clear();

		while (getline(ss, a, '\\'))
		{
			dir.push_back(a);
		}

		dir.push_back("e");

		root->insert(0);
	}

	root->Print(0);
}