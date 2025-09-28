#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point
{
	double x, y;

	bool operator==(const Point& p) const
	{
		return this->x == p.x && this->y == p.y;
	}
};

struct Segment
{
	Point A, B;

	bool equation(double x, double y) const
	{
		int minY, maxY;
		int minX, maxX;

		minY = min(A.y, B.y);
		maxY = max(A.y, B.y);

		minX = min(A.x, B.x);
		maxX = max(A.x, B.x);

		if (A.y - B.y == 0)
		{
			return (y == A.y) && (x >= minX && x <= maxX);

		}
		else if (A.x - B.x == 0)
		{
			return (x == A.x) && (y >= minY && y <= maxY);
		}
		else
		{
			double delta = (A.y - B.y) / (A.x - B.x);

			if (x >= minX && maxX >= x && y >= minY && y <= maxY)
			{
				const double EPSILON = 1e-9;
				return abs(delta * (x - A.x) - (y - A.y)) < EPSILON;
			}

			return false;
		}
	}

	Point CulCrossPoint(Segment s) const
	{
		Point result = { 0,0 };

		double x_1 = s.A.x;
		double x_2 = s.B.x;
		double y_1 = s.A.y;
		double y_2 = s.B.y;

		if (A.y - B.y == 0)
		{
			if (x_1 - x_2 != 0)
			{
				if (y_1 - y_2 != 0)
				{
					double delta = (y_1 - y_2) / (x_1 - x_2);

					double xSection = ((A.y - y_1) / delta) + x_1;

					result = { xSection ,A.y };
				}
				else
				{
					if (A == s.A || A == s.B)
					{
						return A;
					}
					else
					{
						return B;
					}
				}
			}
			else
			{
				result = { x_1,A.y };
			}
		}
		else if (A.x - B.x == 0)
		{
			if (y_1 - y_2 != 0)
			{
				if (x_1 - x_2 != 0)
				{
					double delta = (y_1 - y_2) / (x_1 - x_2);

					double ySection = delta * (A.x - x_1) + y_1;

					result = { A.x,ySection };
				}
				else
				{
					if (A == s.A || A == s.B)
					{
						return A;
					}
					else
					{
						return B;
					}
				}
			}
			else
			{
				result = { A.x,y_1 };
			}
		}
		else
		{
			double delta1 = (A.y - B.y) / (A.x - B.x);

			if (x_1 - x_2 != 0 && y_1 - y_2 != 0)
			{
				double delta2 = (y_1 - y_2) / (x_1 - x_2);

				if (delta2 != delta1)
				{
					double x = (y_1 - A.y + delta1 * A.x - delta2 * x_1) / (delta1 - delta2);

					double y = delta1 * (x - A.x) + A.y;

					result = { x,y };
				}
				else
				{
					if (A == s.A || A == s.B)
					{
						return A;
					}
					else
					{
						return B;
					}
				}
			}
			else
			{
				if (x_1 == x_2)
				{
					double y = delta1 * (x_1 - A.x) + A.y;

					result = { x_1,y };
				}
				else if (y_1 == y_2)
				{
					double x = (y_1 - A.y) / delta1 + A.x;

					result = { x, y_1 };
				}
			}
		}
		return result;
	}
};

double CCW(Segment s, Point p)
{
	double result = (s.A.x * s.B.y + s.B.x * p.y + p.x * s.A.y) - (s.B.x * s.A.y + p.x * s.B.y + s.A.x * p.y);

	const double EPSILON = 1e-9;

	if (result > EPSILON)
	{
		return 1;
	}
	else if (result < -EPSILON)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

bool IsOverlap(Segment s1, Segment s2)
{
	bool perfectOverlap = s1.equation(s2.A.x, s2.A.y) && s1.equation(s2.B.x, s2.B.y) || s2.equation(s1.A.x, s1.A.y) && s2.equation(s1.B.x, s1.B.y);

	// 한 개는 선분 위 하나는 밖이면서 
	bool partlyOverlap = s1.equation(s2.A.x, s2.A.y) && s2.equation(s1.A.x, s1.A.y) && !(s2.A == s1.A)
		|| s1.equation(s2.B.x, s2.B.y) && s2.equation(s1.A.x, s1.A.y) && !(s2.B == s1.A)
		|| s1.equation(s2.A.x, s2.A.y) && s2.equation(s1.B.x, s1.B.y) && !(s2.A == s1.B)
		|| s1.equation(s2.B.x, s2.B.y) && s2.equation(s1.B.x, s1.B.y) && !(s2.B == s1.B);

	return perfectOverlap || partlyOverlap;
}

Point CrossPoint(Segment s1, Segment s2)
{
	return s1.CulCrossPoint(s2);
}

void IsCross(Segment s1, Segment s2)
{
	double ABC = CCW(s1, s2.A);
	double ABD = CCW(s1, s2.B);
	double CDA = CCW(s2, s1.A);
	double CDB = CCW(s2, s1.B);

	if (ABC == 0 && ABD == 0 && CDA == 0 && CDB == 0)
	{
		if (IsOverlap(s1, s2))
		{
			cout << 1;
			return;
		}
		else
		{
			if (s1.A == s2.A || s1.A == s2.B)
			{
				cout << 1 << "\n";
				cout << s1.A.x << " " << s1.A.y;
				return;
			}
			else if (s1.B == s2.A || s1.B == s2.B)
			{
				cout << 1 << "\n";
				cout << s1.B.x << " " << s1.B.y;
				return;
			}

			cout << 0;
			return;
		}
	}

	if (ABC * ABD <= 0 && CDA * CDB <= 0)
	{
		cout << 1 << "\n";

		Point cp = CrossPoint(s1, s2);

		cout << fixed;
		cout << setprecision(9);
		cout << cp.x << " " << cp.y << "\n";

		return;
	}

	cout << 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Segment s1, s2;

	cin >> s1.A.x >> s1.A.y >> s1.B.x >> s1.B.y;
	cin >> s2.A.x >> s2.A.y >> s2.B.x >> s2.B.y;

	IsCross(s1, s2);
}