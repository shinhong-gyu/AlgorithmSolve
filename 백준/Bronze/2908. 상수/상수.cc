#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int reverse_n(int n) {
	int x, y, z, r_n;

	x = n / 100;
	y = (n % 100) / 10;
	z = (n % 100) % 10;

	r_n = z * 100 + y * 10 + x;

	return r_n;
}

int main() {
	int A, B;
	int r_A, r_B;
	cin >> A >> B;

	r_A = reverse_n(A);
	r_B = reverse_n(B);

	if (r_A > r_B) cout << r_A;
	else if (r_B >= r_A) cout << r_B;
}