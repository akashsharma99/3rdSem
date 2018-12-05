#include<stdio.h>
#include<malloc.h>
int main()
{
      int *a;
      int n,i;
      printf("Enter array size:");
      scanf("%d",&n);
      a=(int*)calloc(n,sizeof(int));
      printf("Enter the array elements: \n");
      for(i=0;i<n;i++)
      {
            scanf("%d",&a[i]);
      }
      int sec_high=a[1],high=a[0],low=a[0],sec_low=a[1];
      for(i=1;i<n;i++)
      {
            if(a[i]>high)
            {
            sec_high=high;
            high=a[i];
            }
            else if(a[i]<high && a[i]>=sec_high)
            {
                  sec_high=a[i];
            }
            if(a[i]<low)
            {
            sec_low=low;
            low=a[i];
            }
            else if(a[i]>low && a[i]<=sec_low)
            {
                  sec_low=a[i];
            }
      }
      printf("Second highest= %d\n",sec_high);
      printf("Second lowest= %d\n",sec_low);
      return 0;
 }
