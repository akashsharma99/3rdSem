#include<stdio.h>
#include<malloc.h>
int main()
{
	char st[50],st2[50],conc[100];
	char* ans;
	int c,i,k,flag,count;char ch;
	printf("Enter the string: ");
	scanf("%[^\n]s",st);

	printf("1.concatenate\n2.Substring\n3.string compare\n4.copy string\n5.reverse\n6.palindrome check\n7.count vowels\n");
	printf("Choose an option: ");
	scanf("%d",&c);
	ch=getchar();
	switch(c)
	{
		case 1:
				printf("Enter another string to concatenate: ");
				scanf("%[^\n]s",st2);

				i=0;
				while(st[i]!='\0')
				{
					conc[i]=st[i];i++;
				}
				k=0;
				while(st2[k]!='\0')
				{
					conc[i]=st2[k];k++;i++;
				}
				conc[i]='\0';
				printf("Concatenated string is: %s\n",conc);
				break;
		case 2:	ans=(char*)calloc(50,sizeof(char));
				int index;
				printf("Enter index to substring from: ");
				scanf("%d",&index);
				i=0,k=0;
				while(st[i]!='\0')
				{
					if(i>=index)
						ans[k++]=st[i];
					i++;
				}
				ans[k]='\0';
				printf("The substring is %s\n",ans);
				break;
		case 3:	ans=(char*)calloc(50,sizeof(char));
				printf("Enter another string to compare: ");
				scanf("%[^\n]s",ans);
				i=0;flag=0;
				while(st[i]!='\0' && ans[i]!='\0')
				{
					if(st[i]!=ans[i])
					{
						flag=1;break;
					}
					i++;
				}
				if(flag==1 || st[i]!=ans[i])
					printf("not equal strings!\n");
				else
					printf("Equal strings!\n");
				break;
		case 4:	ans=(char*)calloc(50,sizeof(char));
				i=0;
				while(st[i]!='\0')
				{
					ans[i]=st[i];
					i++;
				}
				printf("String copied: %s\n",ans);
				break;
		case 5:	i=0;
				while(st[i+1]!='\0')
				{
					i++;
				}
				k=0;
				while(k<i)
				{
					ch=st[i];
					st[i]=st[k];
					st[k]=ch;
					i--;k++;
				}
				printf("Reverse is: %s\n",st);
				break;
		case 6:	//creating a copy
				ans=(char*)calloc(50,sizeof(char));
				i=0;
				while(st[i]!='\0')
				{
					ans[i]=st[i];
					i++;
				}
				//reversing
				i=0;
				while(st[i+1]!='\0')
				{
					i++;
				}
				k=0;
				while(k<i)
				{
					ch=st[i];
					st[i]=st[k];
					st[k]=ch;
					i--;k++;
				}
				//comparing
				i=0;flag=0;
				while(st[i]!='\0' && ans[i]!='\0')
				{
					if(st[i]!=ans[i])
					{
						flag=1;break;
					}
					i++;
				}
				if(flag==1 || st[i]!=ans[i])
					printf("not palindrome!\n");
				else
					printf("palindrome string!\n");
				break;
		case 7:	count=0;
				i=0;
				while(st[i]!='\0')
				{
					if(st[i]=='a'||st[i]=='e'||st[i]=='i'||st[i]=='o'||st[i]=='u'||st[i]=='A'||st[i]=='E'||st[i]=='I'||st[i]=='O'||st[i]=='U')
					{
						count++;
					}
					i++;
				}
				printf("Number of vowels: %d\n",count);
				break;
		default: printf("Making bad choices nigga!\n");


	}
	return 0;
}
