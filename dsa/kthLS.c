#include<stdio.h>
#include<malloc.h>
int main()
{
      int *a;
      int n,i,t,j,k;
      printf("Enter array size:");
      scanf("%d",&n);
      a=(int*)calloc(n,sizeof(int));
      printf("Enter the array elements: \n");
      for(i=0;i<n;i++)
      {
            scanf("%d",&a[i]);
      }
      //sorting
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
      printf("Enter value of k: ");
      scanf("%d",&k);
      if(k>0 && k<=n)
      {
            printf("kth largest= %d\nkth smallest= %d\n",a[n-k],a[k-1]);
      }
      else
      printf("k out of range!\n");
      return 0;
 }
