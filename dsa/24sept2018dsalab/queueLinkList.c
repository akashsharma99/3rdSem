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
	(*q)->front=(*q)->front->next;
	if((*q)->front==NULL)
		(*q)->rear=NULL;
	return v;
}
int main()
{
int v;
	struct queue *q1=(struct queue*)malloc(sizeof(struct queue));
	initQueue(&q1);
	enqueue(&q1,1);
	enqueue(&q1,2);
	enqueue(&q1,3);
	enqueue(&q1,4);
	v=dequeue(&q1);
	if(v!=-999)printf("%d ",v);
	else printf("\nUnderflow!\n");
	v=dequeue(&q1);
	if(v!=-999)printf("%d ",v);
	else printf("\nUnderflow!\n");
	v=dequeue(&q1);
	if(v!=-999)printf("%d ",v);
	else printf("\nUnderflow!\n");
	v=dequeue(&q1);
	if(v!=-999)printf("%d ",v);
	else printf("\nUnderflow!\n");
	v=dequeue(&q1);
	if(v!=-999)printf("%d ",v);
	else printf("\nUnderflow!\n");
	v=dequeue(&q1);
	if(v!=-999)printf("%d ",v);
	else printf("\nUnderflow!\n");
	enqueue(&q1,3);
	enqueue(&q1,4);
	v=dequeue(&q1);
	if(v!=-999)printf("%d ",v);
	else printf("\nUnderflow!\n");
	return 0;
}
