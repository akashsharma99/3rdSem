#include<stdlib.h>
#include<stdio.h>
int queue[5];
int rear,front,curr_size;
void initQueue()
{
	rear=-1;
	front=-1;
	curr_size=0;
}
void enqueue(int v)
{
	if(rear==-1 && front==-1)
	{
		front=0;rear=0;
		queue[rear++]=v;
		//curr_size++;
		return;
	}
	if(rear==front || (rear==5 && front==0))
	{
		printf("Overflow!\n");
		return;
	}
	if(rear==5)
	{
		rear=0;
	}
	queue[rear++]=v;
	//curr_size++;
	return;
}
int dequeue()
{
	if(front==-1)
	{
		return -999;
	}
	int v=queue[front++];
	if(front==rear)
	{
		front=-1;rear=-1;
	}
	if(front==5)
	front=0;
	return v;
}
void display()
{
	int i;
	if(front==-1)
	{
		printf("Empty queue!\n");
		return;
	}
	if(front<rear){
		for(i=front;i<rear;i++)
		{
			printf("%d\n",queue[i]);
		}
	}
	else
	{
		for(i=front;i<=4;i++)
			printf("%d\n",queue[i]);
		for(i=0;i<rear;i++)
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
