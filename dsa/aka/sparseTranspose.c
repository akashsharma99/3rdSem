#include<stdio.h>
#include<malloc.h>
int** transpose(int** mat)
{
	int i,j,t,n,k=1;
	int** mat2=(int**)calloc(mat[0][0]+1,sizeof(int*));
	for(i=0;i<mat[0][0]+1;i++)
	mat2[i]=(int*)calloc(3,sizeof(int));
	n=mat[0][0];
	mat2[0][1]=n;
	t=mat[0][2];
	mat2[0][2]=t;
	mat2[0][0]=mat[0][1];
	for(j=0;j<n;j++)
	{
	for(i=1;i<=t;i++)
	{
		if(mat[i][1]==j)
		{
			mat2[k][1]=mat[i][0];
			mat2[k][0]=mat[i][1];
			mat2[k][2]=mat[i][2];
			k++;
		}
	}
	}
	mat=mat2;
}
int main()
{
	int **a,**triplet;
	int x,y,i,j,c=0;
	printf("Enter number of rows:");
	scanf("%d",&x);
	printf("Enter number of columns:");
	scanf("%d",&y);
	a=(int**)calloc(x,sizeof(int*));
	for(i=0;i<x;i++)
	a[i]=(int*)calloc(y,sizeof(int));
	printf("Enter matrix elements:\n");
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
		scanf("%d",&a[i][j]);
		if(a[i][j]!=0)c++;
		}
	}
	triplet=(int**)calloc(c+1,sizeof(int*));
	for(i=0;i<c+1;i++)
		triplet[i]=(int*)calloc(3,sizeof(int));
	triplet[0][0]=x;
	triplet[0][1]=y;
	triplet[0][2]=c;
	int m=1;
	//display matrix
	printf("The given sparse matrix is: \n");
	for(i=0;i<x;i++)
	{
		for(j=0;j<y;j++)
		{
			printf("%d ",a[i][j]);
			if(a[i][j]!=0){
				triplet[m][0]=i;
				triplet[m][1]=j;
				triplet[m][2]=a[i][j];
				m++;
			}
		}
		printf("\n");
	}
	triplet=transpose(triplet);
	a=(int**)calloc(triplet[0][0],sizeof(int*));
	for(i=0;i<triplet[0][0];i++)
	a[i]=(int*)calloc(triplet[0][1],sizeof(int));
	for(i=1;i<=triplet[0][2];i++){
		a[triplet[i][0]][triplet[i][1]]=triplet[i][2];
	}
	printf("The transposed matrix is: \n");
	for(i=0;i<triplet[0][0];i++)
	{
		for(j=0;j<triplet[0][1];j++)
		{
			printf("%d ",a[i][j]);
			
		}
		printf("\n");
	}
	return 0;
}
