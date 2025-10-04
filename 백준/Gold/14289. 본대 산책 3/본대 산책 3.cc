#include <iostream>
#include <vector>


using namespace std;


using Matrix = vector<vector<long long>>;

const long long MOD = 1000000007;

int N, M;

Matrix MatMul(const Matrix& m1, const Matrix& m2)
{
	Matrix ret(m1.size(), vector<long long>(m1.size()));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				ret[i][j] = (ret[i][j] + m1[i][k] * m2[k][j]) % MOD;
			}
		}
	}

	return ret;
}

Matrix MatPow(Matrix m, long long D)
{
	Matrix ret(m.size(), vector<long long>(m.size()));

	for (int i = 0; i < N; i++)
	{
		ret[i][i] = 1;
	}

	while (D > 0)
	{
		if (D % 2 == 1)
		{
			ret = MatMul(ret, m);
		}

		m = MatMul(m, m);

		D /= 2;
	}

	return ret;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	Matrix edges(N + 1, vector<long long>(N + 1));

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;

		edges[a - 1][b - 1] = 1;
		edges[b - 1][a - 1] = 1;
	}

	int D;
	cin >> D;

	Matrix res = MatPow(edges, D);

	cout << res[0][0];
}