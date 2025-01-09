#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int odd_sum = 0;
    int even_sum = 0;
    for(int i =0; i< num_list.size(); i++){
        if((i+1)%2 ==0){
            odd_sum += num_list[i];
        }
        else {
            even_sum += num_list[i];
        }
    }
    return even_sum > odd_sum ? even_sum : odd_sum;
}