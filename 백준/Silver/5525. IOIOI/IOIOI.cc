#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N;
	cin >> M;

	string pn = "";

	for (int i = 0; i < N; i++)
	{
		pn += "IO";
	}

	pn += "I";

	string input;
	cin >> input;

	int count = 0;
	string::size_type pos = 0;


	while (pos < input.size())
	{
		if (input.find(pn, pos) != string::npos)
		{
			count++;
			pos = input.find(pn, pos) + 1;
		}
		else
		{
			break;
		}
	}

	cout << count;
}