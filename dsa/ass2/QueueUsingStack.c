6.Implement queue adt using stack

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};
struct queue
{
      struct node* st1,*st2;
};
void initQueue(struct queue** q)
{
      (*q)->st1=NULL;
      (*q)->st2=NULL;
}
void enqueue(struct queue** q,int n)
{
      struct node* temp=(struct node*)malloc(sizeof(struct node));
      temp->data=n;
      temp->next=(*q)->st1;
      (*q)->st1=temp;
      return;
}
int dequeue(struct queue** q)
{
      struct node* s1=(*q)->st1;
      struct node* s2=(*q)->st2;
      if((*q)->st2==NULL)
      {
            if((*q)->st1==NULL)
            {
                  printf("Empty Queue\n");
                  return -999;
            }
            while((*q)->st1!=NULL)
            {
                  struct node* t=(*q)->st1->next;
                  (*q)->st1->next=(*q)->st2;
                  (*q)->st2=(*q)->st1;
                  (*q)->st1=t;
            }
      }
      int v=(*q)->st2->data;
      (*q)->st2=(*q)->st2->next;
      return v;
}
int main()
{
	struct queue* q=(struct queue*)malloc(sizeof(struct queue));
	initQueue(&q);
	while(1)
	{
		printf("1.Enqueue\n2.Dequeue\n3.exit\nchoose: ");
		int op;
		scanf("%d",&op);
		if(op==3)
		break;
		else if(op==1)
		{
			int val;
			printf("Enter value: ");
			scanf("%d",&val);
			enqueue(&q,val);
		}
		else if(op==2)
		{
			int val=dequeue(&q);
			if(val!=-999)
				printf("Popped out: %d\n",val);
		}
		else
		printf("Wrong choice! try again.\n");
	}
	return 0;
}
