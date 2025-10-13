#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_map<string, double> rating;

	rating["A+"] = 4.5;
	rating["A0"] = 4.0;
	rating["B+"] = 3.5;
	rating["B0"] = 3.0;
	rating["C+"] = 2.5;
	rating["C0"] = 2.0;
	rating["D+"] = 1.5;
	rating["D0"] = 1.0;
	rating["F"] = 0.0;

	double total = 0.0;
	double sum = 0.0;

	for (int i = 1; i <= 20; i++)
	{
		string name;
		double score;
		string rate;

		cin >> name >> score >> rate;

		if (rate != "P")
		{
			total += (score * rating[rate]);

			sum += score;
		}
	}

	cout<<std::fixed << std::setprecision(5) << total/sum;

}