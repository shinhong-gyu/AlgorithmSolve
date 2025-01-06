#include <string>
#include <vector>

using namespace std;

float CulInclination(vector<int> dot1,vector<int> dot2){
   return float(dot1[1]- dot2[1]) / (dot1[0] - dot2[0]);
}

int solution(vector<vector<int>> dots) {
    // 1 - 2 / 3 - 4
    if(CulInclination(dots[0],dots[1]) == CulInclination(dots[2],dots[3])){
        return 1;
    }
    // 1 - 3 / 2 - 4
    if(CulInclination(dots[0],dots[2]) == CulInclination(dots[1],dots[3])){
        return 1;
    }
    // 1 - 4 / 2 - 3
    if(CulInclination(dots[0],dots[3]) == CulInclination(dots[1],dots[2])){
        return 1;
    }
    return 0;
}