#include<stdlib.h>
#include<stdio.h>
struct stack
{
	struct queue* q1;
	struct queue* q2;
	int curr_size;
};
struct queue
{
	struct node *front,*rear;
};
struct node
{
	int val;
	struct node* next;
};
void initQueue(struct queue** q)
{
	(*q)->front=NULL;
	(*q)->rear=NULL;
	return;
}
void initStack(struct stack** s)
{
	(*s)->q1=(struct queue*)malloc(sizeof(struct queue));
	(*s)->q2=(struct queue*)malloc(sizeof(struct queue));
	initQueue(&((*s)->q1));
	initQueue(&((*s)->q2));
	(*s)->curr_size=0;
	return;
}
void enqueue(struct queue** q,int val)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node*));
	temp->val=val;
	temp->next=NULL;
	if((*q)->front==NULL && (*q)->rear==NULL)
	{
		(*q)->front=temp;
		(*q)->rear=temp;
		return;
	}
	(*q)->rear->next=temp;
	(*q)->rear=temp;
	return;
}
int dequeue(struct queue** q)
{
	if((*q)->front==NULL)
	{
		return -999;
	}
	int v=(*q)->front->val;
	(*q)->front=(*q)->front->next;
	if((*q)->front==NULL)
		(*q)->rear=NULL;
	return v;
}
void push(struct stack** s,int val)
{
	struct stack* st=*s;
	st->curr_size++;
	enqueue(&(st->q2),val);
	int v=dequeue(&(st->q1));
	while(v!=-999)
	{
		enqueue(&(st->q2),v);
		v=dequeue(&(st->q1));
	}
	struct queue* temp=st->q1;
	st->q1=st->q2;
	st->q2=temp;
	return;
}
int pop(struct stack** s)
{
	int v=dequeue(&((*s)->q1));
	if(v==-999)
		printf("Stack underflow!\n");
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
