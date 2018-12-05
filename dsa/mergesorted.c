#include<malloc.h>
#include<stdio.h>
int main()
{
	int* arr1;
	int* arr2;
	int j,i,n,m;
	printf("Enter size of 1st array: ");
	scanf("%d",&n);
	arr1=(int*)calloc(n,sizeof(int));
	printf("Enter the array elements: \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr1[i]);
	}
	printf("Enter size of 2nd array: ");
	scanf("%d",&m);
	arr2=(int*)calloc(m,sizeof(int));
	printf("Enter the array elements: \n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&arr2[i]);
	}
	//sorting arr1[]
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(arr1[j]>arr1[j+1])
			{
				int t=arr1[j];
				arr1[j]=arr1[j+1];
				arr1[j+1]=t;
			}
		}
	}
	//sorting arr2[]
	for(i=0;i<m;i++)
	{
		for(j=0;j<m-1-i;j++)
		{
			if(arr2[j]>arr2[j+1])
			{
				int t=arr2[j];
				arr2[j]=arr2[j+1];
				arr2[j+1]=t;
			}
		}
	}
	int* merged=(int*)calloc(m+n,sizeof(int));
	int x=0,y=0;
	for(i=0;i<m+n;i++)
	{
		if(x>=n){
			merged[i]=arr2[y];
			y++;
		}
		else if(y>=m){
			merged[i]=arr1[x];
			x++;
		}
		else if(arr1[x]<=arr2[y])
		{
		merged[i]=arr1[x];
		x++;
		}
		else if(arr1[x]>=arr2[y])
		{
		merged[i]=arr2[y];
		y++;
		}
	}
	for(i=0;i<n+m;i++)
	printf("%d,",merged[i]);
	return 0;
	}
	
