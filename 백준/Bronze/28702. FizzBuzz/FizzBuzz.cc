#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<string> strArray(3);

	cin >> strArray[0];
	cin >> strArray[1];
	cin >> strArray[2];

	int lastNum;
	int idx;
	for (int i = 0; i < 3; i++)
	{
		if (atoi(strArray[i].c_str()) != 0)
		{
			lastNum = atoi(strArray[i].c_str());
			idx = i;
		}
	}
	int temp = lastNum + 3 - idx;

	if (temp % 5 == 0 && temp % 3 == 0) cout << "FizzBuzz" << endl;
	else if (temp % 3 == 0) cout << "Fizz" << endl;
	else if (temp % 5 == 0) cout << "Buzz" << endl;
	else cout << temp << endl;
}