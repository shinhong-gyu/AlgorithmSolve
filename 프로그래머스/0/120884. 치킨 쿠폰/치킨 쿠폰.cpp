#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int chicken) {
    int total_Chicken = 0;
    int coupons = chicken;
    int newChicken = 0;

    while(coupons >= 10)
    {
        newChicken = coupons/10;
        coupons = coupons%10 + newChicken;
        total_Chicken += newChicken;
    }
    return total_Chicken;
}