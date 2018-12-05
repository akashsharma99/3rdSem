#include<stdio.h>
#include<stdlib.h>
void mergeSort(int*,int,int);
void merge(int* a, int l,int m,int r)
{
      int i=l;
      int j=m+1;
      int temp[r-l+1];
      int k=0;
      while(i<=m && j<=r)
      {
            if(a[i]<a[j])
            {
                  temp[k++]=a[i++];
            }
            else
            {
                  temp[k++]=a[j++];
            }
      }
      while(i<=m)
      {
            temp[k++]=a[i++];
      }
      while(j<=r)
      {
            temp[k++]=a[j++];
      }
      while(r>=l)
      {
            a[r--]=temp[--k];
      }
}
void mergeSort(int* a,int l,int r)
{
      if(l<r)
      {
            int m=(l+r)/2;
            mergeSort(a,l,m);
            mergeSort(a,m+1,r);
            merge(a,l,m,r);
      }
}

void printArray(int* a,int n)
{
      int i=0;
      for(;i<n-1;i++)
      printf("%d , ",a[i]);
      printf("%d\n",a[i]);
}
int main()
{
      int n;
      printf("Enter size of array: ");
      scanf("%d",&n);
      int* a=(int*)calloc(n,sizeof(int));
      printf("Enter the array elements: \n");
      int i=0;
      while(i<n)
      {
            scanf("%d",&a[i]);
            i++;
      }
      mergeSort(a,0,n-1);
      printArray(a,n);
      return 0;
}
