#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int T,R;
	char str[161] = {0};
	cin >> T;
	while (T--) {
		cin >> R >> str;
		for (int i = 0; i < strlen(str); i++) {
			for (int j = 0; j < R; j++) {
				cout << str[i];
			}
		}
		cout << endl;
	}
}