#include<stdio.h>
#include<malloc.h>
int main()
{
      int a,b,c;
      printf("Enter num 1: ");
      scanf("%d",&a);
      printf("Enter num 2: ");
      scanf("%d",&b);
      printf("Enter num 3: ");
      scanf("%d",&c);
      a=a+b+c;
      b=a-(b+c);
      c=a-(b+c);
      a=a-(b+c);
      printf("after swap\nnum1=%d, num2=%d, num3=%d\n",a,b,c);
      return 0;
  }
