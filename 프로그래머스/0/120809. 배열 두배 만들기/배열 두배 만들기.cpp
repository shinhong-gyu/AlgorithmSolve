#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(auto n : numbers){
        answer.push_back(n*2);
    }
    return answer;
}