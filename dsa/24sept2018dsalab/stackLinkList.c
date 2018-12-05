#include<stdio.h>
#include<stdlib.h>
struct stack
{
	struct node* top;
};
struct node
{
	int val;
	struct node* next;
};
void initStack(struct stack** s)
{
	(*s)->top=NULL;
	return;
}
void push(struct stack** s,int val)
{
	struct stack* st=*s;
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->val=val;
	if(st->top==NULL)
	{
		st->top=temp;
		return;
	}
	temp->next=st->top;
	st->top=temp;
	return;
}
int pop(struct stack** s)
{
	struct stack* st=*s;
	if(st->top==NULL)
	{
		printf("Stack underflow!\n");
		return -999;
	}
	int v=st->top->val;
	struct node* garb=st->top;
	st->top=st->top->next;
	free(garb);
	return v;
}
int main()
{
	struct stack* st=(struct stack*)malloc(sizeof(struct stack));
	initStack(&st);
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
