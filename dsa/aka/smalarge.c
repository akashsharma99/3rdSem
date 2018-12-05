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
      int low=a[0];
      for(i=0;i<n;i++)
      {
            if(a[i]>high)
                  high=a[i];
            if(a[i]<low)
                  low=a[i];
      }
      printf("Lowest number is: %d\n",low);
      printf("Highest number is: %d\n",high);
      return 0;
}
