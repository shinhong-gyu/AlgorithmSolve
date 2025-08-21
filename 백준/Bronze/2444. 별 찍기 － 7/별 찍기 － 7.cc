#include <iostream>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;


	for (int i = 0; i < N; i++)
	{

		for (int j = N - 1; j > i; j--)
		{
			cout << " ";
		}
		for (int j = 2 * i + 1; j > 0; j--)
		{
			cout << "*";
		}



		cout << "\n";
	}

	for (int i = N - 2; i >= 0; i--)
	{
		for (int j = N - 1; j > i; j--)
		{
			cout << " ";
		}
		for (int j = 2 * i + 1; j > 0; j--)
		{
			cout << "*";
		}

		cout << "\n";
	}
}
