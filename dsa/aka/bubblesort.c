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
      //sorting bubblesort
      for(i=0;i<n-1;i++)
      {
            for(j=0;j<n-i-1;j++)
            {
                  if(a[j]>a[j+1]){
                        t=a[j];
                        a[j]=a[j+1];
                        a[j+1]=t;
                  }
             }
      }
      //display array after sorting
      printf("The sorted array is :\n");
      for(i=0;i<n;i++)
      {
            printf("%d\n",a[i]);
      }
      return 0;
 }
