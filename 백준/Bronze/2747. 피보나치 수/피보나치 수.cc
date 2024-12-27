#include <iostream>
using namespace std;

int fiboarr[50] = {0,1,};
int fibo(int N)
{
    if(N == 0 || N == 1)
        return fiboarr[N];
    else if(fiboarr[N] == 0)
        fiboarr[N] = fibo(N-1) + fibo(N-2);
    return fiboarr[N];
}
int main() {
   int n;
   cin >> n;
   cout << fibo(n) << endl;;
}