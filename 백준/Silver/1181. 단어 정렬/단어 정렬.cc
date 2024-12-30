#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string s1, string s2)
{
	if (s1.length() != s2.length())
		return s1.length() < s2.length();
	else
	{
		return s1 < s2;
	}
}

int main()
{
	int N;
	cin >> N;

	vector<string> strArray;
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;

		if (find(strArray.begin(), strArray.end(), temp) == strArray.end()) strArray.push_back(temp);
	}

	sort(strArray.begin(), strArray.end(), compare);

	for (int i = 0; i < strArray.size(); i++)
	{
		cout << strArray[i] << endl;
	}
}