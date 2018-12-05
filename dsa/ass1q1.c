#include<stdio.h>
#include<malloc.h>
int search(int **m,int size,int a,int b)
{
  if(size==1)
      return -1;
  for(int i=1;i<size;i++)
  {
    if(m[i][0]==a && m[i][1]==b)
      return i;
  }
  return -1;
}
int main()
{
  printf("Enter number of elements in the first triplet form:\n");
  int t1;
  scanf("%d",&t1);
  int a[t1+1][3];
  printf("Enter number of elements in the second triplet form:\n");
  int t2;
  scanf("%d",&t2);
  int b[t2+1][3];
  printf("Enter Number of rows in the First Matrix: ");
  scanf("%d",&(a[0][0]));
  printf("Enter Number of columns in the First Matrix: ");
  scanf("%d",&(a[0][1]));
  printf("1st Matrix:\n");
  printf("Enter row index, column index, element value\n");
  for(int i=1;i<=t1;i++)
  {
    scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
  }
  printf("Enter Number of rows in the Second Matrix: ");
  scanf("%d",&(b[0][0]));
  printf("Enter Number of columns in the Second Matrix: ");
  scanf("%d",&(b[0][1]));
  printf("2nd Matrix:\n");
  printf("Enter the row index, column index, element value\n");
  for(int i=1;i<=t2;i++)
  {
    scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
  }
  //multiplying
  if(a[0][1]==b[0][0])
  {
    int **c=(int **)calloc(t1+t2+1,sizeof(int *));
    for (int i=0;i<=(t1+t2);i++)
         c[i]=(int *)calloc(3,sizeof(int));
    int num=0;
    int size=1;
    for(int i=1;i<=t1;i++)
    {
      for(int j=1;j<=t2;j++)
      {
        if(a[i][1]==b[j][0])
        {
          num=a[i][2]*b[j][2];
          int p=search(c,size,a[i][0],b[j][1]);
          if(p==-1)
          {
            c[size][0]=a[i][0];
            c[size][1]=b[j][1];
            c[size][2]=num;
            size++;
          }
          else
          {
            c[p][2]+=num;
          }
        }
      }
    }
    printf("Multiplied form is:\n");
    c[0][0]=a[0][0];
    c[0][1]=b[0][1];
    c[0][2]=size-1;
    for(int i=size;i<=t1+t2;i++)
      free(c[i]);
    for(int i=0;i<size;i++)
    {
      printf("%d\t%d\t%d\n",c[i][0],c[i][1],c[i][2]);
    }
  }
  else
    printf("Multiplication not possible\n");
  return 0;
}
