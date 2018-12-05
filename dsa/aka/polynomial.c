#include<stdio.h>
#include<malloc.h>
int main()
{
	int i,j,n,m;
	int* an,*am,*ans;
	printf("Enter highest order of first polynomial: ");
	scanf("%d",&n);
	printf("Enter coefficient for each order of x for 1st polynomial:\n");
	an=(int*)calloc(n+1,sizeof(int));
	for(i=0;i<=n;i++){
		printf("%d: ",i);
		scanf("%d",&an[i]);
	}
	printf("Enter highest order of second polynomial: ");
	scanf("%d",&m);
	printf("Enter coefficient for each order of x for 2nd polynomial:\n");
	am=(int*)calloc(m+1,sizeof(int));
	for(i=0;i<=m;i++){
		printf("%d: ",i);
		scanf("%d",&am[i]);
	}
	int x=(n>m)?n:m;
	int ch;
	printf("1.Polynomial Addition\n2.Polynomial Multiplication\nchoose an option\n");
	scanf("%d",&ch);
	switch(ch){
	case 1:	
			ans=(int*)calloc(x+1,sizeof(int));
			for(i=0;i<=x;i++)
			{
				if(i>n)
					ans[i]=am[i];
				else if(i>m)
					ans[i]=an[i];
				else
					ans[i]=an[i]+am[i];
			}
			//printing
			printf("Summation of polynomials is: ");
			for(i=0;i<x;i++)
			{
				if(ans[i]!=0)
				printf("%dx^%d + ",ans[i],i);
			}
			if(ans[i]!=0)
				printf("%dx^%d\n",ans[i],i);
			break;
	case 2:	ans=(int*)calloc(n+m+1,sizeof(int));	
			for(i=0;i<=n;i++)
			{
				for(j=0;j<=m;j++)
				{
					ans[i+j]=an[i]*am[j]+ans[i+j];
				}
			}
			printf("Product of polynomials is: ");
			for(i=0;i<m+n;i++)
			{
				if(ans[i]!=0)
				printf("%dx^%d + ",ans[i],i);
			}
			if(ans[i]!=0)
				printf("%dx^%d\n",ans[i],i);
			break;
	default:printf("Wrong input!\n");
	}
	return 0;		
}
	
