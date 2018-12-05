1.Find the middle element of a linked list.

#include<stdio.h>
#include<stdlib.h>
struct node
{
      struct node* next;
      int data;
};
int getMiddle(struct node** s)
{
      if(*s==NULL)
      {
            printf("List is Empty!\n");
            return -999;
      }
      if((*s)->next==NULL)
      {
            printf("Only single element in list...\n");
            return (*s)->data;
      }
      struct node* slow_ptr=*s;
      struct node* fast_ptr=*s;
      do
      {
            slow_ptr=slow_ptr->next;
            fast_ptr=fast_ptr->next->next;
            if(fast_ptr==NULL || fast_ptr->next==NULL)
            break;

      }while(1);
      return slow_ptr->data;
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
      while(st!=NULL)
      {
            printf("%d\n",st->data);
            st=st->next;
      }
      return;
}
int main()
{
      struct node* start=NULL;
      printf("Lets create the list first!\n");
      create(&start);
      printf("The list is: \n");
      display(&start);
      int middle=getMiddle(&start);
      if(middle!=-999)
            printf("Middle : %d\n",middle);
      return 0;
}
