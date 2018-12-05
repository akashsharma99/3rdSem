#include<stdlib.h>
#include<stdio.h>
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
	printf("%d\n",v);
	(*q)->front=(*q)->front->next;
	if((*q)->front==NULL)
		(*q)->rear=NULL;
	return v;
}
void display(struct queue** q)
{
	if((*q)->front==NULL)
	{
		printf("Empty queue!\n");
		return;
	}
	struct node *p=(*q)->front;
	while(p!=NULL)
	{
		printf("%d\n",p->val);
		p=p->next;
	}
	return;
}
int main()
{
	int v=1,ch;
	struct queue *q1=(struct queue*)malloc(sizeof(struct queue));
	initQueue(&q1);
	while(v==1)
	{
		printf("1.insert__2.delete__3.display__4.exit\n");
		printf("Choose: ");
		scanf("%d",&ch);
		if(ch==1){
			printf("Enter a value: ");
			int val;
			scanf("%d",&val);
			enqueue(&q1,val);
		}
		else if(ch==2){
			int val=dequeue(&q1);
			if(val==-999)
				printf("Underflow!\n");
			else
				printf("Deleted: %d",val);
		}
		else if(ch==3){
			printf("The queue is:\n");display(&q1);
		}
		else
			break;
	}
}
