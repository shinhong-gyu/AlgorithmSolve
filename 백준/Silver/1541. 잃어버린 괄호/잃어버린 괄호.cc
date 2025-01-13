#include <iostream>
#include <string>

using namespace std;

int main()
{
	string exp;
	cin >> exp;
	int minusCount = 0;
	int total = 0;
	bool toggle = false;
	string temp;
	for (auto c : exp)
	{
		if (c != '-' && c != '+')
		{
			temp += c;
			continue;
		}
		else if (c == '-')
		{
			if (minusCount == 0)
			{
				minusCount++;
				total += stoi(temp);
				temp = "";
				toggle = true;
				continue;
			}
			toggle = true;
		}
		if (toggle)
		{
			total -= stoi(temp);
			temp = "";
		}
		else
		{
			total += stoi(temp);
			temp = "";
		}
	}
	if (toggle)
	{
		total -= stoi(temp);
	}
	else
	{
		total += stoi(temp);
	}
	cout << total << "\n";
}