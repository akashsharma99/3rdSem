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
      for(i=0;i<n;i+=2)
      {
            if(i>=n)
            break;
            if(a[i]<a[i+1]){
                  t=a[i];
                  a[i]=a[i+1];
                  a[i+1]=t;
                  }
      }
      //printing
      printf("New array: \n");
      for(i=0;i<n;i++)
      {
      printf("%d, ",a[i]);
      }
      printf("\n");
      return 0;
 }
            
