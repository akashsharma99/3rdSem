2.Split a linked list in half

#include<stdio.h>
#include<stdlib.h>
struct node{
      int data;
      struct node *next;
};
struct node* getMiddle(struct node** s)
{
      if(*s==NULL)
      {
            return NULL;
      }
      if((*s)->next==NULL)
      {
            printf("Only single element in list...\n");
            return NULL;
      }
      struct node* slow_ptr=*s;
      struct node* fast_ptr=*s;
      struct node* p=*s;
      while(fast_ptr!=NULL && fast_ptr->next!=NULL)
      {
            p=slow_ptr;
            slow_ptr=slow_ptr->next;
            fast_ptr=fast_ptr->next->next;
      }
      fast_ptr=p->next;
      p->next=NULL;
      return fast_ptr;
}
void create(struct node** s)
{
      int v,i;
      struct node* temp, *last;
      printf("Enter -1 to exit creation of link list: ");
      scanf("%d",&v);
      while(v!=-1)
      {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->data=v;
            temp->next=NULL;
            if(*s==NULL)
            {
                  (*s)=temp;
                  last=temp;
            }
            else
            {
                  last->next=temp;
                  last=temp;
            }
            scanf("%d",&v);
      }
      return;
}
void display(struct node** s)
{
      struct node *st=*s;
      if(st==NULL)
      {
            printf("Empty!\n");
            return;
      }
      while(st!=NULL)
      {
            printf("%d\n",st->data);
            st=st->next;
      }
      return;
}
int main()
{
      struct node* start1=NULL,*start2=NULL;
      printf("Lets create the list first!\n");
      create(&start1);
      printf("The list is: \n");
      display(&start1);
      start2=getMiddle(&start1);
      printf("First half:\n");
      display(&start1);
      printf("Second half:\n");
      display(&start2);
      return 0;
}
