#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Coordinate
{
	int x, y;
};

ostream& operator<<(ostream& os, const Coordinate& p)
{
	return os << p.x << " " << p.y << "\n";
}

bool compare(Coordinate p1, Coordinate p2)
{
	if (p1.x == p2.x)
		return p1.y < p2.y;
	return p1.x < p2.x;
}

int main()
{
	int N;
	cin >> N;

	vector<Coordinate> points(N);

	for (int i = 0; i < N; i++)
	{
		cin >> points[i].x >> points[i].y;
	}

	sort(points.begin(), points.end(), compare);


	for (int i = 0; i < N; i++)
	{
		cout << points[i];
	}
}

