#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    bool isNoZero = false;
    int n = common.size();
    for(auto n : common){
        if(n == 0){
            isNoZero = true;
        }
    }
    if(!isNoZero){
        return common[1]/common[0] == common[2]/common[1]? common[common.size()-1] * ((float)common[1]/common[0]) : common[common.size()-1]+(common[1]-common[0]);    
    }
    else{
        return common[common.size()-1]+(common[1]-common[0]);
    }
}