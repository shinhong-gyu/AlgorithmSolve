#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;

class Union
{
public:
	Union(int n)
	{
		parent.resize(n);

		iota(parent.begin(), parent.end(), 0);
	}

	int Find(int n)
	{
		if (parent[n] == -1)
		{
			return -1;
		}

		if (n == parent[n])
		{
			return n;
		}

		return parent[n] = Find(parent[n]);
	}

	void SetUnion(int i, int j)
	{
		int root_i = Find(i);
		int root_j = Find(j);

		if (root_i == -1 && root_j != -1)
		{
			UnionIsTree(root_j);
			return;
		}

		else if (root_j == -1 && root_i != -1)
		{
			UnionIsTree(root_i);
			return;
		}


		if (root_i != root_j)
		{
			parent[root_j] = root_i;
		}
	}

	bool IsUnion(int i, int j)
	{
		return Find(i) == Find(j);
	}

	void UnionIsTree(int n)
	{
		vector<int> temp;

		temp.push_back(n);

		int val = n;
		while (val != -1 && val != parent[val])
		{
			val = parent[val];

			if (val != -1)
			{
				temp.push_back(val);
			}
		}

		for (int i = 0; i < parent.size(); i++)
		{
			if (i != n && parent[i] == n)
			{
				temp.push_back(i);
			}
		}

		for (int i = 0; i < temp.size(); i++)
		{
			parent[temp[i]] = -1;
		}
	}

	int GetSetCount()
	{
		unordered_set<int> s;

		for (int i = 1; i < parent.size(); i++)
		{
			Find(i);
		}

		for (int i = 1; i < parent.size(); i++)
		{
			if (parent[i] != -1)
			{
				s.insert(parent[i]);
			}
		}

		return (int)s.size();
	}


	vector<int> parent;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int i = 1;
	while (1)
	{
		int N, M;

		cin >> N >> M;

		if (N == 0 && M == 0)
		{
			break;
		}

		Union uf(N + 1);

		int Case = 1;
		for (int n = 0; n < M; n++)
		{
			int A, B;
			cin >> A >> B;

			if (uf.IsUnion(A, B))
			{
				uf.UnionIsTree(A);
			}
			else
			{
				uf.SetUnion(A, B);
			}
		}

		int count = uf.GetSetCount();


		cout << "Case " << i << ": ";

		if (count > 1)
		{
			cout << "A forest of " << count << " trees.\n";
		}
		else if (count == 1)
		{
			cout << "There is one tree.\n";
		}
		else
		{
			cout << "No trees.\n";
		}

		i++;
	}
}