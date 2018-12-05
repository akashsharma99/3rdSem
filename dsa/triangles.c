#include<stdio.h>
#include<malloc.h>
int main()
{
      int **a;
      int n,i,t,j,s=0,op;
      printf("Enter array size:");
      scanf("%d",&n);
      a=(int**)calloc(n,sizeof(int*));
      for(i=0;i<n;i++)
      {a[i]=(int*)calloc(n,sizeof(int));}
      printf("Enter the matrix elements: \n");
      for(i=0;i<n;i++)
      {
            for(j=0;j<n;j++)
            {
                  scanf("%d",&a[i][j]);
            }
      }
      printf("The matrix is: \n");
      for(i=0;i<n;i++)
      {
            for(j=0;j<n;j++)
            {
                  printf("%d\t",a[i][j]);
            }
            printf("\n");
      }
      printf("1.add upper elements for major diagonal\n");
      printf("2.add lower elements for major diagonal\n");
      printf("3.add upper elements for minor diagonal\n");
      printf("4.add lower elements for minor diagonal\n");
      printf("Choose your option: ");
      scanf("%d",&op);
      switch(op){
            case 1: for(i=0;i<n-1;i++)
                    {
                        for(j=1+i;j<n;j++)
                        {
                        s=s+a[i][j];
                        }
                    }
                    printf("sum = %d\n",s);
                    break;
            case 2: for(i=1;i<n;i++)
                    {
                    	for(j=0;j<i;j++)
                    	{
                    	s=s+a[i][j];
                    	}
                    }
                    printf("sum= %d\n",s);
                    break;
            case 3: for(i=0;i<n-1;i++)
                    {
                    	for(j=0;j<n-i-1;j++)
                    	{
                    	s=s+a[i][j];
                    	}
                    }
                    printf("sum= %d\n",s);
                    break;
            case 4:
                    for(i=0;i<n;i++)
                    {
                    	for(j=0;j<n;j++)
                    	{
                              if(i+j>=n)
                                    s=s+a[i][j];
                    	}
                    }
                    printf("sum= %d\n",s);
                    break;
            default: printf("wrong input\n");
       }
       return 0;
 }
