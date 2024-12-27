#include <iostream>

using namespace std;

int main()
{
	int temp = 0;
	int n;
	for (int i = 0; i < 5; i++)
	{
		cin >> n;
		temp += (n * n);
	}
	cout << temp % 10;
}