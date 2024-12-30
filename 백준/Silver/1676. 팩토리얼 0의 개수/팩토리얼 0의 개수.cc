#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int count = 0;

	while (N > 0)
	{
		if (N % 125 == 0)
		{
			count += 3;
		}
		else if (N % 25 == 0)
		{
			count += 2;
		}
		else if (N % 5 == 0)
		{
			count += 1;
		}
		N--;
	}
	cout << count << endl;
}