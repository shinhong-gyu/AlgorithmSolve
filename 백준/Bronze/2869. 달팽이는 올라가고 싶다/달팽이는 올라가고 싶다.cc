#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int A, B, V;
	cin >> A >> B >> V;

	double result = (double)(V - B) / (A - B);

	cout << (long long)ceil(result) << endl;;
}