#include <iostream>

using namespace std;

int N;
unsigned long long B;

class Matrix
{
public:
	Matrix operator*(const Matrix& m)
	{
		Matrix ret = Matrix();

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				for (int k = 0; k < N; k++)
				{
					ret.A[i][j] += (this->A[i][k] * m.A[k][j]);
					ret.A[i][j] %= 1000;
				}
			}
		}

		return ret;
	}

	int A[5][5] = { 0 };
};

Matrix origin;

Matrix DnC(unsigned long long n)
{
	if (n == 1)
	{
		return origin;
	}
	else
	{
		Matrix temp = DnC(n / 2);
		Matrix result = temp * temp;

		if (n % 2 == 1)
		{
			result = result * origin;
		}

		return result;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> B;


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> origin.A[i][j];
		}
	}

	Matrix answer = DnC(B);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << answer.A[i][j] % 1000 << " ";
		}
		cout << "\n";
	}
}