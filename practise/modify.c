#include<stdlib.h>
#include<stdio.h>
struct node
{
      int data;
      struct node* link;
}*start=NULL;
typedef struct node NODE;
void create(int num)
{
      NODE* temp=(NODE*)malloc(sizeof(NODE));
      NODE* q;
      temp->data=num;
      temp->link=NULL;
      if(start==NULL)
            start=temp;
      else
      {
            q=start;
            while(q->link!=NULL)
                  q=q->link;
            q->link=temp;
      }
}
void modify()
{
      NODE* p=start,*q;
      if(start==NULL || start->link==NULL || start->link->link==NULL)
      return;
      while(p->link!=NULL && p->link->link!=NULL)
      {
            q=p;
            while(q->link->link!=NULL)
            {
                  q=q->link;
            }
            q->link->link=p->link;
            p->link=q->link;
            p=q->link;
            q->link=NULL;
            p=p->link;
      }
}
void display()
{
      NODE* t=start;
      while(t!=NULL)
      {
            printf("%d,",t->data);
            t=t->link;
      }
}
int main()
{
      int n,i,num;
      printf("Enter size of list: ");
      scanf("%d",&n);
      printf("Enter the numbers: \n");
      for(i=0;i<n;i++){
            scanf("%d",&num);
            create(num);
      }
      modify();
      display();
      return 0;
}
