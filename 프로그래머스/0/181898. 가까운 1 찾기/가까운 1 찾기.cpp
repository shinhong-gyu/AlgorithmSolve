#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr, int idx) {

    return find(arr.begin()+idx,arr.end(),1) != arr.end()? find(arr.begin()+idx,arr.end(),1) - arr.begin() : -1;
}