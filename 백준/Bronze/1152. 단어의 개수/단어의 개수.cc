#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int is_vaild(char a) {
	if (a >= 65 && a <= 122) {
		return 1;
	}
	return 0;
}

int main() {
	string str;
	int count = 0;
	getline(cin, str);

	
	int vaild = 0;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 65 && str[i] <= 122) {
			vaild = 1;
			count = 1;
		}
	}

	if (vaild) {
		for (int i = 1; i < str.length()-1; i++) {
			if (is_vaild(str[i - 1]) && str[i] == ' ' && is_vaild(str[i + 1])) count++;
		}
	}
	cout << count << endl;
}