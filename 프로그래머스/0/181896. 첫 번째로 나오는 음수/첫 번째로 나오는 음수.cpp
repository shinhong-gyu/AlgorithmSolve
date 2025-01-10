#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> num_list) {
    
    for(auto n : num_list){
        if(n<0){
            return find(num_list.begin(), num_list.end(),n) != num_list.end()? find(num_list.begin(), num_list.end(),n)-num_list.begin():-1;
        }
    }
    return -1;
}