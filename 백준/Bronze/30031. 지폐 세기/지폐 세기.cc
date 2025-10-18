#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int N;
	cin >> N;


	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int len,temp;
		cin >> len >> temp;

		switch (len)
		{
		case 136:
			sum += 1000;
			break;
		case 142:
			sum += 5000;
			break;
		case 148:
			sum += 10000;
			break;
		case 154:
			sum += 50000;
			break;

		}
	}
	cout << sum;
}