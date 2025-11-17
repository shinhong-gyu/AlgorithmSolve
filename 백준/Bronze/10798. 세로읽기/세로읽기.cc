#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string temp;

	vector<string> arr;

	for (int i = 0; i < 5; i++)
	{
		cin >> temp;
		arr.push_back(temp);
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i < arr[j].size())
			{
				cout << arr[j][i];
			}
		}
	}
}