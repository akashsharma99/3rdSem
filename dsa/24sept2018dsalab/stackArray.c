#include<stdio.h>
#include<stdlib.h>
struct stack
{
	int size;
	int *a;
	int top;
};
void initStack(struct stack** s,int size)
{
	(*s)->size=size;
	(*s)->a=malloc(sizeof(int));
	(*s)->top=-1;
}
void push(struct stack** s,int val)
{
	struct stack* st=*s;
	if(st->top==st->size-1)
	{
		printf("Stack Overflow!\n");
		return;
	}
	st->a[++(st->top)]=val;
	return;	
}
int pop(struct stack** s)
{
	struct stack* st=*s;
	if(st->top==-1)
	{
		printf("Stack Underflow!\n");
		return -999;
	}
	int v=st->a[(st->top)--];
	return v;
}
int main()
{
	int s;
	printf("Enter size of stack: ");
	scanf("%d",&s);
	struct stack* st=(struct stack*)malloc(sizeof(struct stack));
	initStack(&st,s);
	while(1)
	{
		printf("1.Push\n2.Pop\n3.exit\nchoose: ");
		int op;
		scanf("%d",&op);
		if(op==3)
		break;
		else if(op==1)
		{
			int val;
			printf("Enter value: ");
			scanf("%d",&val);
			push(&st,val);
		}
		else if(op==2)
		{
			int val=pop(&st);
			if(val!=-999)
				printf("Popped out: %d\n",val);
		}
		else
		printf("Wrong choice! try again.\n");
	}
	return 0;
}

