#include<stdlib.h>
#include<stdio.h>
int main()
{
      int **a,**b;
      int tot;
      printf("Enter number of elements in the sparse matrix: ");
      scanf("%d",&tot);
      a=(int**)calloc(tot+1,sizeof(int*));
      for(int i=0;i<=tot;i++)
            a[i]=(int*)calloc(3,sizeof(int));
      printf("Enter number of rows in the sparse matrix: ");
      scanf("%d",&a[0][0]);
      printf("Enter number of columns in the sparse matrix: ");
      scanf("%d",&a[0][1]);
      a[0][2]=tot;
      b=(int**)calloc(tot+1,sizeof(int*));
      for(int i=0;i<=tot;i++)
            b[i]=(int*)calloc(3,sizeof(int));
      printf("Enter row:col:value of each element-\n");
      for(int i=1;i<=tot;i++)
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
      int m,n,t,k=1;
      n=a[0][0];m=a[0][1];t=a[0][2];
      b[0][1]=n;b[0][0]=m;b[0][2]=t;
      for(int j=0;j<n;j++)
      {
            for(int i=1;i<=t;i++)
            {
                  if(a[i][1]==j)
                  {
                        b[k][1]=a[i][0];
                        b[k][0]=a[i][1];
                        b[k][2]=a[i][2];
                        k++;
                  }
            }
      }
      printf("Transposed matrix is :\n");
      for(int i=0;i<=t;i++)
            printf("%d %d %d\n",b[i][0],b[i][1],b[i][2]);
      return 0;
}
