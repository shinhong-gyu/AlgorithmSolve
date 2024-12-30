#include <iostream>
#include <string>
using namespace std;

void isPalindrom(int pN)
{
	string temp = to_string(pN);
	int length = temp.length();

	for (int i = 0; i < length / 2; i++)
	{
		if (temp[i] == temp[length - i - 1])
		{
			continue;
		}
		cout << "no" << endl;
		return;
	}
	cout << "yes" << endl;
}

int main()
{
	int N;

	while (true)
	{
		cin >> N;

		if (N == 0) break;

		isPalindrom(N);
	}
}