#include<stdio.h>
#include<malloc.h>
int main()
{
      int *a;
      int n,i,t,j;
      printf("Enter array size:");
      scanf("%d",&n);
      a=(int*)calloc(n,sizeof(int));
      printf("Enter the array elements: \n");
      for(i=0;i<n;i++)
      {
            scanf("%d",&a[i]);
      }
      int prev=a[0];
      for(i=1;i<n-1;i++)
      {
            t=prev*a[i+1];
            prev=a[i];
            a[i]=t;
      }
      //printing
      for(i=0;i<n;i++)
      {
            printf("%d,",a[i]);
      }
      printf("\n");
      return 0;
 }
