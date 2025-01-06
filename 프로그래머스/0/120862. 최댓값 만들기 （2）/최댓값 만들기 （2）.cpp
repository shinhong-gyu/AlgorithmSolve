#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> numbers) {
    int answer = -100000000;
    for(int i = 0; i < numbers.size(); i++)
    {
        for(int j = i+1; j< numbers.size(); j++)
        {
            if(answer < numbers[i]*numbers[j])
            {
                answer = numbers[i]*numbers[j];
            }
        }
    }
    return answer;
}