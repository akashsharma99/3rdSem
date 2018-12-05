#include<stdio.h>
#include<malloc.h>
int main()
{
      int *a;
      int n,i,high=-1;
      printf("Enter array size:");
      scanf("%d",&n);
      a=(int*)calloc(n,sizeof(int));
      int*b=(int*)calloc(n,sizeof(int));
      printf("Enter the array elements: \n");
      for(i=0;i<n;i++)
      {
            scanf("%d",&a[i]);
      }
      int odd=0,eve=n-1;
      for(i=0;i<n;i++)
      {
            if(a[i]%2==0)
                  b[eve--]=a[i];
            else
                  b[odd++]=a[i];
      }
      //display new array
      for(i=0;i<n;i++)
      {
            printf("%d,",b[i]);
      }
      printf("\n");
      return 0;
 }
