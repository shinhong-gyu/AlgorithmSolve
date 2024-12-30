#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int take = 0;

	for (auto c : s)
	{
		int temp = c - 'A';

		if (temp >= 0 && temp <= 2) // 2
		{
			take += 3;
		}
		else if (temp >= 3 && temp <= 5) //3
		{
			take += 4;
		}
		else if (temp >= 6 && temp <= 8) // 4
		{
			take += 5;
		}
		else if (temp >= 9 && temp <= 11) // 5
		{
			take += 6;
		}
		else if (temp >= 12 && temp <= 14) // 6
		{
			take += 7;
		}
		else if (temp >= 15 && temp <= 18) // 7
		{
			take += 8;
		}
		else if (temp >= 19 && temp <= 21) //8
		{
			take += 9;
		}
		else if (temp >= 22 && temp <= 25) //9
		{
			take += 10;
		}
	}
	cout << take << endl;
}