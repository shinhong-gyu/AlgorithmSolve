#include <iostream>
#include <string.h>

using namespace std;

int main() {
	char str[101] = {0};
	char compare = 'a';
	int index = 0;
	cin >> str;
	while (compare <= 'z') {
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == compare) {
				index = i;
				break;
			}
			index = -1;
		}
		if (compare == 'z') {
			printf("%d",index);
		}
		else {
			printf("%d ",index);
		}
		compare++;
	}
}