#include <string>
#include <vector>

using namespace std;

// right down left up
vector<vector<int>> solution(int n) {
   
	vector<vector<int>> answer(n, vector<int>(n, 0));
	int direction = 0;
	int index1 = 0;
	int index2 = 0;
	int input = 1;
	int times = n * 2 - 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer[i][j] = 0;
		}
	}

	while (times >= 0) {
		switch (direction) {
		case 0:
			for (int j = 0; j < n; j++) {
				if (input!=n*n&&(index2 + 1 >= n || answer[index1][index2 + 1] != 0)) break;
				else {
					answer[index1][index2++] = input++;
				}
			}
			direction = 1;
			times--;
			break;
		case 1:
			for (int j = 0; j < n; j++) {
				if (input != n * n && (index1 + 1 >= n || answer[index1 + 1][index2] != 0)) break;
				else {
				answer[index1++][index2] = input++;
				}
			}
			direction = 2;
			times--;
			break;
		case 2:
			for (int j = 0; j < n; j++) {
				if (input != n * n && (index2 - 1 < 0 || answer[index1][index2 - 1] != 0)) break;
				else {
				answer[index1][index2--] = input++;
				}
			}
			direction = 3;
			times--;
			break;
		case 3:
			for (int j = 0; j < n; j++) {
				if (n==2||input != n * n && (index1 - 1 < 0 ||answer[index1 - 1][index2] != 0)) {
					break;
				}
				else {
					answer[index1--][index2] = input++;
				}
			}
			direction = 0;
			times--;
			break;
		}
	}
        
    return answer;
}