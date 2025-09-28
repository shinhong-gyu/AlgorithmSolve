#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	int x_1, y_1;
	int x_2, y_2;
	int x_3, y_3;

	cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3;

	int answer = x_1 * y_2 + x_2 * y_3 + x_3 * y_1 - (x_2 * y_1 + x_3 * y_2 + x_1 * y_3);

	if (answer < 0)
	{
		answer = -1;
	}
	else if (answer != 0)
	{
		answer = 1;
	}

	cout << answer;

}