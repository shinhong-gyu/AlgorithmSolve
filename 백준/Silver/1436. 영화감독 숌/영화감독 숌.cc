#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;

	string temp;

	for (int i = 665; i++;)
	{
		temp = to_string(i);

		if (temp.find("666") != string::npos)
		{
			N--;
		}
		if (N == 0)
		{
			cout << temp << endl;
			return 0;
		}
	}
}