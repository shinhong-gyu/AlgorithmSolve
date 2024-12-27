#include <iostream>
#include <string>

using namespace std;



int main()
{
	long long A, B, C;
	cin >> A >> B >> C;
	long long mulSum = A * B * C;
	int count[10] = { 0 };
	string temp = to_string(mulSum);

	for (auto c : temp)
	{
		int ctos = c - '0';
		count[ctos]++;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << count[i] << endl;
	}
}