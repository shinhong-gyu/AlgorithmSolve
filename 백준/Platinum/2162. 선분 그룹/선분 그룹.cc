#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>
#include <algorithm>

using namespace std;

struct Point
{
	double x, y;
};

struct Segment
{
	Point A, B;

	double operator*(const Point& p)
	{
		double result = (A.x * B.y + B.x * p.y + p.x * A.y) - (B.x * A.y + p.x * B.y + A.x * p.y);

		if (result < 0)
		{
			return -1;
		}
		else if (result > 0)
		{
			return 1;
		}

		return result;
	}

	bool equation(double x, double y) const
	{
		int minY, maxY;
		int minX, maxX;

		minY = min(A.y, B.y);
		maxY = max(A.y, B.y);

		minX = min(A.x, B.x);
		maxX = max(A.x, B.x);

		if (A.y - B.y == 0)
		{
			return (y == A.y) && (x >= minX && x <= maxX);

		}
		else if (A.x - B.x == 0)
		{
			return (x == A.x) && (y >= minY && y <= maxY);
		}
		else
		{
			double delta = (A.y - B.y) / (A.x - B.x);

			if (x >= minX && maxX >= x && y >= minY && y <= maxY)
			{
				const double EPSILON = 1e-9;
				return abs(delta * (x - A.x) - (y - A.y)) < EPSILON;
			}

			return false;
		}
	}

	bool IsCross(Segment& s)
	{
		// C,D가 하나라도 AB 위에 있다면 교차
		if (this->equation(s.A.x, s.A.y) || this->equation(s.B.x, s.B.y))
		{
			return true;
		}


		// A,B가 하나라도 CD 위에 있다면 교차
		if (s.equation(this->A.x, this->A.y) || s.equation(this->B.x, this->B.y))
		{
			return true;
		}

		// AB에 대해서 C,D가 왼쪽 오른쪽에 있으면서 CD에 대해서 A,B가 왼쪽 오른쪽에 있으면 교차

		Segment AB = { this->A,this->B };

		int ABC = AB * s.A;
		int ABD = AB * s.B;

		int CDA = s * AB.A;
		int CDB = s * AB.B;

		if (ABC == 0 || ABD == 0 || CDA == 0 || CDB == 0)
		{
			return false;
		}

		// CD 오/왼에 A,B가 있을 때
		if (CDA*CDB < 0)
		{
			// C,D 도 AB의 왼쪽/오른쪽에 있다면 교차
			if (ABC *ABD<0)
			{
				return true;
			}
		}

		return false;
	}
};

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
			parent[root_j] = root_i;
		}
	}

	bool IsUnion(int i, int j)
	{
		return Find(i) == Find(j);
	}

	vector<int> parent;
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<Segment> s(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> s[i].A.x >> s[i].A.y >> s[i].B.x >> s[i].B.y;
	}

	Union uf(N + 1);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i != j && s[i].IsCross(s[j]))
			{
				if (!uf.IsUnion(i, j))
				{
					uf.SetUnion(i, j);
				}
			}
		}

	}

	unordered_map<int, int> m;

	for (int i = 1; i <= N; i++)
	{
		m[uf.Find(i)]++;
	}

	cout << m.size() << endl;

	int answer = -1;

	for (auto p : m)
	{
		answer = max(answer, p.second);
	}

	cout << answer;
}