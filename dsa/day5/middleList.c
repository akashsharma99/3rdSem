#include<stdio.h>
#include<stdlib.h>
struct node
{
      int data;
      struct node* next;
};
void create(struct node** head,int n)
{
      struct node* temp=(struct node*)malloc(sizeof(struct node));
      struct node* p=*head;
      temp->data=n;
      temp->next=NULL;
      if(*head==NULL)
      {
            *head=temp;
            return;
      }
      while(p->next!=NULL)
      {
            p=p->next;
      }
      p->next=temp;
      return;
}
int getMiddle(struct node** head)
{
      struct node* p=*head,*q=p;
      if(p==NULL)
      {
            printf("List empty!\n");
            return -999;
      }
      if(q->next==NULL)
      return q->data;

      while(q!=NULL && q->next!=NULL)
      {
            q=q->next->next;
            p=p->next;
      }
      return p->data;
}
int main()
{
      struct node* head=NULL;
      int n;
      printf("Create a link list.\nEnter -1 to stop\n");
      scanf("%d",&n);
      while(n!=-1)
      {
            create(&head,n);
            scanf("%d",&n);
      }
      n=getMiddle(&head);
      if(n!=-999)
      printf("The middle element is: %d\n",n);
      return 0;
}
