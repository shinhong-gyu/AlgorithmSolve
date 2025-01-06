#include <string>
#include <vector>
#include <cmath>
#include <math.h>

using namespace std;

int solution(int n) {
    return trunc(sqrt(n))*trunc(sqrt(n)) != n? 2:1;
}