#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Union
{
public:
	Union(int n)
	{
		parent.resize(n);
		size.resize(n, 1);
		iota(parent.begin(), parent.end(), 0);
	}

	int Find(int n)
	{
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

		if (root_i != root_j)
		{
			if (root_i < root_j)
			{
				parent[root_j] = root_i;
			}
			else
			{
				parent[root_i] = root_j;
			}

		}
	}

	bool IsUnion(int i, int j)
	{
		return Find(i) == Find(j);
	}

	int GetSize(int n)
	{
		int root = Find(n);
		return size[root];
	}

	vector<int> parent;
	vector<int> size;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int G;
	cin >> G;
	int P;
	cin >> P;

	vector<int> Doking(P + 1);

	for (int i = 1; i <= P; i++)
	{
		cin >> Doking[i];
	}

	Union uf(G + 1);

	if (P == 1)
	{
		cout << 1;
		return 0;
	}

	for (int i = 1; i <= P; i++)
	{
		int root = uf.Find(Doking[i]);

		if (root == 0)
		{
			cout << i - 1 << "\n";
			return 0;
		}

		uf.SetUnion(root, root - 1);
	}

	cout << P << "\n";
}