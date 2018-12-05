#include<stdio.h>
#include<malloc.h>
int main()
{
      int *a;
      int n,i,j,high;
      printf("Enter array size:");
      scanf("%d",&n);
      a=(int*)calloc(n,sizeof(int));
      printf("Enter the array elements: \n");
      for(i=0;i<n;i++)
      {
            scanf("%d",&a[i]);
      }
      for(i=0;i<n-1;i++)
      {
            high=a[i];
            for(j=i+1;j<n;j++)
            {
                  if(a[j]>high){
                        high=a[j];break;}
            }
            if(high==a[i])high=-1;
            printf("%d : %d\n",a[i],high);
      }
      printf("%d : %d\n",a[n-1],-1);
      return 0;
 }
