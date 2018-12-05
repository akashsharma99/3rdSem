#include<stdio.h>
#include<malloc.h>
char compare(int x,int y)
{
      if(x==y)
      return '=';
      else if(x>y)
      return '>';
      else
      return '<';
}
int main()
{
      int **a,**b,**c;
      int t1,t2,i,j,k;
      char c1,c2;
      printf("How many elements in 1st matrix: ");
      scanf("%d",&t1);

      a=(int**)calloc(t1+1,sizeof(int*));
      for(i=0;i<=t1;i++)
            a[i]=(int*)calloc(3,sizeof(int));

      printf("How many rows and columns in 1st matrix: ");
      scanf("%d%d",&a[0][0],&a[0][1]);
      a[0][2]=t1;

      printf("Enter row:col:value.\n");
      for(i=1;i<=t1;i++)
            scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);

      printf("How many elements in 2nd matrix: ");
      scanf("%d",&t2);
      b=(int**)calloc(t2+1,sizeof(int*));
      for(i=0;i<=t2;i++)
            b[i]=(int*)calloc(3,sizeof(int));
      printf("How many rows and columns in 2nd matrix: ");
      scanf("%d%d",&b[0][0],&b[0][1]);
      b[0][2]=t2;
      printf("Enter row:col:value.\n");
      for(i=1;i<=t2;i++)
            scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
      if(a[0][0]!=b[0][0]||a[0][1]!=b[0][1])
      {
            printf("Addition not possible!");
            return 0;
      }
      c=(int**)calloc(t1+t2+1,sizeof(int*));
      for(i=0;i<=t1+t2;i++)
            c[i]=(int*)calloc(3,sizeof(int));
      i=1;j=1;k=1;
      while(i<=t1 && j<=t2)
      {
            c1=compare(a[i][0],b[j][0]);
            switch(c1)
            {
                  case '=':   c2=compare(a[i][1],b[j][1]);
                              switch(c2)
                              {
                                    case '=':   c[k][0]=a[i][0];
                                                c[k][1]=a[i][1];
                                                c[k][2]=a[i][2]+b[j][2];
                                                i++;j++;k++;
                                                break;
                                    case '<':   c[k][0]=a[i][0];
                                                c[k][1]=a[i][1];
                                                c[k][2]=a[i][2];
                                                i++;k++;
                                                break;
                                    case '>':   c[k][0]=b[j][0];
                                                c[k][1]=b[j][1];
                                                c[k][2]=b[j][2];
                                                j++;k++;
                                                break;
                              }
                              break;
                  case '<':   c[k][0]=a[i][0];
                              c[k][1]=a[i][1];
                              c[k][2]=a[i][2];
                              i++;k++;
                              break;
                  case '>':   c[k][0]=b[j][0];
                              c[k][1]=b[j][1];
                              c[k][2]=b[j][2];
                              j++;k++;
                              break;
            }
      }
      while(i<=t1)
      {
            c[k][0]=a[i][0];
            c[k][1]=a[i][1];
            c[k][2]=a[i][2];
            i++;k++;
      }
      while(j<=t2)
      {
            c[k][0]=b[j][0];
            c[k][1]=b[j][1];
            c[k][2]=b[j][2];
            k++;j++;
      }
      c[0][2]=k-1;
      c[0][1]=a[0][1];
      c[0][0]=a[0][0];
      printf("Final matrix is:\n");
      for(int i=0;i<k;i++)
            printf("%d %d %d\n",c[i][0],c[i][1],c[i][2]);
      return 0;
}
