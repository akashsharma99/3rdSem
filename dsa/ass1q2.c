#include<stdio.h>
#include<malloc.h>
int main()
{
      int* a;
      int n,i,j,k,sum;
      printf("Enter size of array: ");
      scanf("%d",&n);
      printf("Enter array elements:\n");
      a=(int*)calloc(n,sizeof(int));
      for(i=0;i<n;i++){
            scanf("%d",&a[i]);
      }
      printf("Enter a value to find triplet: ");
      scanf("%d",&sum);
      for(i=0;i<n-2;i++)
      {
            for(j=i+1;j<n-1;j++)
            {
                  for(k=j+1;k<n;k++)
                  {
                        if(a[i]+a[j]+a[k]==sum)
                        {
                              printf("%d,%d,%d form the triplet",a[i],a[j],a[k]);
                              return 0;
                        }
                  }
            }
      }
      printf("No triplet found!\n");
      return 0;
}
