#include <stdio.h>

int main(void){
   int a,b,c;
   scanf("%d\n%d",&a,&b);
   c = b;
   printf("%d\n",a*(b%10));
   b = b-(b%10);
   printf("%d\n",a*(b%100/10));
   b = b-(b%100);
   printf("%d\n",a*(b/100));
   printf("%d",a*c);
}
