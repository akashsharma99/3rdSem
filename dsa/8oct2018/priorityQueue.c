#include<stdio.h>
#include<stdlib.h>
struct queue{
      struct node *front,*rear;
};
struct node{
      int val,prior;
      struct node *next;
};
void initQueue(struct queue** q)
{
      (*q)->front=NULL;
      (*q)->rear=NULL;
      return;
}
void display(struct queue** q)
{
      if((*q)->front==NULL)
      {
            printf("Empty queue\n");
            return;
      }
      struct node *p=(*q)->front;
      while(p!=NULL)
      {
            //printf("HI!");
            printf("%d\n",p->val);
            p=p->next;
      }
      return;
}
void enqueue(struct queue** q,int val,int p)
{
      struct node* temp=(struct node*)malloc(sizeof(struct node*));
      temp->val=val;
      temp->prior=p;
      temp->next=NULL;
      if((*q)->front==NULL && (*q)->rear==NULL)
      {
            (*q)->front=temp;
            (*q)->rear=temp;
            return;
      }
      struct node* n=(*q)->front,*prev=(*q)->front;
      //printf("%d ..%d\n",prev->val,n->val);
      while(n!=NULL)
      {
            if((n->prior)<p)
            {
                  printf("Helpoooo!\n");
                  printf("%d..%d\n",prev->val,n->val);
                  if(n==prev->next){
                        temp->next=n;
                        prev->next=temp;
                        //(*q)->front=temp;
                        printf("Pehla\n");
                        display(q);
                  }
                  else if(n->next==NULL){
                        temp->next=n;
                        if(prev->next==NULL){
                              (*q)->front=temp;
                        }
                        else{
                              prev->next=temp;
                        }
                        //return;
                        printf("DOOSra\n");
                        display(q);
                  }
                  if(temp->next==NULL)
                        (*q)->rear=temp;
                  return;
            }
            prev=n;
            n=n->next;
      }
      (*q)->rear->next=temp;
      (*q)->rear=temp;
      return;
}
int dequeue(struct queue** q)
{
      if((*q)->front==NULL)
            return -999;
      int v=(*q)->front->val;
      (*q)->front=(*q)->front->next;
      if((*q)->front==NULL)
            (*q)->rear=NULL;
      return v;
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
			int val,p;
			scanf("%d",&val);
                  printf("Enter priority: ");
                  scanf("%d",&p);
			enqueue(&q1,val,p);
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
