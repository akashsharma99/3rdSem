#include<malloc.h>
#include<stdio.h>
int main()
{
	int* a;
	int i,s;
	printf("Enter size of array: ");
	scanf("%d",&s);
	a=(int*)calloc(s,sizeof(int));
	printf("Enter the array elements:\n");
	for(i=0;i<s;i++)
		scanf("%d",&a[i]);
	//reversing the array
	for(i=0;i<s/2;i++)
	{
		int t=a[i];
		a[i]=a[s-i-1];
		a[s-i-1]=t;
	}
	//printing reversed array
	printf("The reversed array is:\n");
	for(i=0;i<s;i++)
	{
		printf("%d\n",a[i]);
	}
return 0;
}
