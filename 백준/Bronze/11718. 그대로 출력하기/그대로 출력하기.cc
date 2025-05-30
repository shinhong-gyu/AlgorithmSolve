#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		string temp;

		getline(cin,temp);
		
		if (temp.size() == 0)
		{
			break;
		}

		cout << temp << "\n";
	}

}
