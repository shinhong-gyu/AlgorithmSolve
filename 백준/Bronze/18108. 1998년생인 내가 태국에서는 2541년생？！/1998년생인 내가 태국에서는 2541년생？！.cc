#include <stdio.h>

int main(void){
    int y;
    scanf("%d",&y);
    if(y<1000||y>3000) return 0;
    printf("%d",y-543);
    return 0;
}