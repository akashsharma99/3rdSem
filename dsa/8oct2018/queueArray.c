#include<stdlib.h>
#include<stdio.h>
int queue[5];
int rear,front;
void initQueue()
{
	rear=-1;
	front=-1;
}
void enqueue(int v)
{
	if(rear==-1 && front==-1)
	{
		front=0;
		queue[++rear]=v;
		return;
	}
	if(rear==4)
	{
		printf("Overflow!\n");
		return;
	}
	queue[++rear]=v;
	return;
}
int dequeue()
{
	if(front>rear || front==-1)
	{
		front=-1;
		rear=-1;
		return -999;
	}
	int v=queue[front];
	front++;
	return v;
}
void display()
{
	int i;
	if(front>rear)
	{
		printf("Empty queue!\n");
		return;
	}
	for(i=front;i<=rear;i++)
	{
		printf("%d\n",queue[i]);
	}
	return;
}
int main()
{
initQueue();
	int v=1,ch;
	while(v==1)
	{		
		printf("1.insert__2.delete__3.display__4.exit\n");
		printf("Choose: ");
		scanf("%d",&ch);
		if(ch==1){
			printf("Enter a value: ");
			int val;
			scanf("%d",&val);
			enqueue(val);
		}
		else if(ch==2){
			int val=dequeue();
			if(val==-999)
				printf("Underflow!\n");
			else
				printf("Deleted: %d\n",val);
		}
		else if(ch==3){
			printf("The queue is:\n");display();
		}
		else
			break;
	}
}
