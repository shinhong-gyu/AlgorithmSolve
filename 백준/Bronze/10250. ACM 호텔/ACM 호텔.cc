#include "iostream"

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

	int T, H, W, N;
	cin >> T;
	while (T--)
	{
		cin >> H >> W >> N;

		int floor = 0;
		int room = 1;

		for (int i = 0; i < N; i++)
		{
			floor++;
			if (floor > H)
			{
				floor = 1;
				room++;
				if (room > W)
				{
					return 0;
				}
			}
		}
		if (room < 10)
		{
			cout << floor << "0" << room << endl;
		}
		else
		{
			cout << floor << room << endl;
		}
	}
}