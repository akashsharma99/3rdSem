#include<stdio.h>
#include<malloc.h>
int main()
{
      int *a,*b;
      int n,i,j,high;
      printf("Enter array size:");
      scanf("%d",&n);
      a=(int*)calloc(n,sizeof(int));
      b=(int*)calloc(n,sizeof(int));
      printf("Enter the array elements: \n");
      for(i=0;i<n;i++)
      {
            scanf("%d",&a[i]);
      }
      int flag=0,h=-1;
      for(i=0;i<n;i++)
      {
            for(j=0;j<n;j++)
            {
                  if(a[j]>a[i] && flag==0){
                        flag=1;
                        h=a[j];
                  }
                  else if(a[j]>a[i])
                  {
                        if(a[j]<h)
                        h=a[j];
                  }
            }
            b[i]=h;
            h=-1;
            flag=0;
      }
      printf("The new array is :\n");
      for(i=0;i<n;i++)
      {
            printf("%d\n",b[i]);
      }
      return 0;
}
