#include <unordered_set>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<string> v;

	v.push_back("c=");
	v.push_back("c-");
	v.push_back("dz=");
	v.push_back("d-");
	v.push_back("lj");
	v.push_back("nj");
	v.push_back("s=");
	v.push_back("z=");

	string str;
	cin >> str;

	for (const string& s : v)
	{
		auto idx = str.find(s);

		while (idx != string::npos)
		{
			str.replace(str.begin() + idx, str.begin() + idx + s.length(), "/");
			idx = str.find(s);
		}
	}

	cout << str.length();
}
