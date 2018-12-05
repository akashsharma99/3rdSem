#include<stdlib.h>
#include<stdio.h>
struct node
{
      int data;
      struct node* link;
}*start=NULL;
void create(int num)
{
      struct node* temp=(struct node*)malloc(sizeof(struct node));
      struct node* q;
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
void reverse()
{
      int n;
      struct node *p1,*p2,*p3,*x,*p=start;
      printf("Enter size of sub lists: ");
      scanf("%d",&n);
      if(start==NULL || start->link==NULL || n==1)
      return;
      p1=start;
      p2=start->link;
      p3=p2->link;
      while(p3!=NULL)
      {
            int c=1;
            if(p!=start)
            {
                  p1=p2;p2=p2->link;p3=p3->link;
            }

            while(c<n)
            {
                        x=p1->link;
                  if(p2==NULL)break;
                        p2->link=p1;
                        p1=p2;
                        p2=p3;
                        if(p3!=NULL)
                        p3=p3->link;
                  c++;
            }
            if(p==start)
            {
                  start=p1;
                  p->link=p2;
            }
            else
            {
                  p->link->link=p2;
                  struct node* tick=p->link;
                  p->link=p1;
                  p=tick;
            }

      }


}
void display()
{
      struct node* t=start;
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
      reverse();
      display();
      return 0;
}
