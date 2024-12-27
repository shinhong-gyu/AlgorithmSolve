#include <stdio.h>

int main(void){
    double a,b;
    scanf("%lf %lf",&a,&b);
    if(b!=0) {
        printf("%.10lf",a/b);
    }
    return 0;
}