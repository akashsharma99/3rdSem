#include<stdio.h>
#include<malloc.h>
int main()
{
      int *a;
      int n,i,high=-1;
      printf("Enter array size:");
      scanf("%d",&n);
      a=(int*)calloc(n,sizeof(int));
      printf("Enter the array elements: \n");
      for(i=0;i<n;i++)
      {
            scanf("%d",&a[i]);
      }
      int odd=0,eve=n-1,t;
      while(odd<eve)
      {
            if(a[odd]%2==0)
            {
                  t=a[odd];
                  a[odd]=a[eve];
                  a[eve]=t;
                  eve--;
            }
            else
            {
                  odd++;
            }
      }
      //display new array
      for(i=0;i<n;i++)
      {
            printf("%d,",a[i]);
      }
      printf("\n");
      return 0;
 }
