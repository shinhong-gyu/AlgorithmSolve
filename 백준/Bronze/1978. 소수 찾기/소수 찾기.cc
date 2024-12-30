#include "iostream"

using namespace std;

int main()
{
	int N;
	cin >> N;

	int count = 0;

	while (N--)
	{
		int temp;
		cin >> temp;
		bool prime = true;
		for (int i = 2; i < temp; i++)
		{
			if (temp % i == 0)
			{
				prime = false;
				break;
			}
		}
		if (temp != 1 && prime) count++;
	}
	cout << count << endl;
}